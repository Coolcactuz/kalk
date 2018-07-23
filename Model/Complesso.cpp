//
// Created by luca on 18/12/17.
//

#include "Complesso.h"
//
Complesso* Complesso::create(std::string s){
  return Complex_hierarchy::itemID(s);
}

std::ostream& operator<< (std::ostream& os, const Complesso& c){
    c.stampa(os);
    return os;
}
