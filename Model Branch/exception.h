#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

class exception{
public:
  virtual void print() const =0;
  std::string errorMessage;
  exception(std::string s): errorMessage(s){}
};

class syntax_exception: public exception{
public:
  syntax_exception(std::string s): exception(s) {}
  virtual void print() const {  std::cout << exception::errorMessage
    << std::endl;}
};

class logic_exception: public exception{
public:
  logic_exception(std::string s): exception(s) {}
  virtual void print() const {  std::cout << exception::errorMessage
    << std::endl;}
};

#endif
