//
// Created by luca on 14/01/18.
//

#include "Circuito.h"


double Circuito::freq=0;
double Circuito::volt=0;

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
    if(volt != 0){
        C_cartesiano v=C_cartesiano(volt);
        C_cartesiano impEq=impEquivalente(start);
        return *((&impEq)->operator/(&v));
    }
    throw(0); //gestire ECCEZIONE
}

void Circuito::setVolt(double v){
  if(v>=0)
    volt=v;
  else
    throw(0); //gestire eccezione
}
void Circuito::setFreq(double f){
  if(f>=0)
    freq=f;
  else
    throw(0); //gestire eccezione
}
