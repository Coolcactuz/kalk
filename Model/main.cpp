#include "Raz.h"
#include "C_cartesiano.h"
#include "C_polare.h"

#include "exception.h"
#include "parser.h"

#include "Resistore.h"
#include "Induttore.h"
#include "Condensatore.h"

#include "Circuito.h"
#include "Melodia.h"

using namespace std;

int main() {
  std::string s1,s2;
  std::cin>>s1>>s2;
  Raz* r1= new Raz(s1);
  std::cout<<*r1<<std::endl;
  Raz* r2= new Raz(s2);
  std::cout<<*r2<<std::endl;
  Raz* r3= r1->operator/(r2);
  std::cout<<*r3;

  return 0;
}
