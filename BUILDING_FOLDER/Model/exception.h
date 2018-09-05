#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include <typeinfo>

class exception{
public:
  std::string getErrorMessage() const {
    return errorMessage;
  }
  std::string errorMessage;
  exception(std::string s): errorMessage(s){}
};

class syntax_exception: public exception{
public:
  syntax_exception(std::string s): exception(s) {}
};

class logic_exception: public exception{
public:
  logic_exception(std::string s): exception(s) {}
};

#endif
