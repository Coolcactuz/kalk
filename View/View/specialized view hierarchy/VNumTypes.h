#ifndef VNUMTYPES_H
#define VNUMTYPES_H

#include "specialized_view.h"

class VNumTypes: public specialized_view{

protected:
  QGridLayout* nt_op;

public:
  VNumTypes();
  ~VNumTypes(){
    std::cout << "distruttore numtypes" << std::endl;
  }


  void plot();
};

#endif
