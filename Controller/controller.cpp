#include "controller.h"

controller::controller(): cv(new controller_view()), tipo_corrente(0), oggetto_corrente(0), from_gui(""){
  QObject::connect(cv, SIGNAL(inviaTipo(int)), this, SLOT(defineTC(int)));
  QObject::connect(cv, SIGNAL(inviaStringa(QString)), this, SLOT(data_GUI_to_controller(QString)));

  QObject::connect(cv, SIGNAL(SOComplesso(int)), this, SLOT(socomplesso_logic(int)));
  QObject::connect(cv, SIGNAL(SORaz(int)), this, SLOT(soraz_logic(int)));

  QObject::connect(cv, SIGNAL(controller_view_inviaVolt(double)), this, SLOT(circuito_cambia_volt(double)));
  QObject::connect(cv, SIGNAL(controller_view_inviaFreq(double)), this, SLOT(circuito_cambia_freq(double)));


  QObject::connect(this, SIGNAL(data_controller_to_GUI(QString)), cv, SIGNAL(inviaResult(QString)));
  //inizia_sessione();
}

controller::~controller(){

  if(cv){
    delete cv;
  }

  if(oggetto_corrente){
    delete oggetto_corrente;
  }

}

void controller::defineTC(int tc){
  tipo_corrente = tc;
}

void controller::data_GUI_to_controller(QString s){
  from_gui = s;

  try{
    switch (tipo_corrente){

      case 1:
      {
        Raz* tmp = new Raz();
        parser<Raz> pr(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pr.resolve();
        delete tmp;
      }
      break;

      case 2:
      {
        Complesso* tmp = new C_cartesiano();
        parser<Complesso> pcomplesso(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pcomplesso.resolve();
        delete tmp;
      }
      break;

      case 3:
      {
        tupla* tmp = new tupla();
        parser<tupla> pt(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pt.resolve();
        delete tmp;
      }
      break;

      default:
      {
        Componente* tmp = new Condensatore();
        parser<Componente> pcomponente(from_gui.toUtf8().constData(), tmp);
        oggetto_corrente = pcomponente.resolve();
        delete tmp;
      }
      break;
    }
  }
  catch(syntax_exception se){
    //visualizza errore sintassi
  }
  catch(logic_exception le){
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
      emit data_controller_to_GUI(QString((double) (*aux)));
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
      Complesso* result_conversione = aux->converti();
      QString result_stringa = result_conversione->toString();
      delete result_conversione;
      emit data_controller_to_GUI(result_stringa);
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
