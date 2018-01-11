//
// Created by luca on 03/01/18.
//

#include "Macro.h"

Macro::Micro::Micro(Componente* c,Micro* f,Micro* s,Micro* p):obj(c),father(f),serie(s),parallelo(p){};

Macro::Micro::~Micro(){
    delete serie;
    delete parallelo;
    delete obj;
}

//Macro::Macro(Componente* c):start(new Micro(c,0,0,0)),next(0),prev(0){}

Macro::Macro(Componente *c, Macro* n, Macro* p):
    start(new Micro(c)),next(n),prev(p){}

Macro::~Macro(){
    delete next;
    delete start;
}

Macro* Macro::operator+ (Componente *c) {
    Macro*aux=this;
    while(aux->next)
        aux=aux->next;
    aux->next=new Macro(c);
    return this;
}

