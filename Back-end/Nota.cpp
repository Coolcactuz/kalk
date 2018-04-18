#include "Nota.h"

Nota(int n, std::string tune, Raz timing): note(n), tono(tune), tempo(timing){}
Nota(const Nota&);

Nota* operator+ (const Raz&){} //aumenta tempo

}

Nota* operator- (const Raz&){ //diminuisci tempo

}

Nota* operator++ (){ //aumenta tonalità

}

Nota* operator-- (){ //diminuisci tonalità

}

int getNote() const{
  return note;
}
std::string getTono() const{
  return tono;
}
Raz getTempo() const{
  return tempo;
}

void stampa(std::ostream&)const{
  
}
