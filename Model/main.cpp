#include"parser.h"
#include"Raz.h"
#include<string>

int main(){
  std::string input;
  std::cin>>input;
  parser<Raz> a(input);
  a.load_operators();
    std::cout<<"harambe"<<std::endl;
  a.print(a.build_tree(input));
  return 0;
}
