#include"parser.h"
#include"C_polare.h"
#include<string>

int main(){
  // std::string input;
  // std::cin>>input;
  // parser<C_polare> a(input);
  // a.load_operators();
  //   std::cout<<"harambiani"<<std::endl;
  // a.print(a.build_tree(input));
  //


  Complesso* a=new C_cartesiano(2,2);
  Complesso* b=new C_polare(2,45);
  Complesso* c=dynamic_cast<Complesso*>(a->operator/(b));
  //Complesso* c=new C_cartesiano(1,1);
  //Complesso* e=dynamic_cast<Complesso*>((b->operator+(a))->operator-(c));
  std::cout<<*c<<std::endl;
  std::cout<<"harambeee"<<std::endl;


  return 0;
}
