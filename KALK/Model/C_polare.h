#ifndef KALK_C_POLARE_H
#define KALK_C_POLARE_H

#include "C_cartesiano.h"

class C_polare: public Complesso {
private:
    double modulo;
    double fase;

public:
    C_polare(double, double);
    C_polare(std::string);
    C_polare();

    C_polare* operator+ (const Numero*)const;
    C_polare* operator- (const Numero*)const;
    C_polare* operator* (const Numero*)const;
    C_polare* operator/ (const Numero*)const;
    bool operator== (const Dato&)const;

    std::string toString() const;
    Complesso* converti() const;
    C_polare* coniugato() const;
    double getModulo() const;
    double getFase() const;
};

#endif //KALK_C_POLARE_H
