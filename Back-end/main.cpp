#include <iostream>
#include "Raz.h"
//#include "parser.h"
#include "C_cartesiano.h"

using namespace std;

int main() {
  Dato* a= new Raz(1,2);
  Dato* b= new C_cartesiano(1,2);
  Dato* c= new C_polare(1,2);

    return 0;
}
