//
// Created by luca on 03/01/18.
//

#include "Componente.h"

double Componente::freq=0;
double Componente::volt=0;

Componente::Componente(C_cartesiano& c){
    try{
        setImp(c);
    }
    catch(const exception& error){
        throw;
    }
}

Componente::Componente(std::string s) {
    try {
        auto pos = s.find('Z');
        if (pos == 0)
            setImp(std::stod(s.substr(1)));
        else
            throw syntax_exception("La stringa non inizia con il carattere Z");
    }
    catch(const exception& error){
        throw;
    }
}

Componente::Componente(): imp(0){}

Componente* Componente::operator+ (const Componente* c) const{
    C_cartesiano* comp1= new C_cartesiano(impedenza());
    C_cartesiano* comp2= new C_cartesiano(c->impedenza());
    C_cartesiano* serie= comp1->operator+(comp2);
    delete comp1;
    delete comp2;
    Componente* result= new Componente(*serie);
    delete serie;
    return result;
}

Componente* Componente::operator/ (const Componente* c) const {
    C_cartesiano* comp1= new C_cartesiano(impedenza());
    C_cartesiano* comp2= new C_cartesiano(c->impedenza());

    C_cartesiano* num= comp1->operator*(comp2);
    C_cartesiano* den= comp1->operator+(comp2);
    delete comp1;
    delete comp2;

    C_cartesiano* parallelo= num->operator/(den);
    delete num;
    delete den;

    Componente* result=new Componente(*parallelo);
    delete parallelo;
    return result;
}

bool Componente::operator== (const Dato& d) const{
   try{
       auto aux= dynamic_cast<const Componente&>(d);
       return imp==aux.imp;
   }
   catch(const std::bad_cast& error){
       return false;
   }
}
//
//Componente& Componente::operator= (const Dato& d){
//    try{
//        auto aux= dynamic_cast<const Componente&>(d);
//        setImp(aux.impedenza());
//        return *this;
//    }
//    catch (const std::bad_cast &error){
//        std::cout << "tipi incompatibili" << std::endl;
//    }
//}

Componente* Componente::solve_operation(const Dato* a, const Dato* b, char o){
    auto l=dynamic_cast<const Componente*>(a);
    auto r=dynamic_cast<const Componente*>(b);
    if(l && r){
        switch(o) {
            case '+':
              return l->operator+(r);
            break;

            case '/':
              return l->operator/(r);
            break;

            default:
                throw syntax_exception("Operatore inesistente");
            break;

        }
    }
    else
        throw logic_exception("tipo di dati errato");
}

std::string Componente::toString() const {
    std::string res="Z"+(impedenza()).toString();
    return res;
}

C_cartesiano Componente::impedenza() const{
  return imp;
}

double Componente::getVolt(){
    return volt;
}

double Componente::getFreq(){
    return freq;
}

void Componente::setImp(const C_cartesiano& c ){
  if(c.getReale()<0)
      throw syntax_exception("il valore reale dell'impedenza non può essere negativo");
  else
    imp=c;
}

void Componente::setVolt(double v){
    if(v>0)
        volt=v;
    else
      throw syntax_exception("parametro non corretto");
}

void Componente::setFreq(double f) {
    if (f > 0)
        freq = f;
    else
        throw syntax_exception("parametro non corretto");
}
