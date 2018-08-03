//
// Created by luca on 02/08/18.
//

#include "Hierarchy_Handler.h"

Hierarchy_Handler::Hierarchy_Handler(){
    class_operators();
    class_operators.push_back('(');
    class_operators.push_back(')');
}

Hierarchy_Handler::~Hierarchy_Handler(){
    for(auto cit=class_operators.cbegin(); cit!=class_operators.cend();)
        cit=class_operators.erase(cit);
}


void Hierarchy_Handler::add_operator(const char c){
  if(!(is_operator(c))) class_operators.push_back(c);
  else
    throw(0); //gestire eccezione "operatore già presente"
}

void Hierarchy_Handler::remove_operator(const char){
    for (auto cit=class_operators.cbegin(); cit!=class_operators.cend(); ++cit) {
        if (c==*cit) class_operators.erase(cit);
        --cit;
    }
}

bool Hierarchy_Handler::is_operator(const char) const {
    for(auto it=class_operators.begin(); it!=class_operators.end(); ++it){
        if (c==*it) return true;
    }
    return false;
}