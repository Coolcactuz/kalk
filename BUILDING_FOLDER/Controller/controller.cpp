#include "controller.h"

controller::controller(): cv(new controller_view()), tipo_corrente(0), from_gui(""), conv_complesso(0), conv_raz(0.0){
  QObject::connect(cv, SIGNAL(inviaTipo(int)), this, SLOT(defineTC(int)));
  QObject::connect(cv, SIGNAL(inviaStringa(QString)), this, SLOT(data_GUI_to_controller(QString)));

  QObject::connect(cv, SIGNAL(SOComplesso(int)), this, SLOT(socomplesso_logic(int)));
  QObject::connect(cv, SIGNAL(SORaz(int)), this, SLOT(soraz_logic(int)));

  QObject::connect(cv, SIGNAL(controller_view_inviaVolt(double)), this, SLOT(circuito_cambia_volt(double)));
  QObject::connect(cv, SIGNAL(controller_view_inviaFreq(double)), this, SLOT(circuito_cambia_freq(double)));

  QObject::connect(this, SIGNAL(data_controller_to_GUI(QString)), cv, SIGNAL(inviaResult(QString)));


  QObject::connect(this, SIGNAL(CtV_exception(QString, bool)), cv, SIGNAL(pass_exception(QString, bool)));

  QObject::connect(cv, SIGNAL(emergenza3()), this, SLOT(gestisci_emergenza()));
}

void controller::check_string(std::string s) const{
  std::size_t found = s.find_first_not_of(".+*%/-^(),<abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890");
  if(found != std::string::npos){
    throw syntax_exception("La stringa contiene caratteri speciali");
  }
}

void controller::gestisci_emergenza(){
  if(cv){
    delete cv;
  }

  if(conv_complesso){
    delete conv_complesso;
  }

  std::exit(1);
}

controller::~controller(){

  if(cv){
    delete cv;
  }

  if(conv_complesso){
    delete conv_complesso;
  }

}

void controller::defineTC(int tc){
  tipo_corrente = tc;
}

void controller::data_GUI_to_controller(QString s){
  from_gui = s; //stringa ricevuta in input
  Dato* tmp = 0;    //puntatore a oggetto fittizio per il parser
  QString qstmp = "";   //QString per lo slot mostra_result

  try{
    //controlla che la stringa non abbia caratteri speciali al suo interno
    std::string stringa_da_controllare = from_gui.toUtf8().constData();
    check_string(stringa_da_controllare);

    switch(i){
       case 1:
        {
        tmp = new Raz();    //inizializzazione oggetto fittizio per il parser
        Dato* result = 0;   //puntatore all'oggetto risultato
        parser<Raz> pr(from_gui.toUtf8().constData(), tmp);    //creazione oggetto parser
        result = parser<Raz>::resolve(pr.getStart());   //calcolo e assegnazione del risultato
        conv_raz = double(*(static_cast<Raz*>(result)));
        qstmp = (result->toString()).c_str();
        delete result;
        }
       break;
       case 2:
        {
        tmp = new C_cartesiano();
        Dato* result = 0;
        parser<Complesso> pcomplesso(from_gui.toUtf8().constData(), tmp);
        result = parser<Complesso>::resolve(pcomplesso.getStart());
        conv_complesso = (static_cast<Complesso*> (result))->converti();
        qstmp = (result->toString()).c_str();
        delete result;
        }
        break;
        case 3:
        {
        tmp = new tupla();
        Dato* result = 0;
        parser<tupla> pt(from_gui.toUtf8().constData(), tmp);
        result = parser<tupla>::resolve(pt.getStart());
        qstmp = (result->toString()).c_str();
        delete result;
        }
        break;
        default:
        {
        tmp = new Condensatore();
        Dato* result = 0;
        parser<Componente> pcomponente(from_gui.toUtf8().constData(), tmp);
        result = parser<Componente>::resolve(pcomponente.getStart());
        qstmp = (result->toString()).c_str();
        delete result;
        }
     }
  }
  catch(const syntax_exception & se){
    if(tmp)
      delete tmp;
    emit CtV_exception(QString((se.getErrorMessage()).c_str()), true);
  }
  catch(const logic_exception & le){
    if(tmp)
      delete tmp;
    emit CtV_exception(QString((le.getErrorMessage()).c_str()), false);
  }

  delete tmp;

  emit data_controller_to_GUI(qstmp);
}

void controller::soraz_logic(int i){

    Dato* fittizio = new Raz();
    parser<Raz> pr(from_gui.toUtf8().constData(), fittizio);
    delete fittizio;
    Dato* result = parser<Raz>::resolve(pr.getStart());

    Raz aux = *(static_cast<Raz*>(result));
    delete result;


    try{
        switch (i){

        case -6:
          emit data_controller_to_GUI(QString((std::to_string(aux.radice_quadrata())).c_str()));
        break;

        case -7:
          {
            Raz* tmp = aux.reciproco();
            Raz raz_obj = *tmp;
            delete tmp;
            emit data_controller_to_GUI(QString((raz_obj.toString()).c_str()));
          }
        break;

        default:
          emit data_controller_to_GUI(QString((std::to_string(conv_raz)).c_str()));
        break;
       }
    }

    catch(const syntax_exception & se){
      emit CtV_exception(QString((se.getErrorMessage()).c_str()), true);
    }
    catch(const logic_exception & le){
      emit CtV_exception(QString((le.getErrorMessage()).c_str()), false);
    }
}

void controller::socomplesso_logic(int i){

  Complesso* aux = dynamic_cast<Complesso*>(oggetto_corrente);

  if(!aux){
    //gestire eccezione
  }

  switch (i){

    case -4:
    {
      if(conv_complesso){
        emit data_controller_to_GUI(QString((conv_complesso->toString()).c_str()));
      }
      else{
        //eccezione sintassi premuto converti senza avere creato oggetto
      }
    }
    break;

    default:
    {
      Complesso* result_coniugato = aux->coniugato();
      QString stringa_coniugato = (result_coniugato->toString()).c_str();
      delete result_coniugato;
      emit data_controller_to_GUI(stringa_coniugato);
    }
    break;
  }
}

void controller::circuito_cambia_volt(double d){
  Componente::setVolt(d);

  //per vedere se fa robe
  emit data_controller_to_GUI(QString((std::to_string(Componente::getVolt())).c_str()));
}

void controller::circuito_cambia_freq(double d){
  Componente::setFreq(d);

  //per vedere se fa robe
  emit data_controller_to_GUI(QString((std::to_string(Componente::getFreq())).c_str()));
}
