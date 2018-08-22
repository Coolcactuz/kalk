#include "VCircuito.h"

VCircuito::VCircuito(): circuitoKeyboard(new QGridLayout()), circuitoOp(new QGridLayout()),
                        circuitoSelectors(new QVBoxLayout()), freq(new QSpinBox(this)),
                        volt(new QSpinBox(this)){

type_title->setText("CIRCUITO");

lower->addLayout(circuitoKeyboard);
lower->addLayout(circuitoOp);
lower->addLayout(circuitoSelectors);


circuitoKeyboard->addWidget(new KalkButton(0, "0", this), 3, 1);
circuitoKeyboard->addWidget(new KalkButton(1, "1", this), 2, 0);
circuitoKeyboard->addWidget(new KalkButton(2, "2", this), 2, 1);
circuitoKeyboard->addWidget(new KalkButton(3, "3", this), 2, 2);
circuitoKeyboard->addWidget(new KalkButton(4, "4", this), 1, 0);
circuitoKeyboard->addWidget(new KalkButton(5, "5", this), 1, 1);
circuitoKeyboard->addWidget(new KalkButton(6, "6", this), 1, 2);
circuitoKeyboard->addWidget(new KalkButton(7, "7", this), 0, 0);
circuitoKeyboard->addWidget(new KalkButton(8, "8", this), 0, 1);
circuitoKeyboard->addWidget(new KalkButton(9, "9", this), 0, 2);

circuitoOp->addWidget(new KalkButton(10, "+", this), 0, 0);
circuitoOp->addWidget(new KalkButton(11, "//", this), 0, 1);
circuitoOp->addWidget(new KalkButton(12, "R", this), 0, 2);
circuitoOp->addWidget(new KalkButton(13, "L", this), 1, 0);
circuitoOp->addWidget(new KalkButton(14, "C", this), 1, 1);
circuitoOp->addWidget(new KalkButton(15, "Z", this), 1, 2);

circuitoSelectors->addWidget(new QLabel("Frequenza:", this));
circuitoSelectors->addWidget(freq);
circuitoSelectors->addWidget(new QLabel("Voltaggio:", this));
circuitoSelectors->addWidget(volt);

}
