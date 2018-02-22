//
// Created by luca on 18/12/17.
//

#include "C_polare.h"
#include <cmath>

C_polare::C_polare(double m, double f) {
    if(m<0) throw (0);    //GESTIRE ECCEZIONE
    else
        modulo=m;
    while(f>=360 && f<0) {
        f=((f>=360)?f-360:f+360);
    }
    fase=f;
}

C_polare::C_polare(const C_polare& c):modulo(c.modulo),fase(c.fase){};

C_polare* C_polare::operator+ (const Numero& n)const{
    C_cartesiano* aux1= static_cast<C_cartesiano*>((new C_polare(*this))->converti());
    C_polare cp= static_cast<const C_polare&>(n);
    C_cartesiano* aux2= static_cast<C_cartesiano*>(cp.converti());
    C_cartesiano* somma=new C_cartesiano(*(*aux1+*aux2));
    delete aux1;
    delete aux2;
    return static_cast<C_polare*>(somma->converti());
}
C_polare* C_polare::operator- (const Numero& n)const{
    C_cartesiano* aux1= static_cast<C_cartesiano*>((new C_polare(*this))->converti());
    C_polare cp= static_cast<const C_polare&>(n);
    C_cartesiano* aux2= static_cast<C_cartesiano*>(cp.converti());
    C_cartesiano* differenza=new C_cartesiano(*(*aux1-*aux2));
    delete aux1;
    delete aux2;
    return static_cast<C_polare*>(differenza->converti());
}
C_polare* C_polare::operator* (const Numero& n)const{
    C_polare cp= dynamic_cast<const C_polare&>(n);
    double m=modulo*cp.modulo;
    double f=rad_to_deg(atan(deg_to_rad(fase))+atan(deg_to_rad(cp.fase)));
    return new C_polare(m,f);
}
C_polare* C_polare::operator/ (const Numero& n)const{
    C_polare cp= dynamic_cast<const C_polare&>(n);
    double m=modulo/cp.modulo;
    double f=rad_to_deg(atan(deg_to_rad(fase))-atan(deg_to_rad(cp.fase)));
    return new C_polare(m,f);
}

Complesso* C_polare::converti() const{
    double reale=modulo*cos(deg_to_rad(fase));
    double immaginaria=modulo*sin(deg_to_rad(fase));
    return new C_cartesiano(reale,immaginaria);
}

C_polare* C_polare::coniugato() const {
    return new C_polare(modulo,fase*-1);
}

double C_polare::getModulo() const {return modulo;}

double C_polare::getFase() const {return fase;}

void C_polare::stampa(std::ostream& os)const {
    std::cout<<modulo<<"∟"<<fase<<"°";
}

std::ostream& operator<<(std::ostream& os, const C_polare& cp){
    cp.stampa(os);
    return os;
}