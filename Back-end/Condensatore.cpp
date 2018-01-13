//
// Created by luca on 11/01/18.
//

#include "Condensatore.h"


Condensatore::Condensatore(std::string n, double c):nome(n),capacita(c){}

std::string Condensatore::getName() const{
    return nome;
}

C_cartesiano Condensatore::impedenza() const{
    //calcoli
    return C_cartesiano(,/*calcoli*/);
}