#include "Componente.h"


Componente::Componente(C_cartesiano c): imp(c){}

Componente::Componente(std::string s){  //???????

}

Componente::Componente(): imp(0){}

Componente::~Componente(){}

Componente* Componente::create(std::string){}  //????

Componente* Componente::operator+ (const Componente* c) const{
    C_cartesiano c1=impedenza();
    C_cartesiano c2=c->impedenza();
    return new Componente(*((&c1)->operator+(&c2)));
}

Componente* Componente::operator/ (const Componente* c) const {
    C_cartesiano c1=impedenza();
    C_cartesiano c2=c->impedenza();
    return new Componente(*(((&c1)->operator*(&c2))->operator/((&c1)->operator+(&c2))));
}

Componente* Componente::solve_operation(const Componente* l, const Componente* r, char o) const{
    switch(o) {
        case '+':
            return l->operator+(r);
        case '/':
            return l->operator/(r);
        default:
            throw syntax_exception("Operatore inesistente");
    }
}

C_cartesiano Componente::impedenza() const{
  return imp;
}

void Componente::setImp(const C_cartesiano c){
  imp=c;
}
