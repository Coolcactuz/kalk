
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
  if(!is_operator(c)) class_operators.push_back(c);
  else
    throw logic_exception("Operatore già presente"); //gestire eccezione "operatore già presente"
}

void Hierarchy_Handler::remove_operator(const char c){
    for (auto cit=class_operators.cbegin(); cit!=class_operators.cend(); ++cit) {
        if (c==*cit) class_operators.erase(cit);
        --cit;
    }
}

bool Hierarchy_Handler::is_operator(const char c) const {
    for(auto it=class_operators.begin(); it!=class_operators.end(); ++it){
        if (c==*it) return true;
    }
    return false;
}
