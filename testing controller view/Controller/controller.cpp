#include "controller.h"

controller::controller(): datatype(-1), vm(new view_manager()){
  QObject::connect(vm, SIGNAL(datatype_vm(int)), this, SLOT(setData(int)));
}

void controller::setData(int info){
  // std::cout <<"parametro ricevuto: " << info<< std::endl;
  datatype = info;
  std::cout <<"valore del campo datatype : " << datatype<< std::endl;
}

controller::~controller(){
  delete vm;
}
