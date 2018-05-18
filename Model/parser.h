#ifndef PARSER_H
#define PARSER_H

#include <string>



template<class T>
class tree{
private:
  class nodo{
  public:
    T* obj;
    char op;
    nodo *left, *right;
    nodo(const T* o=0, char c=NULL, nodo* l=0, nodo* r=0):
      obj(o), op(c), left(l), right(r){};
    ~nodo(){delete left; delete right; delete obj;};
  };
  nodo* root;
public:
  tree(nodo* r=0): root(r){};
  ~tree(){delete root;};
};


#include <list>

class parser{
private:
  std::string input;
  std::list<char> class_operators;

  bool is_operator(char) const;
  void add_operator(char);
  void remove_operator(char);
  void load_operators(char*);

  virtual void build_tree(std::string) =0;

public:
  parser(std::string ="");
  virtual ~parser() =default;

};

#include "Raz.h"

class parser_raz : public parser{
private:
  tree<Raz>* albero;

  void build_tree(std::string);

public:
  parser_raz(std::string);
  ~parser_raz(){delete albero;};
};

#endif
