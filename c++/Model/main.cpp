#include"parser.h"

#include <typeinfo>

int main(){
  std::string input;
  std::cin>>input;
  Dato* tmp=new C_cartesiano();
//  Componente::setFreq(50);
//  Componente::setVolt(220);
  Dato *result= nullptr;
  try {
      parser<Complesso> controller(input, tmp);
      delete tmp;
      result = parser<Complesso>::resolve(controller.getStart());
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
  return 0;
}
