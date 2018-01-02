//
// Created by luca on 18/12/17.
//

#ifndef KALK_C_POLARE_H
#define KALK_C_POLARE_H

#include "Complesso.h"
#include "C_cartesiano.h"

class C_polare: public Complesso {
private:
    double modulo;
    double fase;

public:
    C_polare(double, double);
    C_polare(const C_polare&);

    C_polare* operator+ (const Numero&)const;
    C_polare* operator- (const Numero&)const;
    C_polare* operator* (const Numero&)const;
    C_polare* operator/ (const Numero&)const;

    Complesso* converti() const;
    Complesso* coniugato() const;
    double getModulo() const;
    double getFase() const;
    void stampa(std::ostream&)const ;
};

std::ostream& operator<<(std::ostream&, const C_polare&);

#endif //KALK_C_POLARE_H
