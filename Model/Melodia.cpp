#include "Melodia.h"

Melodia(Nota* s){
  v.push_back(s)
};
Melodia(Melodia&);
~Melodia();

Melodia* operator+(const Melodia*) const;
Melodia* operator*(int) const;

Melodia* addNote();
Melodia* removeNote();
void increaseTono();
void increaseTiming();
void clona();
void stampa();
