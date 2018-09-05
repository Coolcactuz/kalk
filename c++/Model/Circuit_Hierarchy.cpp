//
// Created by luca on 01/08/18.
//

#include "Circuit_Hierarchy.h"

Circuit_Hierarchy::Circuit_Hierarchy(){
    load_operators();
}

void Circuit_Hierarchy::load_operators() {
    unsigned int n=2;
    char op[n]={'+','/'};
    for(unsigned int i=0; i<n; ++i)
        add_operator(op[i]);
}

Componente* Circuit_Hierarchy::create(std::string s) const{
    try {
        if (s.find('Z') != -1)
            return new Componente(s);
        if (s.find('R') != -1)
            return new Resistore(s);
        if (s.find('L') != -1)
            return new Induttore(s);
        if (s.find('C') != -1)
            return new Condensatore(s);
        throw syntax_exception("errore di sintassi"); //gestire eccezione errore tipo
    }
    catch (const syntax_exception& se){
        throw ;
    }
}
