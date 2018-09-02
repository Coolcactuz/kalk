#ifndef VRAZIONALE_H
#define VRAZIONALE_H

#include "numerical_insert.h"

class VRazionale: public numerical_insert{
private:
  QGridLayout* razionaleOp;
public:
  VRazionale();

  ~VRazionale(){
    std::cout << "SONO IL DISTRUTTORE DI VRAZIONALE" << std::endl;
  }
};

#endif
