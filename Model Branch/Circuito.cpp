#include "Circuito.h"

double Circuito::freq=0;
double Circuito::volt=0;

Circuito::Circuito(std::string s): circuit(parser<Componente>(s)){}

C_cartesiano Circuito::impEquivalente () const {
    Componente* res = static_cast<Componente*>(parser<Componente>::resolve(circuit.getStart()));
    return res->impedenza();
}

C_cartesiano Circuito::Corrente_totale() const{
    if(volt != 0){
        C_cartesiano v=C_cartesiano(volt);
        C_cartesiano impEq=impEquivalente();
        return *((&impEq)->operator/(&v));
    }
    return 0;
}

Circuito Circuito::operator=(const Circuito& c){
    if(!(circuit==c.circuit)){
        delete this->circuit.getStart();
        delete this->circuit.getHandler();
        circuit = c.circuit;
    }
    return *this;
}

void Circuito::setVolt(double v){
  if(v>=0)
    volt=v;
  else
    throw logic_exception("Invalid Value");   //gestire eccezione invalid value
}

void Circuito::setFreq(double f){
  if(f>=0)
    freq=f;
  else
    throw logic_exception("Invalid Value");  //gestire eccezione invalid value
}
