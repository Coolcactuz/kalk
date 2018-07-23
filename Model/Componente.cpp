//
// Created by luca on 03/01/18.
//

#include "Componente.h"

Componente::Componente(C_cartesiano c): imp(c){}
Componente::Componente(std::string s){

}
Componente::Componente(): imp(0){}
Componente::~Componente(){}

Componente* Componente::operator+ (const Componente* c) const{
    C_cartesiano c1=impedenza();
    C_cartesiano c2=c->impedenza();
    return new Componente(*((&c1)->operator+(&c2)));
}

Componente* Componente::operator/ (const Componente* c) const {
    C_cartesiano c1=impedenza();
    C_cartesiano c2=c->impedenza();
    return new Componente(*(((&c1)->operator*(&c2))->operator/( (&c1)->operator+(&c2))));
}

C_cartesiano Componente::impedenza() const{
  return imp;
}

void Componente::setImp(const C_cartesiano& c ){
  imp=c;
}
