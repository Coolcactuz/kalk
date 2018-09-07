#include "Condensatore.h"


Condensatore::Condensatore(double c){
    if(c > 0)
        capacita = c;
    else
        throw logic_exception("Inizializzato con valore negativo");
    try {
        Componente::setImp(impedenza());
    }
    catch (const syntax_exception& se){
        throw;
    }
}
Condensatore::Condensatore(std::string s){
  auto pos=s.find('C');
  if(pos==0){
      try {
          capacita=toDouble(s.substr(1));
          Componente::setImp(impedenza());
      }
      catch (const syntax_exception& se){
          throw;
      }
      catch (const std::exception& ex){
          throw syntax_exception("errore di sintassi");
      }
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

std::string Condensatore::toString() const {
    std::string res="C"+std::to_string(getCapacita());
    return res;
}

double Condensatore::getCapacita() const{
    return capacita;
}

C_cartesiano Condensatore::impedenza() const{
    double xc=1/(2*(Numero::pi)*(Componente::freq)*(capacita/1000));
    return C_cartesiano(0,-xc);
}
