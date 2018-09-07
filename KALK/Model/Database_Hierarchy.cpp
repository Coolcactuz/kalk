//
// Created by luca on 01/08/18.
//

#include "Database_Hierarchy.h"

Database_Hierarchy::Database_Hierarchy() : Hierarchy_Handler(){
    load_operators();
}

void Database_Hierarchy::load_operators() {
  unsigned int n=3;
  char op[n]={'-', '%', '/'};
  for(unsigned int i=0; i<n; ++i)
    add_operator(op[i]);
}

tupla* Database_Hierarchy::create(std::string s) const{
    try{
        if(s=="")
            return new tupla();
        return new tupla(s);
    }
    catch(const syntax_exception& se){
        throw ;
    }
}