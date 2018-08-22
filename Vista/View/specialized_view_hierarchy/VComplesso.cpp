#include "VComplesso.h"

VComplesso::VComplesso(): complessoKeyboard(new QGridLayout()), complessoOp(new QGridLayout()){

  type_title->setText("COMPLESSO");

  lower->addLayout(complessoKeyboard);
  lower->addLayout(complessoOp);

  complessoKeyboard->addWidget(new KalkButton(0, "0", this), 3, 1);
  complessoKeyboard->addWidget(new KalkButton(1, "1", this), 2, 0);
  complessoKeyboard->addWidget(new KalkButton(2, "2", this), 2, 1);
  complessoKeyboard->addWidget(new KalkButton(3, "3", this), 2, 2);
  complessoKeyboard->addWidget(new KalkButton(4, "4", this), 1, 0);
  complessoKeyboard->addWidget(new KalkButton(5, "5", this), 1, 1);
  complessoKeyboard->addWidget(new KalkButton(6, "6", this), 1, 2);
  complessoKeyboard->addWidget(new KalkButton(7, "7", this), 0, 0);
  complessoKeyboard->addWidget(new KalkButton(8, "8", this), 0, 1);
  complessoKeyboard->addWidget(new KalkButton(9, "9", this), 0, 2);

  complessoOp->addWidget(new KalkButton(10, "+", this), 0, 0);
  complessoOp->addWidget(new KalkButton(11, "*", this), 0, 1);
  complessoOp->addWidget(new KalkButton(12, "-", this), 1, 0);
  complessoOp->addWidget(new KalkButton(13, "/", this), 1, 1);
  complessoOp->addWidget(new KalkButton(14, "<->", this), 2, 0);
  complessoOp->addWidget(new KalkButton(15, "¬", this), 2, 1);

}
