#ifndef VCIRCUIT_H
#define VCIRCUIT_H

#include "specialized_view.h"
#include <QSlider>

class VCircuit: public specialized_view{

private:
  QVBoxLayout* c_op;
  QVBoxLayout* plot_area;

public:

  VCircuit();
};

#endif
