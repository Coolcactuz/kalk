//
// Created by luca on 01/08/18.
//

#include "Numerical_Hierarchy.h"

Numerical_Hierarchy::Numerical_Hierarchy() : Hierarchy_Handler(){
    load_operators();
}

void Numerical_Hierarchy::load_operators() {
    unsigned int n=5;
    char op[n]={'+', '-', '*', '/', '^'};
    for(unsigned int i=0; i<n; ++i)
        add_operator(op[i]);
    delete[] op;
}

Complesso* Numerical_Hierarchy::create_complex(std::string s){
    auto pos=s.find('<');
    if(pos==-1)
        return new C_cartesiano(s);
    return new C_polare(s);
}

Raz* Numerical_Hierarchy::create_rational(std::string s){
    return new Raz(s);
}