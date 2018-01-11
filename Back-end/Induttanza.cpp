//
// Created by luca on 10/01/18.
//

#include "Induttanza.h"

Induttanza::Induttanza(std::string n, double i):nome(n),induttivita(i){}

std::string Induttanza::getName() const{
    return nome;
}

C_cartesiano Induttanza::impedenza() const{
    //calcoli
    return C_cartesiano(,/*calcoli*/);
}