#ifndef KALK_DATO_H
#define KALK_DATO_H

#include <iostream>
#include <cmath>
#include "parser.h"

class Dato {
public:
  virtual ~Dato() = default;
  virtual void stampa(std::ostream &) const = 0;
};


#endif //KALK_DATO_H
