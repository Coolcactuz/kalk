#include "controller.h"

controller::controller(): cv(new controller_view()), tipo_corrente(0), oggetto_corrente(0), from_gui(""),
                          conv_complesso(0), conv_raz(0.0){
  QObject::connect(cv, SIGNAL(inviaTipo(int)), this, SLOT(defineTC(int)));
  QObject::connect(cv, SIGNAL(inviaStringa(QString)), this, SLOT(data_GUI_to_controller(QString)));

  QObject::connect(cv, SIGNAL(SOComplesso(int)), this, SLOT(socomplesso_logic(int)));
  QObject::connect(cv, SIGNAL(SORaz(int)), this, SLOT(soraz_logic(int)));

  QObject::connect(cv, SIGNAL(controller_view_inviaVolt(double)), this, SLOT(circuito_cambia_volt(double)));
  QObject::connect(cv, SIGNAL(controller_view_inviaFreq(double)), this, SLOT(circuito_cambia_freq(double)));


  QObject::connect(this, SIGNAL(data_controller_to_GUI(QString)), cv, SIGNAL(inviaResult(QString)));
  //inizia_sessione();
}

void controller::check_string(std::string s){
  std::size_t found = ().find_first_not_of("+*%/-^(),<abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890");
  if(found != std::string::npos){
    throw syntax_exception("La stringa contiene caratteri speciali");
  }
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

  try{

    std::string stringa_da_controllare = from_gui.toUtf8().constData();

    check_string(stringa_da_controllare);

    Dato* tmp = 0;

    switch (tipo_corrente){

      case 1:
      {
        tmp = new Raz(); //oggetto fittizio per il parser
        parser<Raz> pr(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pr.resolve(pr.getStart());
        conv_raz = (double) (*(static_cast<Raz*> (oggetto_corrente)));

      }
      break;

      case 2:
      {
        tmp = new C_cartesiano();  //oggetto fittizio per il parser
        parser<Complesso> pcomplesso(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pcomplesso.resolve(pcomplesso.getStart());
        conv_complesso = (static_cast<Complesso*> (oggetto_corrente))->converti();

      }
      break;

      case 3:
      {
        tmp = new tupla(); //oggetto fittizio per il parser
        parser<tupla> pt(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pt.resolve(pt.getStart());

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

    delete tmp;
  }
  catch(const syntax_exception & se){
    if(tmp)
      delete tmp;
    //visualizza errore sintassi
  }
  catch(const logic_exception & le){
    if(tmp)
      delete tmp;
    //errore logico
  }


  emit data_controller_to_GUI(QString(oggetto_corrente->toString()));

}

void controller::soraz_logic(int i){

  Raz* aux = dynamic_cast<Raz*>(oggetto_corrente);

  if(!aux){
    //gestire eccezione
  }

  switch (i){

    case -6:
      emit data_controller_to_GUI(QString(aux->radice_quadrata()));
    break;

    case -7:
      {
        Raz* tmp = aux->reciproco();
        Raz raz_obj = *tmp;
        delete tmp;
        emit data_controller_to_GUI(QString(raz_obj.toString()));
      }
    break;

    default:
      emit data_controller_to_GUI(QString(conv_raz));
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
        emit data_controller_to_GUI(QString(conv_complesso->toString()));
      }
      else{
        //eccezione sintassi premuto converti senza avere creato oggetto
      }
    }
    break;

    default:
    {
      Complesso* result_coniugato = aux->coniugato();
      QString stringa_coniugato = result_coniugato->toString();
      delete result_coniugato;
      emit data_controller_to_GUI(stringa_coniugato);
    }
    break;
  }
}

void controller::circuito_cambia_volt(double d){
  Componente::setVolt(d);

  //per vedere se fa robe
  emit data_controller_to_GUI(QString(Componente::getVolt()));
}

void controller::circuito_cambia_freq(double d){
  Componente::setFreq(d);

  //per vedere se fa robe
  emit data_controller_to_GUI(QString(Componente::getFreq()));
}
