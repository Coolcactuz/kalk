#include "parser.h"
#include <cmath>

parser::parser(std::string s): input(s){};

bool parser::is_operator(char c) const{
  for(auto it=this->class_operators.cbegin(); it!=this->class_operators.cend(); ++it){
    if(c==*it)
      return true;
  }
  return false;
}

void parser::add_operator(char c){
  if(!is_operator(c))
    this->class_operators.push_back(c);
  else
    throw(0); //gestire eccezione operatore già presente
  return;
}

void parser::remove_operator(char c){
  if(is_operator(c)){
    for(auto it=this->class_operators.cbegin(); it!=this->class_operators.cend(); ++it){
      if(c==*it) class_operators.erase(it);
    }
  }
  else
    throw(0); //gestire eccezione operatore non presente
  return;
}

parser_raz::parser_raz(std::string s):parser(s){}

void parser_raz::build_tree(std::string s){

}
