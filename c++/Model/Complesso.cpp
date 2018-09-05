//
// Created by luca on 18/12/17.
//

#include "Complesso.h"

Complesso* Complesso::solve_operation(const Dato* a, const Dato* b, char o){
    auto l=dynamic_cast<const Complesso*>(a);
    auto r=dynamic_cast<const Complesso*>(b);
    if(l && r){
        switch(o) {
            case '+':
                return static_cast<Complesso*>(l->operator+(r));
            case '-':
                return static_cast<Complesso*>(l->operator-(r));
            case '*':
                return static_cast<Complesso*>(l->operator*(r));
            case '/':
                return static_cast<Complesso*>(l->operator/(r));
            default:
                throw syntax_exception("Operatore non valido"); //gestire eccezione operatore errato
        }
    }
    else
        throw logic_exception("tipo di dati errato");
}

std::ostream& operator<< (std::ostream& os, const Complesso& c){
    c.stampa(os);
    return os;
}