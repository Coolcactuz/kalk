#include "VRaz.h"

VRaz::VRaz(){

  std::cout << "costruttore Vraz" << std::endl;

  type_title->setText("RAZIONALI");

  nt_op->addWidget(new KalkButton(-12, "^", this), 0, 1);
  nt_op->addWidget(new KalkButton(-11, "cbrt", this), 1, 1);
  nt_op->addWidget(new KalkButton(-10, "sqrt", this), 2, 1);

  std::cout << "costruttore Vraz - fine" << std::endl;
}


void VRaz::plot(){

}
