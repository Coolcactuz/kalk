#ifndef PARSER_H
#define PARSER_H

#include "Dato.h"
#include <list>
#include <string>

class parser{
private:

  class node{

  private:
    static node* copy(node*);
    static void destroy(node*);

  public:

    bool is_Operator;
    char op;
    Dato* object;
    node* left;
    node* right;

    //di default inserisco il dato vuoto in un node singolo
    node(bool isop = false, char o = '\0', Dato* obj = 0, node* l = 0,
    node* r = 0): is_Operator(isop), op(o), object(obj), left(l), right(r) {}

    //node ha un campo puntatore, regola dei tre
    //distruttore
    ~node();

    //assegnazione
    node& operator=(const node&);

    //costruttore di copia
    node(const node&);
  };

  template <class T>
  bool find(T item, std::list l){
    bool res = false;
    for(std::list<T>::const_iterator it = l.begin(); it != l.end(); it++){
      if(*it == item)
        res = true;
    }
    return res;
  }

  static std::list <Dato* (*) (string)>  p_list;
  static std::list <char> operator_list;

public:

  void add_operator(char) const;
  void add_parser_pointer(Dato* (*) (string)) const;

  node* parse(std::string) const;
};

#endif
