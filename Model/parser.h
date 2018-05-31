
#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <string>
#include <iostream>

template<class T>
class parser{
private:
  class node{
  public:
    T* obj;
    char op;
    int prec;
    node* left, *right;
    node(T* t=nullptr, char o='\0', int p=0, node* l=nullptr, node* r=nullptr):
      obj(t), op(o), prec(p), left(l), right(r){};
    ~node(){delete left; delete right; delete obj;};

    node* copy(node* p=nullptr){
      if(!p) return 0;
         return new node(p->obj,p->op, copy(p->left), copy(p->right));
    };
  };
  std::string data;
  static std::list<const char> class_operators;

public:
  parser(std::string ="");
  ~parser();

  int set_prec(char) const;
  void add_operator(const char);
  void remove_operator(const char);
  void load_operators();
  bool is_operator(const char) const;
  bool balanced_brackets(std::string ="\0") const;
  node* build_tree(std::string ="\0")const ;
  static node* find_father(node* =nullptr, node* =nullptr) ;
  void print(node* =nullptr, int =0);

};

//
//PARSER
//
//costruttore da NODO, default=nullo
template<class T>
parser<T>::parser(std::string s): data(s){}

//distruttore
template<class T>
parser<T>::~parser(){}

//operatori base
template<class T>
std::list<const char> parser<T>::class_operators;

template<class T>
void parser<T>::load_operators(){
  unsigned int n=8;
  char op[n]={'(', ')', '+', '-', '*', '/', '^', '#'};
  for(unsigned int i=0; i<n; ++i)
    add_operator(op[i]);
  //   std::cout <<"caricato operatore "<< op[i] << std::endl;
  return;
}

//ricerca operatore
template<class T>
bool parser<T>::is_operator(const char c) const {
  for(auto it=class_operators.begin(); it!=class_operators.end(); ++it){
    if (c==*it) return true;
  }
  return false;
}

//aggiungi operatore
template<class T>
void parser<T>::add_operator(const char c){
  if(!(is_operator(c))) class_operators.push_back(c);
  else
    throw(0); //gestire eccezione "operatore già presente"
  return;
}

//rimuovi operatore
template<class T>
void parser<T>::remove_operator(const char c){
  for (auto cit=class_operators.cbegin(); cit!=class_operators.cend(); ++cit) {
    if (c==*cit) class_operators.erase(cit);
    --cit;
  }
  return;
}

//controllo parentesi bilanciate
template<class T>
bool parser<T>::balanced_brackets(std::string s) const{
  int bracket=0;
  for(auto it=s.begin(); it!=s.end(); ++it){
    if(*it=='(')  bracket++;
    else if (*it==')') bracket--;
    if(bracket<0) return false;
  }
  if(bracket==0) return true;
  return false;
}

//trova nodo padre del nodo wanted, nell'albero (o sub albero) root
template<class T>
typename parser<T>::node* parser<T>::find_father(typename parser<T>::node* wanted,typename parser<T>::node* root) {
  if(!root || !wanted || wanted==root) return nullptr; //l'albero e il nodo figlio devono essere != null
  if(root){
    if((root->left && root->left == wanted) || (root->right && root->right == wanted)) return root;
    node* sub_left=find_father(wanted, root->left);
    if(sub_left) return sub_left;
    node* sub_right=find_father(wanted, root->right);
    if(sub_right) return sub_right;
  }
  return nullptr;
}

//costruzione albero di parsing
template<class T>
typename parser<T>::node* parser<T>::build_tree(std::string s) const {
  if(!balanced_brackets(s)) throw(0); //gestire eccezione parentesi non bilanciate
  if(s.length()==0) throw(0); //gestire eccezione stringa vuota
  std::string tmp= "(";
  tmp=tmp.append(s);
  tmp=tmp.append(")");
  std::cout<<tmp<<std::endl;
  auto it=tmp.begin();
  node* start = nullptr;
  node* current = start;

  while(it!=tmp.end()){
    std::cout << "valuto: "<<*it<<std::endl;
    if(!is_operator(*it)){
      auto aux = it;
      while(!is_operator(*aux) && aux!=tmp.end())
        aux++;
      std::string spoil_item(it,aux);
      T* obj_p = new T(spoil_item);
      if(!obj_p)
        std::cout << "identify_literal ERROR";
      current->right=new node();
      current=current->right;
      current->op = 0;
      current->prec = set_prec(*it);
      current->obj = obj_p;
      it = aux;
    }
    else{
      switch (*it) {
        case '(': {
          node* item=new node();
          item->op=*it;
          item->prec = set_prec(*it);
          if(!start && !current){
            start=item;
            current=item;
          }
          else{
            current->right=item;
            current=current->right;
          }
        }
        break;

        case ')':{
          while(current->prec != set_prec(*it)){
            current=find_father(current, start);
            std::cout<<"up"<<std::endl;
          }
          node*father=find_father(current,start);
          node* aux=current;
          if(father){
            father->right=current->right;
            current=father;
          }
          else{
            current=current->right;
            start=current;
          }
          aux->right=nullptr;
          delete aux;
          std::cout<<"fatto tutto"<<std::endl;
        }
        break;

        default:{
          node* item=new node();
          item->op=*it;
          item->prec=set_prec(*it);
          while(current->prec >= item->prec)
            current=find_father(current,start);
          item->left=current->right;
          current->right=item;
          current=item;
        }
        break;
      }
      it++;
    }
  }
  return start;
}

template<class T>
int parser<T>::set_prec(char c) const{
  if(c=='(' || c==')')
    return 1;
  else if(c=='+' || c=='-')
    return 2;
  else if(c=='*' || c=='/')
    return 4;
  else if(c=='^' || c=='#')
    return 6;
  else
    return 7;
}


template<class T>
void parser<T>::print(node* n, int z){
  if(!n) return;
  if(!n->left && !n->right)
    std::cout<<*(n->obj)<<std::endl;
  else{
    if(n->left){
      std::cout<<"<"<<std::endl;
      print(n->left);
    }
    std::cout<<n->op<<std::endl;
    if(n->right){
      std::cout<<">"<<std::endl;
      print(n->right);
    }
  }
}

#endif
