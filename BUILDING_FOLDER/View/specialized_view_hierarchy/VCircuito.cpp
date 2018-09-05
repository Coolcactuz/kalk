#include "VCircuito.h"

VCircuito::VCircuito(): circuitoOp(new QGridLayout()),circuitoSelectors(new QVBoxLayout()), freq(new QDoubleSpinBox(this)), volt(new QDoubleSpinBox(this)){

type_title->setText("CIRCUITO");

lower->addLayout(circuitoOp);
lower->addLayout(circuitoSelectors);

circuitoOp->addWidget(new KalkButton(10, "+", this), 0, 1);
circuitoOp->addWidget(new KalkButton(11, "/", this), 1, 1);
circuitoOp->addWidget(new KalkButton(12, "R", this), 0, 0);
circuitoOp->addWidget(new KalkButton(13, "L", this), 1, 0);
circuitoOp->addWidget(new KalkButton(14, "C", this), 2, 0);
//circuitoOp->addWidget(new KalkButton(15, "Z", this), 1, 2);

for(int j = 0; j < circuitoOp->count(); j++){

  QLayoutItem* aux = circuitoOp->itemAt(j);
  QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);

  if(tmp){
    QWidget* qw = tmp->widget();
    KalkButton* kb = dynamic_cast<KalkButton*>(qw);

    if(kb){
      QObject::connect(kb, SIGNAL(clicked()), display, SLOT(write_on_kpte()));
    }
  }
}

circuitoSelectors->addWidget(new QLabel("Frequenza:", this));
circuitoSelectors->addWidget(freq);
circuitoSelectors->addWidget(new QLabel("Voltaggio:", this));
circuitoSelectors->addWidget(volt);

QObject::connect(freq, SIGNAL(valueChanged(double)), this, SIGNAL(specialized_view_inviaFreq(double)));
QObject::connect(volt, SIGNAL(valueChanged(double)), this, SIGNAL(specialized_view_inviaVolt(double)));

QObject::connect(help, SIGNAL(clicked()), this, SLOT(helpCircuito()));

}
