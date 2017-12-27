//
// Created by luca on 19/12/17.
//

#include "C_cartesiano.h"
#include <cmath>

C_cartesiano::C_cartesiano(double r=0, double i=0):reale(r),immaginaria(i){};

C_cartesiano::C_cartesiano(const C_cartesiano& c):reale(c.reale),immaginaria(c.immaginaria){};


C_cartesiano* C_cartesiano::operator+ (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale+c.reale,immaginaria+c.immaginaria);
}
C_cartesiano* C_cartesiano::operator- (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale-c.reale,immaginaria-c.immaginaria);
}
C_cartesiano* C_cartesiano::operator* (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale*c.reale-immaginaria*c.immaginaria,immaginaria*c.reale+reale*c.immaginaria);
}
C_cartesiano* C_cartesiano::operator/ (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale/c.reale-immaginaria/c.immaginaria,immaginaria/c.reale+reale/c.immaginaria);
}

Complesso* C_cartesiano::converti() {
    double fase=sqrt(pow(reale,2)+pow(immaginaria,2));
    double modulo=(immaginaria<0)?rad_to_deg(atan(immaginaria/reale)+pi):rad_to_deg(atan(immaginaria/reale));
    return new C_polare(fase,modulo);
}

void C_cartesiano::stampa(std::ostream& os)const {
    std::cout<<reale;
    (immaginaria<0)?std::cout<<immaginaria:std::cout<<"+"<<immaginaria;
    std::cout<<"i";
}

std::ostream& operator<<(std::ostream& os, const Numero& n){
    C_cartesiano cc= static_cast<const C_cartesiano&>(n);
    cc.stampa(os);
    return os;
}