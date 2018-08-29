//
// Created by luca on 10/01/18.
//

#include "Induttore.h"

Induttore::Induttore(double i){
    if(i > 0)
        induttanza = i;
    else
        throw logic_exception("Inizializzato con valore negativo");
    Componente::setImp(impedenza());
}

Induttore::Induttore(std::string s){
  auto pos=s.find('L');
  if(pos==0){
    induttanza=std::stod(s.substr(1));
    Componente::setImp(impedenza());
  }
  else
      throw syntax_exception("La stringa non inizia con il carattere L"); //gestire eccezione errore di sintassi
}

Induttore::Induttore():induttanza(0){}


bool Induttore::operator== (const Dato& d) const {
    try {
        auto aux = dynamic_cast<const Induttore &>(d);
        return induttanza == aux.induttanza;
    }
    catch (std::bad_cast &error){
        return false;
    }
}
//
//Induttore& Induttore::operator= (const Dato& d) {
//    try {
//        auto aux = dynamic_cast<const Induttore &>(d);
//        induttanza = aux.induttanza;
//        setImp(induttanza);
//        return *this;
//    }
//    catch (const std::bad_cast &error){
//        std::cout << "tipi incompatibili" << std::endl;
//    }
//}

C_cartesiano Induttore::impedenza() const{
    double xl=2*Numero::pi*Componente::freq*induttanza;
    return C_cartesiano(0,xl);
}
