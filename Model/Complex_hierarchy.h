#ifndef KALK_COMPLEX_HIERARCHY_H
#define KALK_COMPLEX_HIERARCHY_H

#include "C_cartesiano.h"
#include "C_polare.h"

class Complex_hierarchy{
public:
    static Complesso* itemID(std::string);
};
#endif


Complesso* Complex_hierarchy::itemID(std::string s){
  //auto pos=s.find('<');
  if(s.find('<')!= -1)
    return new C_polare(s);
  return new C_cartesiano(s);
}
