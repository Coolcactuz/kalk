//
// Created by luca on 18/12/17.
//

#ifndef KALK_DATO_H
#define KALK_DATO_H

#include <iostream>
#include <cmath>
#include <typeinfo>
#include "exception.h"

class Dato{
public:
    virtual ~Dato() = default;
    virtual bool operator==(const Dato&) const =0;
    virtual Dato& operator=(const Dato&) =0;
};


#endif //KALK_NUMERO_H
