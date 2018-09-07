#include "Resistore.h"

Resistore::Resistore(double r){
  if(r >= 0)
    resistenza = r;
  else
    throw logic_exception("Inizializzato con valore negativo");
  try {
    Componente::setImp(impedenza());
  }
  catch (const syntax_exception& se){
    throw;
  }
}

Resistore::Resistore(std::string s){
  auto pos=s.find('R');
  if(pos==0){
    try {
      resistenza=toDouble(s.substr(1));
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

std::string Resistore::toString() const{
    std::string res= "R"+std::to_string(getResistenza());
  return res;
}

double Resistore::getResistenza() const{
  return resistenza;
}

C_cartesiano Resistore::impedenza() const{
    return C_cartesiano(resistenza);
}
