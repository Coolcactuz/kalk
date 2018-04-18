#ifndef PARSER_H
#define PARSER_H

#include "Dato.h"
#include <list>

class parser{
private:

  class node{
  private:
    bool isOperator;
    char op;
    Dato* obj;
  public:
    //di default inserisco il dato vuoto
    node(bool io = false, char o = '\0', Dato* ob = 0)
  };

  static std::list <Dato* (*) (string)>  p_list;
  static std::list <char> operators;
public:
  void add_operator(const char&) const;
  void add_parser_pointer(const Dato* (*) (string) &) const;


};

#endif
