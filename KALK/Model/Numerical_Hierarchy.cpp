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
}

Complesso* Numerical_Hierarchy::create_complex(std::string s)const {
    try{
        if(s=="")
            return new C_cartesiano();
        auto pos=s.find('<');
        if(pos==std::string::npos)
            return new C_cartesiano(s);
        return new C_polare(s);
    }
    catch (const syntax_exception& se){
        throw ;
    }
}

Raz* Numerical_Hierarchy::create(std::string s) const{
    try{
        if(s=="")
            return new Raz();
        return new Raz(s);
    }
    catch (const syntax_exception& se){
        throw;
    }
}