#include "startup_view.h"

startup_view::startup_view(): external_layout(new QVBoxLayout(this)),
upper(new QHBoxLayout()), lower(new QHBoxLayout()), kalk_label(new QLabel("KALK")),
tupla(new KalkButton(3, "TUPLA")), circuito(new KalkButton(4, "CIRCUITO")),
razionale(new KalkButton(1, "RAZIONALE")), complesso(new KalkButton(2, "COMPLESSO")){

/*
QHBoxLayout* upper = new QHBoxLayout(this);
QHBoxLayout* lower = new QHBoxLayout(this);
*/

upper->addWidget(kalk_label);
kalk_label->setAlignment(Qt::AlignCenter);


lower->addWidget(razionale);
lower->addWidget(complesso);
lower->addWidget(tupla);
lower->addWidget(circuito);


external_layout->addLayout(upper);
external_layout->addLayout(lower);


QObject::connect(tupla, SIGNAL(clicked()), this, SLOT(type_FButtonTStartup()));
QObject::connect(circuito, SIGNAL(clicked()), this, SLOT(type_FButtonTStartup()));
QObject::connect(razionale, SIGNAL(clicked()), this, SLOT(type_FButtonTStartup()));
QObject::connect(complesso, SIGNAL(clicked()), this, SLOT(type_FButtonTStartup()));

}


void startup_view::type_FButtonTStartup(){

  KalkButton* button = qobject_cast<KalkButton*>(sender());

  int info = 0;

  if(button){
    info = button->getDataNumber();
    //std::cout << info << std::endl;
    emit type_FStartupTController(info);
  }
  else	//non ci entrera' mai
    std::cout << "non e' un KalkButton" << std::endl;
}
