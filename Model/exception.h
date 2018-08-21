#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

class exception{

private:
  std::string error;

public:
  exception(std::string s = ""): error(s) {}
  virtual void stampa() const{ std::cout<<error<<std::endl;}
};

class logic_exception: public exception{
public:
  void stampa() const{
    std::cout<<"LOGIC EXCEPTION: ";
    exception::stampa();
  }
};

class syntax_exception: public exception{
public:
  void stampa() const{
    std::cout<<"SYNTAX EXCEPTION: ";
    exception::stampa();
  }
};

#endif
