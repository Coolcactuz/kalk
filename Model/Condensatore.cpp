//
// Created by luca on 11/01/18.
//

#include "Condensatore.h"

Condensatore::Condensatore(double c):Componente(),capacita(c){
  Componente::setImp(impedenza());
}
Condensatore::Condensatore(std::string s){
  
}
Condensatore::Condensatore():Componente(),capacita(0){};
Condensatore::~Condensatore(){}

C_cartesiano Condensatore::impedenza() const{
    double xc=1/(2*(Numero::pi)*(Circuito::freq)*capacita);
    return C_cartesiano(0,-xc);
}
