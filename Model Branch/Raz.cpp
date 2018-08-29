//
// Created by luca on 07/12/17.
//
#include "Raz.h"
#include <cmath>

//costruttori
//Raz::Raz(int n):num(n),den(1){}; //1 parametro intero

Raz::Raz(long n, long d){   //2 parametri interi
    if(d==0){
        //se il denominatore è 0 viene automaticamente settato a 1
        d = 1;
    }
    else if(n==0){num=0,den=1;}
    else if(d<0){num=n*(-1); den=d*(-1);}
    else{num=n; den=d;}
    semplifica();
}

Raz::Raz():num(0),den(1){};

Raz::Raz(std::string s){   //stringa
  std::string::size_type size=0;
  double numerator=std::stod(s,&size);
  if(s.find('/')==-1){
    if(size!=s.length())
          throw syntax_exception("Costruzione oggetto fallita");
    Raz aux(numerator);
    num=aux.getNum();
    den=aux.getDen();
  }
  else{
    double denominator=std::stod(s,&size+1);
    if(size!=s.length()) throw syntax_exception("Costruzione oggetto fallita"); //gestire eccezione syntax error
    num=numerator;
    den=denominator;
  }
}

Raz::Raz(double d){ //1 parametro decimale
    int i=1;
    while(d-(floor(d*pow(10,i))/pow(10, i))){
        i++;
    }
    Raz b(d*pow(10, i), pow(10,i));
    num=b.getNum();
    den=b.getDen();
}
//

//overloading operatori con puntatori
Raz* Raz::operator+ (const Numero *n)const {
    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den+r->num*den,(den*r->den));
<<<<<<< HEAD
    else{
      //gestire eccezione
      std::cout << "cast fallito" << std::endl;
    }
=======
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
>>>>>>> 07f087e4e63000dc189fc184e39e3261fb24a5ee
}

Raz* Raz::operator- (const Numero *n)const {
    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den-r->num*den,(den*r->den));
<<<<<<< HEAD
    else{
      //gestire eccezione
      std::cout << "cast fallito" << std::endl;
    }
=======
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
>>>>>>> 07f087e4e63000dc189fc184e39e3261fb24a5ee
}

Raz* Raz::operator* (const Numero *n)const {
    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->num,den*r->den);
<<<<<<< HEAD
    else{
      //gestire eccezione
      std::cout << "cast fallito" << std::endl;
    }
=======
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
>>>>>>> 07f087e4e63000dc189fc184e39e3261fb24a5ee
}

Raz* Raz::operator/ (const Numero *n)const {
    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den,den*r->num);
<<<<<<< HEAD
    else{
      //gestire eccezione
      std::cout << "cast fallito" << std::endl;
    }
=======
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
>>>>>>> 07f087e4e63000dc189fc184e39e3261fb24a5ee
}

Raz* Raz::operator^ (int exp)const {
    if(exp==0) return new Raz(1,1);
    if(exp<0)
        return new Raz(pow(den,exp*-1), pow(num,exp*-1));
    return new Raz(pow(num,exp), pow(den,exp));
}

Raz::operator double() const{  //nb: metodi const
    return num/den;
}

bool Raz::operator== (const Dato& d)const{
    try {
        auto aux = dynamic_cast<const Raz &>(d);
        return this->num == aux.num && this->den == aux.den;
    }
    catch(const std::bad_cast& error){
        return false;
    }
}

Raz& Raz::operator=(const Dato& d){
    try{
        auto aux= dynamic_cast<const Raz&>(d);
        num=aux.num;
        den=aux.den;
        return *this;
    }
    catch (const std::bad_cast &error){
        std::cout << "tipi incompatibili" << std::endl;
    }
}

std::ostream& operator << (std::ostream& os, const Raz& r){
    os<<r.getNum()<<"/"<<r.getDen();
    return os;
}
//

//metodi

Raz* Raz::solve_operation(const Dato* a, const Dato* b, char o){
    auto l=dynamic_cast<const Raz*>(a);
    auto r=dynamic_cast<const Raz*>(b);
    if(l&&r){
        switch(o) {
            case '+':
                return l->operator+(r);
            case '-':
                return l->operator-(r);
            case '*':
                return l->operator*(r);
            case '/':
                return l->operator/(r);
            case '^':
                return l->operator^(double(*dynamic_cast<const Raz*>(r)));
            case '#':
                return new Raz(r->radice_quadrata());
            default:
                throw syntax_exception("Operatore non valido"); //gestire eccezione operatore errato
        }
    }
    else
        throw logic_exception("tipo di dati errato");
}

long Raz::getNum () const { return num; }

long Raz::getDen () const { return den; }

Raz* Raz::reciproco() const {return new Raz(den,num);}

int Raz::getMCD(long a, long b) const {
    a = abs(a);
    b = abs(b);
    if(!b)
        throw logic_exception("Divisore nullo");
    int r;
    while(b){
        r = a%b;
        a=b;
        b=r;
    }
    return (a>=0 ? a:(a*-1));
}

void Raz::semplifica(){
    int mcd=getMCD(getNum(),getDen());
    num=num/mcd;
    den=den/mcd;
}

<<<<<<< HEAD
long double Raz::radice_quadrata() const {
    return sqrt(getNum())/sqrt(getDen());
}

long double Raz::radice_cubica()const {
    return cbrt(getNum())/cbrt(getDen());
=======
long double Raz::radice_quadrata()const {
    if(getNum()>=0)
        return sqrt(getNum()) / sqrt(getDen());
    else
        throw logic_exception("radice di numero negativo");
>>>>>>> 07f087e4e63000dc189fc184e39e3261fb24a5ee
}
