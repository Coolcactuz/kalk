
#include "Condensatore.h"

Condensatore::Condensatore(double c){

  if(c > 0)
    capacita = c;
  else
    throw logic_exception("Inizializzato con valore negativo");

  Componente::setImp(impedenza());
}

Condensatore::Condensatore(std::string s){
  auto pos=s.find('C');
  if(pos==0){
    capacita=std::stod(s.substr(1));
    Componente::setImp(impedenza());
  }
  else
    throw syntax_exception("La stringa non inizia con il carattere C");
}

Condensatore::~Condensatore(){}

C_cartesiano Condensatore::impedenza() const{
    double xc=1/(2*(Numero::pi)*(Circuito::freq)*capacita);
    return C_cartesiano(0,-xc);
}
