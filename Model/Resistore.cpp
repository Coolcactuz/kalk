#include "Resistore.h"

Resistore::Resistore(double r){

  if(r > 0)
    resistenza = r;
  else
    throw logic_exception("Inizializzato con valore negativo");

  Componente::setImp(impedenza());
}

Resistore::Resistore(std::string s):Componente(){
  auto pos=s.find('R');
  if(pos==0){
    resistenza=std::stod(s.substr(1));
    Componente::setImp(impedenza());
  }
  else
    throw syntax_exception("La stringa non inizia con il carattere R"); //gestire eccezione errore di sintassi
}

Resistore::~Resistore(){}

C_cartesiano Resistore::impedenza() const{
    return C_cartesiano(resistenza);
}
