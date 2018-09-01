#include "controller.h"

controller::controller(): cv(new controller_view()), tipo_corrente(0), oggetto_corrente(0), from_gui(""){
  QObject::connect(cv, SIGNAL(inviaTipo(int)), this, SLOT(defineTC(int)));
  QObject::connect(cv, SIGNAL(inviaStringa(QString)), this, SLOT(data_GUI_to_controller(QString)));

  //inizia_sessione();
}

controller::~controller(){
  if(cv){
    delete cv;
  }
}

void controller::defineTC(int tc){
  tipo_corrente = tc;
}

void controller::data_GUI_to_controller(QString s){
  from_gui = s;

  switch (tipo_corrente){

    case 1:

      parser<Raz> pr(from_gui.toUtf8().constData());

      oggetto_corrente = parser::

    break;

  }
}

// void controller::inizia_sessione(){

// }
