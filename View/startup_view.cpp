#include "startup_view.h"

startup_view::startup_view(): external_layout(new QVBoxLayout(this)),
upper(new QHBoxLayout()), lower(new QHBoxLayout()), kalk_label(new QLabel("KALK", this)),
nota(new selectTypeButton(3, "NOTA", this)), circuito(new selectTypeButton(4, "CIRCUITO", this)),
tipi_numerici(new QComboBox(this)){

/*
QHBoxLayout* upper = new QHBoxLayout(this);
QHBoxLayout* lower = new QHBoxLayout(this);
*/

upper->addWidget(kalk_label);
lower->addWidget(nota);
lower->addWidget(circuito);
lower->addWidget(tipi_numerici);

external_layout->addLayout(upper);
external_layout->addLayout(lower);

tipi_numerici->addItem("RAZIONALI");
tipi_numerici->addItem("COMPLESSI POLARI");
tipi_numerici->addItem("COMPLESSI CARTESIANI");

QObject::connect(nota, SIGNAL(clicked()), this, SLOT(datatype_su()));

}

startup_view::~startup_view(){
  delete upper;
  delete lower;
}

void startup_view::datatype_su(){
  selectTypeButton* button = qobject_cast<selectTypeButton*>(sender());

  int info = -2;

  if(button){
    info = button->getDataNumber();
    emit exchange(info);
  }
  else
    std::cout <<"button è nullo"<< std::endl;


}
