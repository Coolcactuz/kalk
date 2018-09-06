#include "Complesso.h"

Complesso* Complesso::solve_operation(const Dato* a, const Dato* b, char o){
    auto l=dynamic_cast<const Complesso*>(a);
    auto r=dynamic_cast<const Complesso*>(b);
    if(l && r){
        try{
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
        catch(const syntax_exception& se){
            throw;
        }
        catch(const logic_exception& le){
            throw;
        }
    }
    else
        throw logic_exception("tipo di dati errato");
}

