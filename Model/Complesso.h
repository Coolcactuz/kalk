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
    virtual void stampa(std::ostream&) const =0;

    static Complesso* solve_operation(const Dato*, const Dato*, char);
};
std::ostream& operator<< (std::ostream&, const Complesso&);
#endif
