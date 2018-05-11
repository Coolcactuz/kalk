//
// Created by luca on 03/01/18.
//

#include "Componente.h"

Componente::Componente(C_cartesiano c, std::string n): imp(c), nome(n){}
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

std::string Componente::getName() const{
  return nome;
}

C_cartesiano Componente::impedenza() const{
  return imp;
}

void Componente::setImp(const C_cartesiano& c ){
  imp=c;
}
