//
// Created by luca on 03/01/18.
//

#include "Resistore.h"

Resistore::Resistore(double r){
  if(r > 0)
    resistenza = r;
  else
    throw logic_exception("Inizializzato con valore negativo");
  Componente::setImp(impedenza());
}

Resistore::Resistore(std::string s){
  auto pos=s.find('R');
  if(pos==0){
    resistenza=std::stod(s.substr(1));
    Componente::setImp(impedenza());
  }
  else
    throw syntax_exception("La stringa non inizia con il carattere R"); //gestire eccezione errore di sintassi
}

Resistore::Resistore():resistenza(0){}

bool Resistore::operator== (const Dato& d) const{
  try{
    auto aux= dynamic_cast<const Resistore&>(d);
    return resistenza==aux.resistenza;
  }
  catch(const std::bad_cast& error){
    return false;
  }
}

//Resistore& Resistore::operator= (const Dato& d) {
//  try {
//    auto aux = dynamic_cast<const Resistore &>(d);
//    resistenza = aux.resistenza;
//    setImp(resistenza);
//    return *this;
//  }
//  catch (const std::bad_cast &error){
//    std::cout << "tipi incompatibili" << std::endl;
//  }
//}

C_cartesiano Resistore::impedenza() const{
    return C_cartesiano(resistenza);
}
