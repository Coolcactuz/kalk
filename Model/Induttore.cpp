//
// Created by luca on 10/01/18.
//

#include "Induttore.h"

Induttore::Induttore(double i, std::string n):Componente(0,n),induttanza(i){
  Componente::setImp(impedenza());
}

Induttore::~Induttore(){}

C_cartesiano Induttore::impedenza() const{
    double xl=2*Numero::pi*Circuito::freq*induttanza;
    return C_cartesiano(0,xl);
}
