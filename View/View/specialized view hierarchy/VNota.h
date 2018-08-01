#ifndef VNOTA_H
#define VNOTA_H

#include "specialized_view.h"

class VNota: public specialized_view{

public:

  VNota(){
    lower->addWidget(new QPushButton("CIAO"));
  }

  void plot(){
    
  }
};

#endif
