//
// Created by luca on 18/12/17.
//

#include "Complesso.h"

Complesso* Complesso::solve_operation(const Dato* a, const Dato* b, char o){
    auto l=dynamic_cast<const Complesso*>(a);
    auto r=dynamic_cast<const Complesso*>(b);
    if(a && b){
        switch(o) {
            case '+':
                return dynamic_cast<Complesso*>(l->operator+(r));
            case '-':
                return dynamic_cast<Complesso*>(l->operator-(r));
            case '*':
                return dynamic_cast<Complesso*>(l->operator*(r));
            case '/':
                return dynamic_cast<Complesso*>(l->operator/(r));
            default:
                throw (0); //gestire eccezione operatore errato
        }
    }
}

std::ostream& operator<< (std::ostream& os, const Complesso& c){
    c.stampa(os);
    return os;
}
