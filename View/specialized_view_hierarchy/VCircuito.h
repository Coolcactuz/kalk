#ifndef VCIRCUITO_H
#define VCIRCUITO_H

#include "numerical_insert.h"

class VCircuito: public numerical_insert{
private:
  QGridLayout* circuitoOp;
  QVBoxLayout* circuitoSelectors;
  QSpinBox* freq;
  QSpinBox* volt;
public:
  VCircuito();
};

#endif
