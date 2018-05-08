//
// Created by luca on 19/12/17.
//

#include "C_cartesiano.h"
#include "C_polare.h"

C_cartesiano::C_cartesiano(double r, double i):reale(r),immaginaria(i){};

C_cartesiano::C_cartesiano(const C_cartesiano& c):reale(c.reale),immaginaria(c.immaginaria){};

//C_cartesiano::C_cartesiano(const Raz& r):reale(double(r)),immaginaria(0){};

C_cartesiano::~C_cartesiano(){}

C_cartesiano* C_cartesiano::operator+ (const Numero* n)const {
    auto c= dynamic_cast<const C_cartesiano*>(n);
    if(c)
      return new C_cartesiano(reale+c->reale,immaginaria+c->immaginaria);
    throw(0);    //gestire eccezione
}
C_cartesiano* C_cartesiano::operator- (const Numero* n)const {
    auto c= dynamic_cast<const C_cartesiano*>(n);
    if(c)
      return new C_cartesiano(reale-c->reale,immaginaria-c->immaginaria);
    throw(0);    //gestire eccezione
}
C_cartesiano* C_cartesiano::operator* (const Numero* n)const {
    auto c= dynamic_cast<const C_cartesiano*>(n);
    if(c)
      return new C_cartesiano(reale*c->reale-immaginaria*c->immaginaria,immaginaria*c->reale+reale*c->immaginaria);
    throw(0);    //gestire eccezione
}
C_cartesiano* C_cartesiano::operator/ (const Numero* n)const {
    auto c= dynamic_cast<const C_cartesiano*>(n);
    if(c)
      return new C_cartesiano(reale/c->reale-immaginaria/c->immaginaria,immaginaria/c->reale+reale/c->immaginaria);
    throw(0);    //gestire eccezione
}


C_cartesiano C_cartesiano::operator+ (const C_cartesiano& n)const {
    return C_cartesiano(reale+n.reale,immaginaria+n.immaginaria);
}
C_cartesiano C_cartesiano::operator- (const C_cartesiano& n)const {
    return C_cartesiano(reale-n.reale,immaginaria-n.immaginaria);
}
C_cartesiano C_cartesiano::operator* (const C_cartesiano& n)const {
    return C_cartesiano(reale*n.reale-immaginaria*n.immaginaria,immaginaria*n.reale+reale*n.immaginaria);
}
C_cartesiano C_cartesiano::operator/ (const C_cartesiano& n)const {
    return C_cartesiano(reale/n.reale-immaginaria/n.immaginaria,immaginaria/n.reale+reale/n.immaginaria);
}


double C_cartesiano::getReale() const {return reale;}
double C_cartesiano::getImmaginaria() const {return immaginaria;}

C_cartesiano* C_cartesiano::coniugato() const{
    return new C_cartesiano(reale, immaginaria*-1);
}

Complesso* C_cartesiano::converti() const{
    double fase=sqrt(pow(reale,2)+pow(immaginaria,2));
    double modulo=(immaginaria<0)?rad_to_deg(atan(immaginaria/reale)+pi):rad_to_deg(atan(immaginaria/reale));
    return new C_polare(fase,modulo);
}

void C_cartesiano::stampa(std::ostream& os)const {
    std::cout<<reale;
    if(immaginaria<0)std::cout<< immaginaria;
    else std::cout<<"+"<<immaginaria;
    std::cout<<"i";
}

std::ostream& operator<<(std::ostream& os, const Numero& n){
    C_cartesiano cc= static_cast<const C_cartesiano&>(n);
    cc.stampa(os);
    return os;
}

/*
C_cartesiano* C_cartesiano::parse(std::string s){
    if(*(s.cbegin())=='['){
      double p_real=0, p_img=0;
      std::size_t pos = s.find(',');
      if(pos!=-1){
        p_real=Numero::subparse(s.substr(1,pos-1));
        p_img=Numero::subparse(s.substr((pos+1),(s.length()-pos-2)));
      }
      else
        p_real=Numero::subparse(s.substr(1,(s.length()-1)));
      return new C_cartesiano(p_real,p_img);
    }
    return nullptr;
}
*/
