//
// Created by luca on 18/12/17.
//

#include "C_polare.h"
#include <cmath>

C_polare::C_polare(double m=0, double f=0) {
    if(m<0) throw (0);    //GESTIRE ECCEZIONE
    else
        modulo=m;
    while(f>=360 && f<0) {
        f=((f>=360)?f-360:f+360);
    }
    fase=f;
}


Complesso* C_polare::converti() {
    double reale=modulo*cos(deg_to_rad(fase));
    double immaginaria=modulo*sin(deg_to_rad(fase));
    return new C_cartesiano(reale,immaginaria);
}

void C_polare::stampa(std::ostream& os)const {
    std::cout<<modulo<<"∟"<<fase<<"°";
}

std::ostream& operator<<(std::ostream& os, const C_polare& cp){
    cp.stampa(os);
    return os;
}