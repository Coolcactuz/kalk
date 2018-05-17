#include "view_manager.h"

view_manager::view_manager(QObject* parent): QObject(parent), startup(0) /*,
specialized(0)*/ {
      start();
}


view_manager::~view_manager(){
  delete startup;
  //delete specialized;
}


void view_manager::start() {

  //elimina le eventuali viste esistenti
  if(startup)
    delete startup;

  /*
  if(specialized){
    delete specialized;
    specialized = 0;
  }*/

  startup = new startup_view();
  startup->show();
}

/*
void view_manager::newSpecialized(int type) {

  switch (type) {
    case 0:
      specialized = new vRaz(this);
    break;
    case 1:
      specialized = new vC_polari(this);
    break;
    case 2:
      specialized = new vC_cartesiani(this);
    break;
    case 3:
      specialized = new vComponente(this);
    break;
    case 4:
      specialized = new vNota(this);
    break;
  }

  specialized->show();

}

*/
