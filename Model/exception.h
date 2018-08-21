#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

class exception{
  friend std::ostream& operator<<(std::ostream&, const exception&);
private:
  std::string error;
public:
  exception(std::string s = ""): error(s) {}
};

std::ostream& operator<<(std::ostream& out, const exception& e){
  out<<e.error<<std::endl;
  return out; 
}

#endif
