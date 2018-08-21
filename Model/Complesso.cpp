#include "Complesso.h"

Complesso* Complesso::solve_operation(Numero* l, Numero* r, char o)const {

    Complesso* res = 0;

    switch(o) {
        case '+':
            res = dynamic_cast<Complesso*>(l->operator+(r));
        case '-':
            res = dynamic_cast<Complesso*>(l->operator-(r));
        case '*':
            res = dynamic_cast<Complesso*>(l->operator*(r));
        case '/':
            res = dynamic_cast<Complesso*>(l->operator/(r));
        default:
            throw syntax_exception("Operatore non valido"); //gestire eccezione operatore errato
    }

    if(!res)
      throw logic_exception();

    return res;
}

std::ostream& operator<< (std::ostream& os, const Complesso& c){
    c.stampa(os);
    return os;
}
