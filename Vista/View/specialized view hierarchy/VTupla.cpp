#include "VTupla.h"

VTupla::VTupla(): tupla_op(new QGridLayout()){

  lower->addLayout(tupla_op);

  tupla_op->addWidget(new KalkButton(8, "+", this), 0, 0);
  tupla_op->addWidget(new KalkButton(9, "-", this), 1, 0);
  tupla_op->addWidget(new KalkButton(10, "/", this), 2, 0);
  tupla_op->addWidget(new KalkButton(11, "%", this), 3, 0);

}

void VTupla::resize_max(){
  
}
