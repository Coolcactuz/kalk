#include "startup_view.h"

startup_view::startup_view(): external_layout(new QVBoxLayout(this)),
upper(new QHBoxLayout()), lower(new QHBoxLayout()), kalk_label(new QLabel("KALK", this)),
nota(new KalkButton(3, "TUPLA", this)), circuito(new KalkButton(4, "COMPONENTE", this)),
razionale(new KalkButton(1, "RAZIONALI", this)), complesso(new KalkButton(2, "COMPLESSO", this)){

/*
QHBoxLayout* upper = new QHBoxLayout(this);
QHBoxLayout* lower = new QHBoxLayout(this);
*/

upper->addWidget(kalk_label);
lower->addWidget(razionale);
lower->addWidget(complesso);
lower->addWidget(nota);
lower->addWidget(circuito);


external_layout->addLayout(upper);
external_layout->addLayout(lower);


QObject::connect(nota, SIGNAL(clicked()), this, SLOT(datatype_su()));
QObject::connect(circuito, SIGNAL(clicked()), this, SLOT(datatype_su()));
QObject::connect(razionale, SIGNAL(clicked()), this, SLOT(datatype_su()));
QObject::connect(complesso, SIGNAL(clicked()), this, SLOT(datatype_su()));

}


void startup_view::datatype_su(){

  KalkButton* button = qobject_cast<KalkButton*>(sender());

  int info = 0;

  if(button){
    info = button->getDataNumber();
    std::cout << info << std::endl;
    //emit exchange_datatype(info);
  }
  else
    std::cout <<"button è nullo"<< std::endl;

}
