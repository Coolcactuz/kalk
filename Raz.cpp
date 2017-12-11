//
// Created by luca on 07/12/17.
//
#include<iostream>
#include "Raz.h"

Raz::Raz(int n){num=n; den=1;}
Raz::Raz(int n, int d){
    if(d==0) throw(0);
    else if(n==0){num=0,den=1;}
    else if(d<0){num=n*(-1); den=d*(-1);}
    else{num=n; den=d;}
}
Raz::~Raz(){}
Raz Raz::reciproco() {return Raz(den,num);}
Raz& Raz::operator= (const Raz &r){
    num=r.num;
    den=r.den;
    return *this;
}
Raz Raz::operator+ (const Raz &r){return Raz(num*r.den+r.num*den,(den*r.den));}
Raz Raz::operator- (const Raz &r){return Raz(num*r.den-r.num*den,(den*r.den));}
Raz Raz::operator* (const Raz &r){return Raz(num*r.num,den*r.den);}
Raz Raz::operator/ (Raz &r){return (*this)*r.reciproco();}
Raz Raz::operator^ (int exp){
    if(exp==0) return Raz(1);
    else if (exp<0) {
        *this=reciproco();
        exp = exp * (-1);
    }
    Raz aux=*this;
    for(unsigned int i=1; i<exp; ++i){
        aux=aux*(*this);
    }
    return aux;
}

double Raz::converti() const{
    return static_cast<double>(num)/static_cast<double>(den);
}
void Raz::semplifica(){

}
