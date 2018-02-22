//
// Created by luca on 14/01/18.
//

#include "Circuito.h"


double Circuito::freq=50;
C_cartesiano Circuito::volt=24;

Circuito::nodo::~nodo () {
    delete left;
    delete right;
    delete obj;
}

Circuito::nodo::nodo (Componente * c, Circuito::nodo *l, Circuito::nodo *r, std::string op){
    obj=c;
    left=l;
    right=r;
    if(op=="+" || op=="//" || op=="0")
        operation=op;
    else
        throw(0);    //gestire ECCEZIONE
}

Circuito::Circuito(Componente * c):start(new nodo(c)){}

Circuito::~Circuito () {delete start;}

C_cartesiano Circuito::impEquivalente (nodo*n) const {
    if(!n)  return 0;

}

C_cartesiano Circuito::Corrente_totale() const{
    if(volt.getReale() != 0)
        return *(impEquivalente(start)/volt);
    throw(0); //gestire ECCEZIONE
}