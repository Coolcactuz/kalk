#ifndef VCIRCUITO_H
#define VCIRCUITO_H

#include "specialized_view.h"

class VCircuito: public specialized_view{

private:

  QGridLayout* circuitoKeyboard;
  QGridLayout* circuitoOp;

  QVBoxLayout* circuitoSelectors;

  QSpinBox* freq;
  QSpinBox* volt;

public:

  VCircuito();

};

#endif
