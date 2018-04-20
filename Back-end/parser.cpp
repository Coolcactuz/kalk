#include "parser.h"

//inizializza qui le liste statiche

//------NODE--------

//distruttore di node

//prende un puntatore a node e libera tutta la memoria occupata dai campi
//object dell'albero
void parser::node::destroy(parser::node* p){
  if(p){
    destroy(p->left);
    destroy(p->right);

    delete object;
  }
}

parser::node::~node(){
  if(left)
    delete left;
  if(right)
    delete right;

  delete object;
}


//assegnazione di node

//prende un puntatore a node, e crea un albero che è copia profonda di node
parser::node* copy(parser::node* p){
  if(!p)
    return 0;

  return new node(p->is_Operator, p->op, new Dato(*(p->object)), copy(p->left),
             copy(p->right));
}

parser::node& parser::node::operator =(const parser::node& n) {
  if(this != &n){
    destroy(this);
    this = copy(&n);
  }
  return this;
}


//costruttore di copia di node

parser::node::node(const parser::node& n){
  this = copy(&n);
}

//-------------------------------

//---------PARSER----------------

void add_operator(char c) const{
  if(!find(c, operator_list))
    operator_list.push_back(c);
}

void add_parser_pointer(Dato* (*p) (string)) const{
  if(!find(p, p_list))
    p_list.push_back(p);
}


parser::node* parse(std::string s) const{
  std::string tmp = "(";
  tmp.append(s);
  tmp.append(")");

  std::string::const_iterator it = tmp.begin();

  while (it != tmp.end()) {
    if(find(*it, operator_list)){
      switch (*it) {
        case '(':
          
        break;
        case ')':
        break;
        default:
        break;
      }
    }
    else{

    }
  }
}
