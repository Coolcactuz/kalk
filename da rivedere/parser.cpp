#include "parser.h"

//inizializza qui le liste statiche

parser::operator_list = std::list<const char&>({'(', ')', '+', '-', '*', '/',
'^', '#'});

parser::p_list = std::list<const Dato* (*) (string)&>({});

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
parser::node* parser::node::copy(parser::node* p){
  if(!p)
    return 0;

  return new node(p->is_Operator, p->op, new Dato(*(p->object)), copy(p->left),
             copy(p->right));
}

parser::node& parser::node::operator =(const parser::node& n) {
  if(this != &n){
    destroy(this);
    delete this;
    this = copy(&n);
  }
  return *this;
}


//costruttore di copia di node

parser::node::node(const parser::node& n){
  this = copy(&n);
}

//-------------------------------

//---------PARSER----------------

void parser::add_operator(char c){
  if(!find(c, operator_list))
    operator_list.push_back(c);
}

void parser::add_parser_pointer(Dato* (*p) (string)){
  if(!find(p, p_list))
    p_list.push_back(p);
}

parser::node* parser::find_father(parser::node* tree, parser::node* child){

  //trova il padre di child nell'albero tree;
  //child deve appartenere a tree

  if(!tree || !child)
    return 0;

  node* lt = find_father(tree->left, child);

  if(lt)
    return lt;

  node* rt = find_father(tree->right, child);

  if(rt)
    return rt;

  if(tree->left == child || tree->right == child)
    return tree;

  return 0;
}

Dato* parser::identify_literal(std::string::const_iterator begin,
  std::string::const_iterator end){

    std::string sub_string(begin, end);
    Dato* res = 0;

    for(std::list::const_iterator it = p_list.begin(); it != p_list.end() &&
    !res; it++)
      res = (*(*it))(sub_string);

    return res;
  }

parser::node* parser::parse(std::string s) const{

  std::string tmp = "(";
  tmp.append(s);
  tmp.append(")");

  std::string::const_iterator it = tmp.begin();

  node* start = new node();
  node* current = start;

  while (it != tmp.end()) {

    if(find(*it, operator_list)){ //il carattere che sto analizzando è una
                                  //delle due parentesi o un operatore

      switch (*it) {
        case '(':   /*aggiungo il figlio sinistro al node corrente: esso diventa
                    il nuovo node corrente*/

          current->left = new node();
          current = current->left;
        break;

        case ')':   //mi sposto al node padre

          current = find_father(start, current);
        break;

        default:    /*setto il giusto operatore al node corrente e mi sposto sul
                    suo figlio destro*/
          current->is_Operator = true;
          current->op = *it;
          current->right = new node();
          current = current->right;
        break;
      }

      it++;
    }
    else{ //il carattere che sto analizzando è il primo carattere del litterale
          //di qualche tipo di dato

          std::string::const_iterator aux = it;

          while(!find(*aux, operator_list))
            aux++;

          //aux ora è il primo operatore dopo il litterale

          Dato* obj_p = identify_literal(it, aux);

          //inserire eccezione se nessun parser riesce a restituire un
          //puntatore non nullo
          if(!obj_p)
            cout << "identify_literal ERROR"

          //il puntatore polimorfo al dato è stato creato, lo memorizzo nel
          //node e mi sposto sul padre

          current->is_Operator = false;
          current->op = '\0';
          current->object = obj_p;

          current = find_father(start, current);

          it = aux;
    }
  }

  return start;
}
