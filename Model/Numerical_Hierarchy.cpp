//
// Created by luca on 01/08/18.
//

#include "Numerical_Hierarchy.h"

Complesso* Numerical_Hierarchy::create_complex(std::string s){
    auto pos=s.find('<');
    if(pos==-1)
        return new C_cartesiano(s);
    return new C_polare(s);
}

Raz* Numerical_Hierarchy::create_rational(std::string s){
    return new Raz(s);
}