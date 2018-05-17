#include "controller.h"

controller::controller(): datatype(-1), vm(new view_manager()){
  QObject::connect(vm, SIGNAL(datatype_vm(int)), this, SLOT(setData(int)));
}

void controller::setData(int info){
  // selectTypeButton* button = qobject_cast<selectTypeButton*>(sender());
  //
  // if(button)
  //   datatype = button->getDataNumber();
  // else
  //   std::cout <<"button è nullo"<< std::endl;

  std::cout <<info<< std::endl;
}
