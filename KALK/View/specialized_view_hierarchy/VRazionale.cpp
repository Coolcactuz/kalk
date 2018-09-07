#include "VRazionale.h"

VRazionale::VRazionale(): razionaleOp(new QGridLayout()){

  type_title->setText("RAZIONALE");

  lower->addLayout(razionaleOp);

  razionaleOp->addWidget(new KalkButton(10, "+"), 0, 0);
  razionaleOp->addWidget(new KalkButton(11, "*"), 0, 1);
  razionaleOp->addWidget(new KalkButton(12, "-"), 1, 0);
  razionaleOp->addWidget(new KalkButton(13, "/"), 1, 1);
  razionaleOp->addWidget(new KalkButton(14, "^"), 2, 0);
  razionaleOp->addWidget(new KalkButton(-6, "sqrt"), 2, 1);
  razionaleOp->addWidget(new KalkButton(-7, "1/x"), 3, 0);
  razionaleOp->addWidget(new KalkButton(-8, "<->"), 3, 1);

  for(int j = 0; j < razionaleOp->count(); j++){

    QLayoutItem* aux = razionaleOp->itemAt(j);
    QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);

    if(tmp){
      QWidget* qw = tmp->widget();
      KalkButton* kb = dynamic_cast<KalkButton*>(qw);

      if(kb){

        if(kb->getDataNumber() > 0){
          QObject::connect(kb, SIGNAL(clicked()), display, SLOT(write_on_kpte()));
        }
        else{
          QObject::connect(kb, SIGNAL(clicked()), this, SLOT(specops_raz()));
        }

      }
    }
  }

  QObject::connect(help, SIGNAL(clicked()), this, SLOT(helpRaz()));
}
