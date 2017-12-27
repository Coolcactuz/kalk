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
    C_cartesiano(double,double);
    C_cartesiano(const C_cartesiano&);

    C_cartesiano* operator+ (const Numero&)const;
    C_cartesiano* operator- (const Numero&)const;
    C_cartesiano* operator* (const Numero&)const;
    C_cartesiano* operator/ (const Numero&)const;


    double getReale() const {return reale;}
    double getImmaginaria() const {return immaginaria;}

    Complesso* converti()override;
    void stampa(std::ostream&)const override ;
};


std::ostream& operator<<(std::ostream&, const Numero&);

#endif //KALK_C_CARTESIANO_H
