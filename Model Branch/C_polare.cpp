//
// Created by luca on 18/12/17.
//

#include "C_polare.h"
#include <cmath>
//#include "C_cartesiano.h"

C_polare::C_polare():modulo(0),fase(0){};

C_polare::C_polare(double m, double f) {
    if(m<0) logic_exception("Modulo negativo");    //GESTIRE ECCEZIONE
    else if(m==0){
      modulo=0;
      fase=0;
    }
    else{   //<----- suppongo ci vadano le parentesi
        modulo=m;
        while(f>=360 || f<0){
          f=((f>=360)?(f-360):(360+f));
        }
        fase=f;
    }
}

//C_polare::C_polare(const C_polare& c):modulo(c.modulo),fase(c.fase){};

C_polare::C_polare(std::string s){
  auto pos=s.find('<');
  std::string::size_type size=0;
  modulo=0;
  fase=0;
  if(pos==-1)
    modulo=std::stod(s);
  else if(pos!=-1 && pos!=s.length()-1){
    modulo=std::stod(s,&size);
    if(modulo==0)
      fase=0;
    else
      fase=(std::stod(s.substr(size+1)));
  }
  else
      throw syntax_exception("Invalid value"); //gestire eccezione syntax error
}

C_polare* C_polare::operator+ (const Numero* n)const{
    if(dynamic_cast<const C_cartesiano*>(n)) {
        const C_cartesiano* aux = static_cast<const C_cartesiano*>(this->converti());
        const C_cartesiano* cc= static_cast<const C_cartesiano*>(n);
        C_cartesiano* somma= aux->operator+(cc);
        delete aux;
        C_polare* somma_polare= static_cast<C_polare*>(somma->converti());
        delete somma;
        return somma_polare;
    }
    else if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        const C_cartesiano* supp= static_cast<const C_cartesiano*>(cp->converti());
        delete cp;
        return this->operator+(supp);
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

C_polare* C_polare::operator- (const Numero* n)const{
    if(dynamic_cast<const C_cartesiano*>(n)) {
        const C_cartesiano* aux = static_cast<const C_cartesiano*>(this->converti());
        const C_cartesiano* cc= static_cast<const C_cartesiano*>(n);
        C_cartesiano* diff= aux->operator-(cc);
        delete aux;
        C_polare* diff_polare= static_cast<C_polare*>(diff->converti());
        delete diff;
        return diff_polare;
    }
    else if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        const C_cartesiano* supp= static_cast<const C_cartesiano*>(cp->converti());
        delete cp;
        return this->operator-(supp);
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}
C_polare* C_polare::operator* (const Numero* n)const{
    if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        double m=modulo*cp->modulo;
        double f=rad_to_deg(atan(deg_to_rad(fase))+atan(deg_to_rad(cp->fase)));
        return new C_polare(m,f);
    }
    else if(dynamic_cast<const C_cartesiano*>(n)){
        const C_cartesiano* aux= static_cast<const C_cartesiano*>(n);
        const C_polare* cp= static_cast<const C_polare*>(aux->converti());
        delete aux;
        return this->operator*(cp);
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

C_polare* C_polare::operator/ (const Numero* n)const{
    if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        double m=modulo/cp->modulo;
        double f=fase-cp->fase;
        return new C_polare(m,f);
    }
    else if(dynamic_cast<const C_cartesiano*>(n)){
        const C_cartesiano* aux= static_cast<const C_cartesiano*>(n);
        const C_polare* cp= static_cast<const C_polare*>(aux->converti());
        delete aux;
        return this->operator/(cp);
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

//C_polare& C_polare::operator= (const Dato& d){
//    try{
//        auto aux=dynamic_cast<const C_polare&>(d);
//        modulo=aux.modulo;
//        fase=aux.fase;
//        return *this;
//    }
//    catch (const std::bad_cast &error){
//        std::cout << "tipi incompatibili" << std::endl;
//    }
//}

bool C_polare::operator== (const Dato& d)const {
    try{
        auto aux = dynamic_cast<const C_polare &>(d);
        return this->modulo == aux.modulo && this->fase == aux.fase;
    }
    catch(const std::bad_cast& error){
        return false;
    }
}

Complesso* C_polare::converti() const{
    double real=modulo*cos(deg_to_rad(fase));
    double img=modulo*sin(deg_to_rad(fase));
    return new C_cartesiano(real,img);
}

C_polare* C_polare::coniugato() const {
    return new C_polare(modulo,fase*-1);
}

double C_polare::getModulo() const {return modulo;}

double C_polare::getFase() const {return fase;}

void C_polare::stampa(std::ostream& os)const {
    std::cout<<modulo<<"<"<<fase<<"°";
}

std::ostream& operator<<(std::ostream& os, const C_polare& cp){
    cp.stampa(os);
    return os;
}
