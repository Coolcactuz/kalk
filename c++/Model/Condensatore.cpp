//
// Created by luca on 11/01/18.
//

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

Condensatore::Condensatore():capacita(0){};

bool Condensatore::operator== (const Dato& d) const{
    try {
        auto aux = dynamic_cast<const Condensatore &>(d);
        return capacita == aux.capacita;
    }
    catch(const std::bad_cast& error) {
        return false;
    }
}
//
//Condensatore& Condensatore::operator= (const Dato& d){
//    try{
//        auto aux= dynamic_cast<const Condensatore&>(d);
//        capacita = aux.capacita;
//        setImp(capacita);
//        return *this;
//    }
//    catch(const std::bad_cast& error){
//        std::cout<<"tipi incompatibili"<<std::endl;
//    }
//}

std::string Condensatore::toString() const {
    std::string res="C"+std::to_string(getCapacita());
    return res;
}

double Condensatore::getCapacita() const{
    return capacita;
}

C_cartesiano Condensatore::impedenza() const{
    double xc=1/(2*(Numero::pi)*(Componente::freq)*capacita);
    return C_cartesiano(0,-xc);
}
