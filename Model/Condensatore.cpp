//
// Created by luca on 11/01/18.
//

#include "Condensatore.h"


Condensatore::Condensatore(std::string n, double c):nome(n),capacita(c), Componente(impedenza()){}

std::string Condensatore::getName() const{
    return nome;
}

C_cartesiano Condensatore::impedenza() const{
    double xc=1/(2*Numero::pi*Circuito::freq*capacita);
    return C_cartesiano(0,-xc);
}
