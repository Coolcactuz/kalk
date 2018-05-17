#include "controller.h"

controller::controller(): datatype(-1) {}

void controller::setData(){
  selectTypeButton* button = qobject_cast<selectTypeButton>()
  datatype = data;
}
