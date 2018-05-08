//
// Created by luca on 03/01/18.
//

#include "Componente.h"

/*Componente Componente::operator+ (const Componente & c) const {
    return new Componente(*( impedenza()+ c.impedenza()));
}

Componente Componente::operator/ (const Componente & c) const {
    return *(*(impedenza()*c.impedenza()) / *(impedenza()+c.impedenza()));
}*/

Componente::Componente(C_cartesiano c): imp(c){}

C_cartesiano Componente::impedenza() const{
  return imp;
}
