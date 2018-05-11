//
// Created by luca on 14/01/18.
//

#include "Circuito.h"


double Circuito::freq=0;
double Circuito::volt=0;

Circuito::Circuito(Componente * c){
  v.push_back(c);
}

Circuito::~Circuito () {
  for(auto cit=v.cbegin(); cit!=v.cend(); ++cit ){
    delete *cit;
    v.erase(cit);
    cit--;
  }
}

C_cartesiano Circuito::impEquivalente () const {
  return 0;
}

C_cartesiano Circuito::Corrente_totale() const{
    if(volt != 0){
        C_cartesiano v=C_cartesiano(volt);
        C_cartesiano impEq=impEquivalente();
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
