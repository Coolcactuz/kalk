#include "parser.h"
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

    if(size!=s.length()){
      throw syntax_exception("Costruzione oggetto fallita");
    }

    Raz aux(numerator);
    num=aux.getNum();
    den=aux.getDen();
  }

  else{
    double denominator=std::stod(s,&size+1);
    if(size!=s.length()) throw syntax_exception("Costruzione oggetto fallita");
    num=numerator;
    den=denominator;
  }

}

Raz::~Raz(){}

Raz::Raz(double d){ //funziona solo con double positivi

    if(d < 0)
      throw syntax_exception("Valore negativo")

    int i=1;
    while(d-(floor(d*pow(10,i))/pow(10, i))){
        i++;
    }
    Raz b(d*pow(10, i),pow(10,i));
    num=b.getNum();
    den=b.getDen();
}

//overloading operatori con puntatori
Raz* Raz::operator+ (const Numero *n)const {

    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den+r->num*den,(den*r->den));

    throw logic_exception(); //gestire eccezione
}

Raz* Raz::operator- (const Numero *n)const {

    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den-r->num*den,(den*r->den));

    throw logic_exception(); //gestire eccezione
}

Raz* Raz::operator* (const Numero *n)const {

    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->num,den*r->den);

    throw logic_exception(); //gestire eccezione
}

Raz* Raz::operator/ (const Numero *n)const {

    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den,den*r->num);

    throw logic_exception(); //gestire eccezione
}

Raz* Raz::operator^ (int exp)const {

    if(exp==0) return new Raz(1,1);
    if(exp<0)
        return new Raz(pow(den,exp*-1), pow(num,exp*-1));
    return new Raz(pow(num,exp), pow(den,exp));
}

Raz::operator double() const{  //nb: metodi const
    return static_cast<double>(num)/static_cast<double>(den);
}

std::ostream& operator << (std::ostream& os, const Raz& r){
    os<<r.getNum()<<"/"<<r.getDen();
    return os;
}
//

//metodi
Raz* Raz::create(std::string s){ return new Raz(s);}

Raz* Raz::solve_operation(Numero* l, Numero* r, char o) const{

    Raz* res = 0;

    switch(o) {
        case '+':
            res = dynamic_cast<Raz*>(l->operator+(r));
        case '-':
            res = dynamic_cast<Raz*>(l->operator-(r));
        case '*':
            res = dynamic_cast<Raz*>(l->operator*(r));
        case '/':
            res = dynamic_cast<Raz*>(l->operator/(r));
        case '^':
            res = dynamic_cast<Raz*>(l)->operator^(double(*dynamic_cast<Raz*>(r));
        case '#':
            res = new Raz(dynamic_cast<Raz*>(r)->radice_quadrata());
        default:
            throw syntax_exception("Operatore non valido"); //gestire eccezione operatore errato
    }

    if(!res)
      throw logic_exception();

    return res;
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

long double Raz::radice_quadrata()const {
    return sqrt(getNum())/sqrt(getDen());
}

long double Raz::radice_cubica()const {
    return cbrt(getNum())/cbrt(getDen());
}
