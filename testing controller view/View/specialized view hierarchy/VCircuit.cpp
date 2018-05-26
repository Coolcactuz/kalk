#include "VCircuit.h"

VCircuit::VCircuit(): c_op(new QVBoxLayout()), plot_area(new QVBoxLayout()){

  external_layout->addLayout(plot_area);
  lower->addLayout(c_op);

  c_op->addWidget(new QPushButton("+", this));
  c_op->addWidget(new QPushButton("/", this));
  c_op->addWidget(new QSlider(Qt::Horizontal, this));
  c_op->addWidget(new QSlider(Qt::Horizontal, this));

}

VCircuit::~VCircuit(){

  std::cout << "distruttore VCircuit - inizio" << std::endl;


  delete c_op;
  delete plot_area;


  std::cout << "distruttore VCircuit - fine" << std::endl;

}
