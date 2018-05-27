#include "VCircuit.h"

VCircuit::VCircuit(): c_op(new QVBoxLayout()), plot_area(new QVBoxLayout()){

  external_layout->addLayout(plot_area);
  lower->addLayout(c_op);

  c_op->addWidget(new QPushButton("+", this));
  c_op->addWidget(new QPushButton("/", this));
  c_op->addWidget(new QSlider(Qt::Horizontal, this));
  c_op->addWidget(new QSlider(Qt::Horizontal, this));

}
