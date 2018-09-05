#include "controller.h"

controller::controller(): cv(new controller_view()), tipo_corrente(0), oggetto_corrente(0), from_gui(""),
                          conv_complesso(0), conv_raz(0.0){
  QObject::connect(cv, SIGNAL(inviaTipo(int)), this, SLOT(defineTC(int)));
  QObject::connect(cv, SIGNAL(inviaStringa(QString)), this, SLOT(data_GUI_to_controller(QString)));

  QObject::connect(cv, SIGNAL(SOComplesso(int)), this, SLOT(socomplesso_logic(int)));
  QObject::connect(cv, SIGNAL(SORaz(int)), this, SLOT(soraz_logic(int)));

  QObject::connect(cv, SIGNAL(controller_view_inviaVolt(double)), this, SLOT(circuito_cambia_volt(double)));
  QObject::connect(cv, SIGNAL(controller_view_inviaFreq(double)), this, SLOT(circuito_cambia_freq(double)));

  QObject::connect(this, SIGNAL(data_controller_to_GUI(QString)), cv, SIGNAL(inviaResult(QString))));


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

  if(oggetto_corrente){
    delete oggetto_corrente;
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

  if(oggetto_corrente){
    delete oggetto_corrente;
  }

  if(conv_complesso){
    delete conv_complesso;
  }

}

void controller::defineTC(int tc){
  tipo_corrente = tc;
}

void controller::data_GUI_to_controller(QString s){
  from_gui = s;

  std::cout<<from_gui.toUtf8().constData()<<std::endl;

  Dato* tmp = 0;

  QString qstmp = "";

  try{
    std::string stringa_da_controllare = from_gui.toUtf8().constData();
    check_string(stringa_da_controllare);

    std::cout<<"tipo corrente =" << tipo_corrente<<std::endl;

    switch (tipo_corrente){

      case 1:
      {
        tmp = new Raz(); //oggetto fittizio per il parser

        std::cout<<"parser raz non ancora creato"<<std::endl;

        parser<Raz> pr(from_gui.toUtf8().constData(), tmp);

        std::cout<<"parser raz creato"<<std::endl;

        oggetto_corrente = parser<Raz>::resolve(pr.getStart());

        std::cout << "oggetto_corrente creato" << '\n';

        std::cout << oggetto_corrente->toString()<<std::endl;

        //conv_raz = (static_cast<Raz*>(oggetto_corrente))->double();
        conv_raz = double(*(static_cast<Raz*>(oggetto_corrente)));

        std::cout << "conversione raz creato" << '\n';

        qstmp = (oggetto_corrente->toString()).c_str();

      }
      break;

      case 2:
      {
        tmp = new C_cartesiano();  //oggetto fittizio per il parser
         std::cout<<"parser complesso non ancora creato"<<std::endl;
        parser<Complesso> pcomplesso(from_gui.toUtf8().constData(), tmp);
         std::cout<<"parser complesso creato"<<std::endl;
        oggetto_corrente = pcomplesso.resolve(pcomplesso.getStart());
        conv_complesso = (static_cast<Complesso*> (oggetto_corrente))->converti();
      }
      break;

      case 3:
      {
        tmp = new tupla(); //oggetto fittizio per il parser
        parser<tupla> pt(from_gui.toUtf8().constData(), tmp);
        //oggetto_corrente = pt.resolve(pt.getStart());
      }
      break;

      default:
      {
        tmp = new Condensatore(); //oggetto fittizio per il parser
        parser<Componente> pcomponente(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pcomponente.resolve(pcomponente.getStart());
      }
      break;
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

  std::cout<<"qui"<<std::endl;


  //emit CtV_exception(QString("prova"), true);

  emit data_controller_to_GUI(qstmp);
}

void controller::soraz_logic(int i){

  Raz* aux = dynamic_cast<Raz*>(oggetto_corrente);

  if(!aux){
    //gestire eccezione
  }

  switch (i){

    case -6:
      emit data_controller_to_GUI(QString((std::to_string(aux->radice_quadrata())).c_str()));
    break;

    case -7:
      {
        Raz* tmp = aux->reciproco();
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
