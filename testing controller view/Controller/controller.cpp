#include "controller.h"

controller::~controller(){
    delete startup;
    delete specialized;
}

void controller::start(){

  if(specialized){
    delete specialized;
    specialized = 0;
  }

  if(startup)
    delete startup;

  startup = new startup_view();
  startup->show();
}


controller::controller(): datatype(-1), startup(0), specialized(0){
  start();

  QObject::connect(startup, SIGNAL(exchange_datatype(int)), this, SLOT(setData(int)));
}


void controller::setData(int n){

  datatype = n;

  switch (datatype) {
    case 4:
      specialized = new VCircuit();
    break;
  }

  startup->close();
  specialized->show();
}
