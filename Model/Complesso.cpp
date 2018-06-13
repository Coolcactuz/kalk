//
// Created by luca on 18/12/17.
//

#include "Complesso.h"
//
// Complesso* Complesso::create(std::string s){
//   if(s.find('<')!= -1){
//     return new C_polare(s);
//   }
//   return new C_cartesiano(s);
// }

std::ostream& operator<< (std::ostream& os, const Complesso& c){
    //c.stampa(os);
    return os;
}
