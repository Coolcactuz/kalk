//
// Created by luca on 07/12/17.
//

#include "Raz.h"
#include <cmath>

//costruttori
Raz::Raz(int n){num=n; den=1;} //1 parametro intero
Raz::Raz(long n, long d){ //2 parametri interi
    if(d==0) throw(0);
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
    semplifica();
}
//

//overloading operatori
Raz& Raz::operator= (const Raz &r){
    num=r.num;
    den=r.den;
    return *this;
}
Raz Raz::operator+ (const Raz &r){return Raz(num*r.den+r.num*den,(den*r.den));}
Raz Raz::operator- (const Raz &r){return Raz(num*r.den-r.num*den,(den*r.den));}
Raz Raz::operator* (const Raz &r){return Raz(num*r.num,den*r.den);}
Raz Raz::operator/ (Raz r){return (*this)*r.reciproco();}
Raz Raz::operator^ (int exp){
    if(exp==0) return Raz(1,0);
    else if (exp<0) {
        *this=reciproco();
        exp = exp*(-1);
    }
    Raz aux=*this;
    for(unsigned int i=1; i<exp; ++i){
        aux=aux*(*this);
    }
    return aux;
}

Raz::operator double() const{  //NB: metodi const
    return static_cast<double>(num)/static_cast<double>(den);
}
//
//metodi
Raz Raz::reciproco() const {return Raz(den,num);}

int Raz::getMCD(long a, long b) const {
    int r;
    while(b){
        r = a%b;
        a=b;
        b=r;
    }
    return a;
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