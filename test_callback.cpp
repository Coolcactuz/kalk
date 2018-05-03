#include <iostream>
#include <string>
#include <list>
using namespace std;

class A{
public:
  static void f (string s) { cout << "ciao";}
  static void g (string s) {}
};

int main(){

  void (*p)(string) = &A::f;

  list< void (*) (string)> l;

  l.push_back(p);

  list<void (*) (string)>::iterator i = l.begin();

  (*i)("n");

  return 0;
}
