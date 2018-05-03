//
// Created by luca on 19/12/17.
//

#ifndef KALK_C_CARTESIANO_H
#define KALK_C_CARTESIANO_H


#include "Complesso.h"
#include "C_polare.h"


class C_cartesiano: public Complesso {

private:
    double reale;
    double immaginaria;

public:
    C_cartesiano(double =0,double =0);
    C_cartesiano(const C_cartesiano&);

    C_cartesiano* operator+ (const Numero*)const;
    C_cartesiano* operator- (const Numero*)const;
    C_cartesiano* operator* (const Numero*)const;
    C_cartesiano* operator/ (const Numero*)const;

    static C_cartesiano* parse(std::string);

    double getReale() const;
    double getImmaginaria() const;
    C_cartesiano* coniugato() const override;

    Complesso* converti()const override;
    void stampa(std::ostream&)const override ;
};

std::ostream& operator<<(std::ostream&, const Numero&);

#endif //KALK_C_CARTESIANO_H