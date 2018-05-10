#include "Nota.h"

Nota::Nota(int n, std::string tune, Raz timing): note(n), tono(tune), tempo(timing){}
Nota::Nota(const Nota&){}

Nota* Nota::operator+ (const Raz&){} //aumenta tempo

Nota* Nota::operator- (const Raz&){ //diminuisci tempo

}

Nota* Nota::operator++ (){ //aumenta tonalità

}

Nota* Nota::operator-- (){ //diminuisci tonalità

}

int Nota::getNote() const{
  return note;
}
std::string Nota::getTono() const{
  return tono;
}
Raz Nota::getTempo() const{
  return tempo;
}

void Nota::stampa(std::ostream&)const{

}
