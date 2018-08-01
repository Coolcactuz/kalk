#ifndef VCIRCUIT_H
#define VCIRCUIT_H

#include "specialized_view.h"
#include <QSpinBox>

class VCircuit: public specialized_view{

private:
  
  QVBoxLayout* c_op;

public:

  VCircuit();

  void plot();
};

#endif
