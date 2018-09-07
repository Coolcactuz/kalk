#ifndef KALK_C_CARTESIANO_H
#define KALK_C_CARTESIANO_H


#include "Complesso.h"

class C_polare;


class C_cartesiano: public Complesso {

private:

    double reale;
    double immaginaria;

public:

    C_cartesiano();
    C_cartesiano(double,double =0);
    C_cartesiano(std::string);

    C_cartesiano* operator+ (const Numero*)const;
    C_cartesiano* operator- (const Numero*)const;
    C_cartesiano* operator* (const Numero*)const;
    C_cartesiano* operator/ (const Numero*)const;
    bool operator== (const Dato&)const;

    std::string toString() const;
    double getReale() const;
    double getImmaginaria() const;
    C_cartesiano* coniugato() const override;
    Complesso* converti()const override;
};

#endif //KALK_C_CARTESIANO_H
