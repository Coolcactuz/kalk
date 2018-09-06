#include"parser.h"

#include <typeinfo>

int main(){
    std::string test="-2";
    double prova=std::stod(test);
    std::cout<<prova<<std::endl;
  std::string input;
  std::cin>>input;
  Dato* tmp=new Raz();
//  Componente::setFreq(50);
//  Componente::setVolt(220);
  Dato *result= nullptr;
  try {
      parser<Raz> controller(input, tmp);
      delete tmp;
      result = parser<Raz>::resolve(controller.getStart());
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
