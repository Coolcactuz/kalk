#include "VNumTypes.h"

VNumTypes::VNumTypes(): nt_op(new QGridLayout()){

  lower->addLayout(nt_op);

  nt_op->addWidget(new KalkButton(-9, "-"), 0, 0);
  nt_op->addWidget(new KalkButton(-8, "+"), 1, 0);
  nt_op->addWidget(new KalkButton(-7, "*"), 2, 0);
  nt_op->addWidget(new KalkButton(-6, "/"), 3, 0);
  nt_op->addWidget(new KalkButton(-5, "CONVERTI"), 4, 0);

}


void VNumTypes::plot(){

}
