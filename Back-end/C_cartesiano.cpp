//
// Created by luca on 19/12/17.
//

#include "C_cartesiano.h"

C_cartesiano::C_cartesiano(double r, double i):reale(r),immaginaria(i){};

C_cartesiano::C_cartesiano(const C_cartesiano& c):reale(c.reale),immaginaria(c.immaginaria){};


C_cartesiano* C_cartesiano::operator+ (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale+c.reale,immaginaria+c.immaginaria);
}
C_cartesiano* C_cartesiano::operator- (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale-c.reale,immaginaria-c.immaginaria);
}
C_cartesiano* C_cartesiano::operator* (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale*c.reale-immaginaria*c.immaginaria,immaginaria*c.reale+reale*c.immaginaria);
}
C_cartesiano* C_cartesiano::operator/ (const Numero& n)const {
    C_cartesiano c= static_cast<const C_cartesiano&>(n);
    return new C_cartesiano(reale/c.reale-immaginaria/c.immaginaria,immaginaria/c.reale+reale/c.immaginaria);
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

static C_cartesiano* C_cartesiano::parse(std::string s){
    if(*(s.cbegin())=='['){
      double p_real=0, p_img=0;
      std::size_t pos = s.find(',');
      if(pos!=-1){
        p_real=Numero::subparse(s.substr(1,pos-1));
        p_img=Numero::subparse(s.substr((pos+1),(s.lenght()-pos-2));
      }
      else
        p_real=Numero::subparse(s.substr(1,(s.lenght()-1));
      return new C_cartesiano(p_real,p_img);
    }
    return nullptr;
}
