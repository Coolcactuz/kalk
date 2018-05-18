#include "view_manager.h"

view_manager::view_manager(): startup(0), specialized(0){
      start();

      QObject::connect(startup, SIGNAL(exchange_datatype(int)), this, SIGNAL(datatype_vm(int)));
}


view_manager::~view_manager(){
  delete startup;
  delete specialized;
}


void view_manager::start() {

  //elimina le eventuali viste esistenti
  if(startup)
    delete startup;

  if(specialized){
    delete specialized;
    specialized = 0;
  }

  startup = new startup_view();
  startup->show();
}


void view_manager::newSpecialized(int type) {

  switch (type) {
    case 0:
      specialized = new vRaz();
    break;
    case 1:
    case 2:
      specialized = new vComplex();
    break;
    case 3:
      specialized = new vSymphony();
    break;
    case 4:
      specialized = new vCircuit();
    break;
  }

  specialized->show();

}
