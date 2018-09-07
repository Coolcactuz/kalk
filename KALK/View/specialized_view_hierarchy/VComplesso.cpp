#include "VComplesso.h"

VComplesso::VComplesso(): complessoOp(new QGridLayout()){

  type_title->setText("COMPLESSO");

  lower->addLayout(complessoOp);

  complessoOp->addWidget(new KalkButton(10, "+"), 0, 0);
  complessoOp->addWidget(new KalkButton(11, "*"), 0, 1);
  complessoOp->addWidget(new KalkButton(12, "-"), 1, 0);
  complessoOp->addWidget(new KalkButton(13, "/"), 1, 1);
  complessoOp->addWidget(new KalkButton(-4, "<->"), 2, 0);
  complessoOp->addWidget(new KalkButton(-5, "¬"), 2, 1);
  complessoOp->addWidget(new KalkButton(14, "i"), 3, 0);
  complessoOp->addWidget(new KalkButton(15, "<"), 3, 1);


  for(int j = 0; j < complessoOp->count(); j++){

    QLayoutItem* aux = complessoOp->itemAt(j);
    QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);

    if(tmp){
      QWidget* qw = tmp->widget();
      KalkButton* kb = dynamic_cast<KalkButton*>(qw);

      if(kb){

        if(kb->getDataNumber() > 0){
          QObject::connect(kb, SIGNAL(clicked()), display, SLOT(write_on_kpte()));
        }
        else{
          QObject::connect(kb, SIGNAL(clicked()), this, SLOT(specops_complesso()));
        }
      }
    }
  }

  QObject::connect(help, SIGNAL(clicked()), this, SLOT(helpComplesso()));

}
