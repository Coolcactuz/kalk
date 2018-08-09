//
// Created by luca on 18/12/17.
//

#include "Complesso.h"

Complesso* Complesso::solve_operation(Numero* l, Numero* r, char o)const {
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

std::ostream& operator<< (std::ostream& os, const Complesso& c){
    c.stampa(os);
    return os;
}
