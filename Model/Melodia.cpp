#include "Melodia.h"

Melodia::Melodia(Nota* s){
  v.push_back(s);
}
Melodia::Melodia(const Melodia&){}
Melodia::~Melodia(){}

Melodia* Melodia::operator+(const Melodia*) const{}
Melodia* Melodia::operator*(int) const{}

Melodia* Melodia::addNote(){}
Melodia* Melodia::removeNote(){}
void Melodia::increaseTono(){}
void Melodia::increaseTiming(){}
void Melodia::clona(){}
void Melodia::stampa(){}
