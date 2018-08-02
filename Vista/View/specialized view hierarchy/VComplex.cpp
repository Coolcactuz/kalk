#include "VComplex.h"

VComplex::VComplex(){

  type_title->setText("COMPLESSI");

  nt_op->addWidget(new KalkButton(-11, "<", this), 0, 1);
  nt_op->addWidget(new KalkButton(-10, "i", this), 1, 1);
}


void VComplex::plot(){

}
