//
// Created by luca on 14/01/18.
//

#include "Circuito.h"


double Circuito::freq=50;
double Circuito::volt=24;

Circuito::nodo::~nodo () {
    delete left;
    delete right;
    delete obj;
}

Circuito::nodo::nodo (Componente * c, Circuito::nodo *l, Circuito::nodo *r, Circuito::nodo *f, std::string op){
    obj=c;
    left=l;
    right=r;
    father=f;
    if(op=="+" || op=="//" || op=="0")
        operation=op;
    else
        throw(0);    //gestire ECCEZIONE
}

Circuito::Circuito(Componente * c):start(new nodo(c)){}

Circuito::~Circuito () {delete start;}
/*
bool Circuito::const_iterator::operator==(const const_iterator& cit) const {
  return ptr == cit.ptr;
}

bool Circuito::const_iterator::operator!=(const const_iterator& cit) const {
  return ptr != cit.ptr;
}
*/
C_cartesiano Circuito::impEquivalente (nodo*n) const {
  return 0;
}

C_cartesiano Circuito::Corrente_totale() const{
    if(volt != 0)
        return impEquivalente(start)/volt;
    throw(0); //gestire ECCEZIONE
}
