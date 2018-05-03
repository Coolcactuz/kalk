//
// Created by luca on 03/01/18.
//

#include "Resistore.h"

Resistore::Resistore(std::string n, double r):nome(n),resistenza(r){}

std::string Resistore::getName() const{
    return nome;
}

C_cartesiano Resistore::impedenza() const{
    return C_cartesiano(resistenza);
}