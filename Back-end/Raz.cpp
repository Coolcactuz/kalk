//
// Created by luca on 07/12/17.
//

#include "Raz.h"
#include <cmath>

//costruttori
Raz::Raz(int n):num(n),den(1){}; //1 parametro intero

Raz::Raz(long n, long d){ //2 parametri interi
    if(d==0) throw(0);  //GESTIRE ECCEZIONE
    else if(n==0){num=0,den=1;}
    else if(d<0){num=n*(-1); den=d*(-1);}
    else{num=n; den=d;}
    semplifica();
}

Raz::Raz(double d){ //1 parametro decimale
    int i=1;
    while(d-(floor(d*pow(10,i))/pow(10, i))){
        i++;
    }
    Raz b(d*pow(10, i),pow(10,i));
    num=b.getNum();
    den=b.getDen();
}
//

//overloading operatori
Raz* Raz::operator+ (const Numero &n)const {
    Raz r= static_cast<const Raz&>(n);
    return new Raz(num*r.den+r.num*den,(den*r.den));
}
Raz* Raz::operator- (const Numero &n)const {
    Raz r= static_cast<const Raz&>(n);
    return new Raz(num*r.den-r.num*den,(den*r.den));
}
Raz* Raz::operator* (const Numero &n)const {
    Raz r= static_cast<const Raz&>(n);
    return new Raz(num*r.num,den*r.den);
}
Raz* Raz::operator/ (const Numero &n)const {
    Raz r= static_cast<const Raz&>(n);
    return new Raz(num*r.den,den*r.num);
}
Raz* Raz::operator^ (int exp)const {
    if(exp==0) return new Raz(1,1);
    if(exp<0)
        return new Raz(pow(den,exp*-1), pow(num,exp*-1));
    return new Raz(pow(num,exp), pow(den,exp));
}

Raz::operator double() const{  //NB: metodi const
    return static_cast<double>(num)/static_cast<double>(den);
}

std::ostream& operator << (std::ostream& os, const Raz& r){
    os<<r.getNum()<<"/"<<r.getDen();
    return os;
}
//


//metodi
long Raz::getNum () const { return num; }

long Raz::getDen () const { return den; }

Raz* Raz::reciproco() const {return new Raz(den,num);}

int Raz::getMCD(long a, long b) const {
    int r;
    while(b){
        r = a%b;
        a=b;
        b=r;
    }
    return (a>=0?a:(a*-1));
}

void Raz::semplifica(){
    int mcd=getMCD(getNum(),getDen());
    num=num/mcd;
    den=den/mcd;
}

long double Raz::radice_quadrata()const {
    return sqrt(getNum())/sqrt(getDen());
}

long double Raz::radice_cubica()const {
    return cbrt(getNum())/cbrt(getDen());
}

static Raz* Raz::parse(std::string s){
  if(*(s.cbegin())=='{'){
    double p_num=0, p_den=0;
    std::size_t pos = s.find(",");
    if(pos!=-1){
      p_num=Numero::subparse(s.substr(1,pos-1));
      p_den=Numero::subparse(s.substr((pos+1),(s.lenght()-pos-2));
    }
    else
      p_num=Numero::subparse(s.substr(1,(s.lenght()-1));
    return new Raz(p_num,p_den);
  }
  return nullptr;
}
