#include "controller.h"

controller::~controller(){

  std::cout << "distruttore controller - inizio" << std::endl;

  if(startup){
    std::cout << "controller->delete startup" << std::endl;
    delete startup;
  }

  if(specialized){
    std::cout << "controller->delete specialized" << std::endl;
    delete specialized;
  }

  std::cout << "distruttore controller - fine" << std::endl;

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
