#include "controller.h"

controller::~controller(){

  std::cout << "distruttore controller" << std::endl;

  if(startup){
    std::cout << "distruttore controller - startup" << std::endl;
    delete startup;
  }

  if(specialized){
    std::cout << "distruttore controller- specialized" << std::endl;
    delete specialized;
  }

  std::cout << "distruttore controller - fine" << std::endl;
}




controller::controller(): datatype(-1), startup(new startup_view()),
specialized(0){
  //start();

  startup->show();

  QObject::connect(startup, SIGNAL(exchange_datatype(int)), this, SLOT(setData(int)));
}


void controller::setData(int n){

  datatype = n;

  std::cout << n << std::endl;

  switch (datatype) {
    case 0:
      specialized = new VRaz();
    break;
    case 1:
      specialized = new VComplex();
    break;
    case 3:
      specialized = new VNota();
    break;
    case 4:
      specialized = new VCircuit();
    break;
  }

  std::cout << "setData 1" << std::endl;

  QObject::connect(specialized, SIGNAL(goBack_CStart()), this, SLOT(CStart()));

  std::cout << "setData 2" << std::endl;


  startup->close();

  std::cout << "setData 3" << std::endl;


  delete startup;

  std::cout << "setData 4" << std::endl;


  startup = 0;

  std::cout << "setData 5" << std::endl;


  specialized->show();

  std::cout << "setData fine" << std::endl;


}

void controller::CStart(){

  std::cout << "ciao" << std::endl;

  specialized->close();
  delete specialized;
  specialized = 0;

  startup = new startup_view();

  startup->show();

  QObject::connect(startup, SIGNAL(exchange_datatype(int)), this, SLOT(setData(int)));
}
