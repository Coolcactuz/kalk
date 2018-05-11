//
// Created by luca on 03/01/18.
//

#include "Resistore.h"

Resistore::Resistore(double r, std::string n):Componente(0,n),resistenza(r){
  Componente::setImp(impedenza());
}

Resistore::~Resistore(){}

C_cartesiano Resistore::impedenza() const{
    return C_cartesiano(resistenza);
}
