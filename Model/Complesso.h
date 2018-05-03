//
// Created by luca on 18/12/17.
//

#ifndef KALK_COMPLESSO_H
#define KALK_COMPLESSO_H

#include "Numero.h"

class Complesso : public Numero{
public:
    virtual Complesso* converti() const =0;
    virtual Complesso* coniugato() const =0;
};
std::ostream& operator<< (std::ostream&, const Complesso&);


#endif