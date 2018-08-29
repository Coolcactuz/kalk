#include "VComplesso.h"

VComplesso::VComplesso(): complessoOp(new QGridLayout()){

  type_title->setText("COMPLESSO");

  lower->addLayout(complessoOp);

  complessoOp->addWidget(new KalkButton(10, "+", this), 0, 0);
  complessoOp->addWidget(new KalkButton(11, "*", this), 0, 1);
  complessoOp->addWidget(new KalkButton(12, "-", this), 1, 0);
  complessoOp->addWidget(new KalkButton(13, "/", this), 1, 1);
  complessoOp->addWidget(new KalkButton(14, "<->", this), 2, 0);
  complessoOp->addWidget(new KalkButton(15, "¬", this), 2, 1);
}
