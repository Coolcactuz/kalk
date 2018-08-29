#include "VRazionale.h"

VRazionale::VRazionale(): razionaleOp(new QGridLayout()){

  type_title->setText("RAZIONALE");

  lower->addLayout(razionaleOp);

  razionaleOp->addWidget(new KalkButton(10, "+", this), 0, 0);
  razionaleOp->addWidget(new KalkButton(11, "*", this), 0, 1);
  razionaleOp->addWidget(new KalkButton(12, "-", this), 1, 0);
  razionaleOp->addWidget(new KalkButton(13, "/", this), 1, 1);
  razionaleOp->addWidget(new KalkButton(14, "^", this), 2, 0);
  razionaleOp->addWidget(new KalkButton(15, "sqrt", this), 2, 1);
  razionaleOp->addWidget(new KalkButton(16, "1/x", this), 2, 1);
  razionaleOp->addWidget(new KalkButton(17, "<->", this), 2, 1);
}
