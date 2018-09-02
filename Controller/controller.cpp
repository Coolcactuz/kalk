#include "controller.h"

controller::controller(): cv(new controller_view()), tipo_corrente(0), oggetto_corrente(0), from_gui(""){
  QObject::connect(cv, SIGNAL(inviaTipo(int)), this, SLOT(defineTC(int)));
  QObject::connect(cv, SIGNAL(inviaStringa(QString)), this, SLOT(data_GUI_to_controller(QString)));

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

  switch (tipo_corrente){

    //vedere sintassi funzione resolve

    case 1:
      parser<Raz> pr(from_gui.toUtf8().constData());
      oggetto_corrente = pr.resolve();
    break;

    case 2:
      parser<Complesso> pcomplesso(from_gui.toUtf8().constData());
      oggetto_corrente = pcomplesso.resolve();
    break;

    case 3:
      parser<tupla> pt(from_gui.toUtf8().constData());
      oggetto_corrente = pt.resolve();
    break;

    default:
      parser<Componente> pcomponente(from_gui.toUtf8().constData());
      oggetto_corrente = pcomponente.resolve();
    break;

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

}
// void controller::inizia_sessione(){

// }
