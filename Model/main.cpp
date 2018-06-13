#include"parser.h"
#include"C_polare.h"
#include<string>

int main(){
  std::string input;
  std::cin>>input;
  parser<C_polare> a(input);
  a.load_operators();
    std::cout<<"harambiani"<<std::endl;
  a.print(a.build_tree(input));


  //
  // C_cartesiano* a=new C_cartesiano(2,2);
  // C_cartesiano* b=new C_cartesiano(2,-2);
  // C_cartesiano* c= a->operator+(b);
  // std::cout<<*c<<std::endl;
  // std::cout<<"harambeee"<<std::endl;


  return 0;
}
