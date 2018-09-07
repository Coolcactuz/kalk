#include "Induttore.h"

Induttore::Induttore(double i){
    if(i > 0)
        induttanza = i;
    else
        throw logic_exception("Inizializzato con valore negativo");
    try {
        Componente::setImp(impedenza());
    }
    catch(const syntax_exception& se){
        throw ;
    }
}

Induttore::Induttore(std::string s){
  auto pos=s.find('L');
  if(pos==0){
    try {
        induttanza = toDouble(s.substr(1));
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

std::string Induttore::toString() const{
    std::string res= "L"+std::to_string(getInduttanza());
    return res;
}

double Induttore::getInduttanza() const{
    return induttanza;
}

C_cartesiano Induttore::impedenza() const{
    double xl=2*Numero::pi*Componente::freq*(induttanza/1000);
    return C_cartesiano(0,xl);
}
