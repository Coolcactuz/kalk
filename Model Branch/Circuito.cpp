#include "Circuito.h"


Circuito::Circuito(std::string s): circuit(parser<Componente>(s)){}



Circuito Circuito::operator=(const Circuito& c){
    if(!(circuit==c.circuit)){
        delete this->circuit.getStart();
        delete this->circuit.getHandler();
        circuit = c.circuit;
    }
    return *this;
}

