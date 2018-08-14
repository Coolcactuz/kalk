//
// Created by luca on 03/01/18.
//

#include "Componente.h"

Componente::Componente(C_cartesiano c): imp(c){}
Componente::Componente(std::string s){

}
Componente::Componente(): imp(0){}
Componente::~Componente(){}

Componente* Componente::create(std::string){}

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

Componente* Componente::solve_operation(const Dato* l, const Dato* r, char o){
    auto l=dynamic_cast<const Componente*>(a);
    auto r=dynamic_cast<const Componente*>(b);
    if(a && b){
        switch(o) {
            case '+':
                return dynamic_cast<Componente*>(l->operator+(r));
            case '*':
                return dynamic_cast<Componente*>(l->operator*(r));
            default:
                throw (0); //gestire eccezione operatore errato
        }
    }
}

C_cartesiano Componente::impedenza() const{
  return imp;
}

void Componente::setImp(const C_cartesiano c ){
  this->imp=c;
}
