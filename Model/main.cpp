#include"parser.h"

int main(){
  std::string input;
  std::cin>>input;
  Complesso* tmp=new C_cartesiano();
  parser<Complesso> controller(input, tmp);
  controller.print(controller.getStart());
  Dato* result=parser<Complesso>::resolve(controller.getStart());
  delete tmp;
  std::cout<<result->toString()<<std::endl;
  std::cout<<"hello"<<std::endl;
  return 0;
}
