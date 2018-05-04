#include "Nota.h"

#include<vector>

class Melodia{
private:
  std::vector<const Nota*> v;
public:
  Melodia(Nota* =0);
  Melodia(const Melodia&);
  ~Melodia();

  Melodia* operator+(const Melodia*) const;
  Melodia* operator*(int) const;

  Melodia* addNote();
  Melodia* removeNote();
  void increaseTono();
  void increaseTiming();
  void clona();
  void stampa();
};
