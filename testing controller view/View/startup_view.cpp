#include "startup_view.h"

startup_view::startup_view(): external_layout(new QVBoxLayout(this)),
upper(new QHBoxLayout()), lower(new QHBoxLayout()), kalk_label(new QLabel("KALK", this)),
nota(new KalkButton(3, "NOTA", this)), circuito(new KalkButton(4, "CIRCUITO", this)),
tipi_numerici(new QComboBox(this)){

/*
QHBoxLayout* upper = new QHBoxLayout(this);
QHBoxLayout* lower = new QHBoxLayout(this);
*/

upper->addWidget(kalk_label);
lower->addWidget(tipi_numerici);
lower->addWidget(nota);
lower->addWidget(circuito);


external_layout->addLayout(upper);
external_layout->addLayout(lower);

tipi_numerici->addItem("RAZIONALI");
tipi_numerici->addItem("COMPLESSI POLARI");
tipi_numerici->addItem("COMPLESSI CARTESIANI");

QObject::connect(nota, SIGNAL(clicked()), this, SLOT(datatype_su()));
QObject::connect(circuito, SIGNAL(clicked()), this, SLOT(datatype_su()));
QObject::connect(tipi_numerici, SIGNAL(activated(int)), this, SIGNAL(exchange_datatype(int)));


}

startup_view::~startup_view(){
  delete upper;
  delete lower;
}

void startup_view::datatype_su(){
  KalkButton* button = qobject_cast<KalkButton*>(sender());

  int info = -2;

  if(button){
    info = button->getDataNumber();
    emit exchange_datatype(info);
  }
  else
    std::cout <<"button è nullo"<< std::endl;


}
