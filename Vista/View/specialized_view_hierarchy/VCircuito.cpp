#include "VCircuito.h"

VCircuito::VCircuito(): circuitoOp(new QGridLayout()),circuitoSelectors(new QVBoxLayout()), freq(new QSpinBox(this)), volt(new QSpinBox(this)){

type_title->setText("CIRCUITO");

lower->addLayout(circuitoOp);
lower->addLayout(circuitoSelectors);

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
