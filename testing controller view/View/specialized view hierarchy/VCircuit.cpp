#include "VCircuit.h"

VCircuit::VCircuit(): c_op(new QVBoxLayout()){

  type_title->setText("COMPONENTE");

  lower->addLayout(c_op);

  c_op->addWidget(new KalkButton(-7, "PLOT", this));
  c_op->addWidget(new KalkButton(-6, "+", this));
  c_op->addWidget(new KalkButton(-5, "/", this));
  c_op->addWidget(new QSlider(Qt::Horizontal, this));
  c_op->addWidget(new QSlider(Qt::Horizontal, this));

}


void VCircuit::plot(){

}
