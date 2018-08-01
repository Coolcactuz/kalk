#include "VCircuit.h"

VCircuit::VCircuit(): c_op(new QVBoxLayout()){

  type_title->setText("COMPONENTE");

  lower->addLayout(c_op);

  c_op->addWidget(new KalkButton(-6, "+", this));
  c_op->addWidget(new KalkButton(-5, "/", this));
  c_op->addWidget(new QSpinBox(this));
  c_op->addWidget(new QSpinBox(this));

}


void VCircuit::plot(){

}
