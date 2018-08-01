//
// Created by luca on 01/08/18.
//

#include "Circuit_Hierarchy.h"

Componente* Circuit_Hierarchy::create(std::string s){
    if(s.find('Z')!=-1)
        return new Componente(s);
    if(s.find('R')!=-1)
        return new Resistore(s);
    if(s.find('L')!=-1)
        return new Induttore(s);
    if(s.find('C')!=-1)
        return new Condensatore(s);
    throw(0); //gestire eccezione errore tipo
}