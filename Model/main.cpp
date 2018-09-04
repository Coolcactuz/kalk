#include"parser.h"

#include <typeinfo>

int main(){
  std::string input;
  std::cin>>input;
  Componente* tmp=new Componente();
  tmp->setFreq(50);
  tmp->setVolt(220);
  Dato *result= nullptr;
  try {
      parser<Componente> controller(input, tmp);
      //controller.print(controller.getStart());
      delete tmp;
      result = parser<Componente>::resolve(controller.getStart());
      std::cout<<result->toString()<<std::endl;
  }
  catch (const syntax_exception& se){
      delete tmp;
      se.print();
  }

  catch (const logic_exception& le){
      delete tmp;
      le.print();
  }
  std::cout<<"hello"<<std::endl;
  return 0;


}
