//
// Created by luca on 19/12/17.
//

#include "C_cartesiano.h"
#include "C_polare.h"
#include <cmath>

C_cartesiano::C_cartesiano(double r, double i):reale(r),immaginaria(i){};

C_cartesiano::C_cartesiano(const C_cartesiano& c):reale(c.reale),immaginaria(c.immaginaria){};

C_cartesiano::C_cartesiano(std::string s){
  auto pos=s.find('i');
  std::string::size_type size=0;
  reale=0;
  immaginaria=0;
  if(pos==-1)
    reale=std::stod(s);
  else if(pos==s.length()-1)
    immaginaria=(pos==0?1:std::stod(s.substr(size)));
  else
    throw(0); //gestire eccezione syntax error
}

C_cartesiano::C_cartesiano():reale(0),immaginaria(0){};

C_cartesiano::~C_cartesiano(){}

C_cartesiano* C_cartesiano::operator+ (const Numero* n)const {
    if(dynamic_cast<const C_cartesiano*>(n)){
      const C_cartesiano* c=static_cast<const C_cartesiano*>(n);
      return new C_cartesiano(reale+c->reale,immaginaria+c->immaginaria);
    }
    else if(dynamic_cast<const C_polare*>(n)){
      const C_polare* cp=static_cast<const C_polare*>(n);
      const C_cartesiano* aux=static_cast<const C_cartesiano*>(cp->converti());
      return this->operator+(aux);
    }
    else
      throw(0);    //gestire eccezione di tipo incompatibile
}

C_cartesiano* C_cartesiano::operator- (const Numero* n)const {
  if(dynamic_cast<const C_cartesiano*>(n)){
    const C_cartesiano* c=static_cast<const C_cartesiano*>(n);
    return new C_cartesiano(reale-c->reale,immaginaria-c->immaginaria);
  }
  else if(dynamic_cast<const C_polare*>(n)){
    const C_polare* cp=static_cast<const C_polare*>(n);
    const C_cartesiano* aux=static_cast<const C_cartesiano*>(cp->converti());
    return this->operator-(aux);
  }
  else
    throw(0);    //gestire eccezione di tipo incompatibile
}

C_cartesiano* C_cartesiano::operator* (const Numero* n)const {
  if(dynamic_cast<const C_cartesiano*>(n)){
    const C_cartesiano* c=static_cast<const C_cartesiano*>(n);
    return new C_cartesiano(reale*c->reale-immaginaria*c->immaginaria,immaginaria*c->reale+reale*c->immaginaria);
  }
  else if(dynamic_cast<const C_polare*>(n)){
    const C_polare* cp=static_cast<const C_polare*>(n);
    const C_cartesiano* aux=static_cast<const C_cartesiano*>(cp->converti());
    return this->operator*(aux);
  }
  else
    throw(0);    //gestire eccezione di tipo incompatibile
}

C_cartesiano* C_cartesiano::operator/ (const Numero* n)const {
  if(dynamic_cast<const C_cartesiano*>(n)){
    const C_cartesiano* c= static_cast<const C_cartesiano*>(n);
    return new C_cartesiano((reale*c->reale+immaginaria*c->immaginaria)/(pow(reale,2)+pow(c->immaginaria,2)),(immaginaria*c->reale-reale*c->immaginaria)/(pow(reale,2)+pow(c->immaginaria,2)));
  }
  else if(dynamic_cast<const C_polare*>(n)){
    const C_polare* aux=static_cast<const C_polare*>(this->converti());
    return static_cast<C_cartesiano*>(aux->operator/(n)->converti());
  }
  else
    throw(0);    //gestire eccezione di tipo incompatibile
}

C_cartesiano& C_cartesiano::operator=(const Dato&) const{
    auto aux= dynamic_cast<C_cartesiano&>(d);
    if(d){
        reale=aux.reale;
        immaginaria=aux.immaginaria;
        return *this;
    }
    throw(0); //gestire eccezione
}

bool C_cartesiano::operator== (const Dato& d)const{
    auto aux= dynamic_cast<const C_cartesiano&>(d);
    if(aux)
        return this->reale==aux.reale && this->immaginaria==aux.immaginaria;
    return false;
}

double C_cartesiano::getReale() const {return reale;}
double C_cartesiano::getImmaginaria() const {return immaginaria;}

C_cartesiano* C_cartesiano::coniugato() const{
    return new C_cartesiano(reale, immaginaria*-1);
}

Complesso* C_cartesiano::converti() const{
    double fase=sqrt(pow(reale,2)+pow(immaginaria,2));
    double modulo=rad_to_deg(atan(immaginaria/reale));
    return new C_polare(fase,modulo);
}

void C_cartesiano::stampa(std::ostream& os)const {
    std::cout<<reale;
    if(immaginaria<0)std::cout<< immaginaria;
    else std::cout<<"+"<<immaginaria;
    std::cout<<"i";
}

std::ostream& operator<<(std::ostream& os, const C_cartesiano& n){
    n.stampa(os);
    return os;
}