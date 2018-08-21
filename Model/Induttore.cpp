#include "Induttore.h"

Induttore::Induttore(double i){

  if(i > 0)
    induttanza = i;
  else
    throw logic_exception("Inizializzato con valore negativo");

  Componente::setImp(impedenza());
}

Induttore::Induttore(std::string s):Componente(){
  auto pos=s.find('L');
  if(pos==0){
    induttanza=std::stod(s.substr(1));
    Componente::setImp(impedenza());
  }
  else
    throw syntax_exception("La stringa non inizia con il carattere L"); //gestire eccezione errore di sintassi
}

Induttore::~Induttore(){}

C_cartesiano Induttore::impedenza() const{
    double xl=2*Numero::pi*Circuito::freq*induttanza;
    return C_cartesiano(0,xl);
}
