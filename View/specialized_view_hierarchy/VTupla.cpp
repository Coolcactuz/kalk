#include "VTupla.h"

VTupla::VTupla(): tupla_op(new QGridLayout()){

  type_title->setText("TUPLA");

  lower->addLayout(tupla_op);

  //tupla_op->addWidget(new KalkButton(8, "+", this), 0, 0);
  tupla_op->addWidget(new KalkButton(10, "-", this), 0, 0);
  tupla_op->addWidget(new KalkButton(11, "/", this), 1, 0);
  tupla_op->addWidget(new KalkButton(12, "%", this), 2, 0);

  for(int j = 0; j < tupla_op->count(); j++){

    QLayoutItem* aux = tupla_op->itemAt(j);
    QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);

    if(tmp){
      QWidget* qw = tmp->widget();
      KalkButton* kb = dynamic_cast<KalkButton*>(qw);

      if(kb){
        QObject::connect(kb, SIGNAL(clicked()), display, SLOT(write_on_kpte()));
      }
    }
  }

  QObject::connect(help, SIGNAL(clicked()), this, SLOT(helpTupla()));

}
