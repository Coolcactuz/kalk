//
// Created by luca on 10/01/18.
//

#include "Induttore.h"

Induttore::Induttore(std::string n, double i):nome(n),induttanza(i){}

std::string Induttore::getName() const{
    return nome;
}

C_cartesiano Induttore::impedenza() const{
    double xl=2*Numero::pi*Circuito::freq*induttanza;
    return C_cartesiano(0,xl);
}