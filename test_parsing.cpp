#include <iostream>
#include <string>
using namespace std;

struct nodo{

  bool isOperator;
  char op;
  int value;
  nodo* left;
  nodo* right;

  nodo(bool io = false, char o = '\0', int v = 0, nodo* l = 0, nodo* r = 0):
  isOperator(io), op(o), value(v), left(l), right(r){
    if(isOperator && op == '\0')
        op = '+';
  }
};

struct parse_tree{

  nodo* start;

  parse_tree(nodo* s = 0): start(s) {}

};

void stampa(nodo* root){

  if(root){

    if(root->isOperator)
      cout << root->op;
    else
      cout << root->value;

    if(root->left){
      cout << "(";
      stampa(root->left);
      cout << ",";
      stampa(root->right);
      cout << ")";
    }

  }

}

nodo* find_father(nodo* tree, nodo* child){

  //trova il padre di child nell'albero tree;
  //child deve appartenere a tree

  if(!tree || !child)
    return 0;

  nodo* lt = find_father(tree->left, child);

  if(lt)
    return lt;

  nodo* rt = find_father(tree->right, child);

  if(rt)
    return rt;

  if(tree->left == child || tree->right == child)
    return tree;

  return 0;
}

parse_tree parse(string s = ""){

  string tmp = "(";

  tmp.append(s);
  tmp.append(")");

  cout << tmp << endl;

  parse_tree pt(new nodo());
  nodo* current = pt.start;

  /*current è sempre il nodo che sto prendendo in considerazione*/

  for(int i = 0; i < tmp.size(); i++){

    cout << tmp[i] << endl;

    switch(tmp[i]){

      case '(':   /*aggiungo il figlio sinistro al nodo corrente: esso diventa
                  il nuovo nodo corrente*/

          current->left = new nodo;
          current = current->left;

        break;

      case ')':  /*mi sposto al nodo padre*/

        current = find_father(pt.start, current);
        break;

      case '*':
      case '-':
      case '/':
      case '+':   /*setto il giusto operatore al nodo corrente e mi sposto sul
                  suo figlio destro*/

        current->isOperator = true;
        current->op = tmp[i];
        current->right = new nodo;
        current = current->right;

        break;
      default:  /*setto il valore numerico del nodo corrente e mi sposto sul
                padre*/

        current->value = tmp[i] - '0';
        current = find_father(pt.start, current);

        break;
    }
  }

  return pt;
}

int main(){

  string s;

  cin >> s;

  stampa(parse(s).start);

  return 0;
}
