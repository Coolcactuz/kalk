//
// Created by luca on 07/12/17.
//

#include "Raz.h"
#include <cmath>

//costruttori
Raz::Raz(int n){num=n; den=1;}
Raz::Raz(int n, int d){
    if(d==0) throw(0);
    else if(n==0){num=0,den=1;}
    else if(d<0){num=n*(-1); den=d*(-1);}
    else{num=n; den=d;}
}

//rivedere
/*
Raz::Raz(double d){
    double parte_intera = floor(d);
    double parte_decimale = d - parte_intera;

    int precisione = 1000000000;

    //int mcd = getMCD(static_cast<int>(round(parte_decimale * precisione)), precisione);
    int dec_num= static_cast<int >(round(parte_decimale * precisione));
    int dec_den=precisione;
    Raz dec(dec_num,dec_den);
    Raz intero(parte_intera);
    Raz totale(dec+intero);
    num=totale.getNum();
    den=totale.getDen();
}*/
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
Raz::operator double() const{  //NB: metodi const
    return static_cast<double>(num)/static_cast<double>(den);
}
//
//metodi
Raz Raz::reciproco() {return Raz(den,num);}

int Raz::getMCD(int a, int b){
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
