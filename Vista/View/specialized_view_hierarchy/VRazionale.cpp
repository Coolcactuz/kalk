#include "VRazionale.h"

VRazionale::VRazionale(): razionaleKeyboard(new QGridLayout()), razionaleOp(new QGridLayout()){

  type_title->setText("RAZIONALE");

  lower->addLayout(razionaleKeyboard);
  lower->addLayout(razionaleOp);

  razionaleKeyboard->addWidget(new KalkButton(0, "0", this), 3, 1);
  razionaleKeyboard->addWidget(new KalkButton(1, "1", this), 2, 0);
  razionaleKeyboard->addWidget(new KalkButton(2, "2", this), 2, 1);
  razionaleKeyboard->addWidget(new KalkButton(3, "3", this), 2, 2);
  razionaleKeyboard->addWidget(new KalkButton(4, "4", this), 1, 0);
  razionaleKeyboard->addWidget(new KalkButton(5, "5", this), 1, 1);
  razionaleKeyboard->addWidget(new KalkButton(6, "6", this), 1, 2);
  razionaleKeyboard->addWidget(new KalkButton(7, "7", this), 0, 0);
  razionaleKeyboard->addWidget(new KalkButton(8, "8", this), 0, 1);
  razionaleKeyboard->addWidget(new KalkButton(9, "9", this), 0, 2);

  razionaleOp->addWidget(new KalkButton(10, "+", this), 0, 0);
  razionaleOp->addWidget(new KalkButton(11, "*", this), 0, 1);
  razionaleOp->addWidget(new KalkButton(12, "-", this), 1, 0);
  razionaleOp->addWidget(new KalkButton(13, "/", this), 1, 1);
  razionaleOp->addWidget(new KalkButton(14, "^", this), 2, 0);
  razionaleOp->addWidget(new KalkButton(15, "sqrt", this), 2, 1);
  razionaleOp->addWidget(new KalkButton(15, "1/x", this), 2, 1);
  razionaleOp->addWidget(new KalkButton(15, "<->", this), 2, 1);

}
