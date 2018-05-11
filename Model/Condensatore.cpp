//
// Created by luca on 11/01/18.
//

#include "Condensatore.h"

Condensatore::Condensatore(double c, std::string n):Componente(0,n),capacita(c){
  Componente::setImp(impedenza());
}

Condensatore::~Condensatore(){}

C_cartesiano Condensatore::impedenza() const{
    double xc=1/(2*(Numero::pi)*(Circuito::freq)*capacita);
    return C_cartesiano(0,-xc);
}
