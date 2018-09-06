#include "Raz.h"
#include <cmath>

//costruttori

Raz::Raz(long n, long d){   //2 parametri interi
    if(d==0)
        d = 1;
    else if(n==0){num=0,den=1;}
    else if(d<0){num=n*(-1); den=d*(-1);}
    else{num=n; den=d;}
    semplifica();
}

Raz::Raz():num(0),den(1){};

Raz::Raz(std::string s){   //stringa
  try {
      if (s.find('/') == -1) {
          num=toDouble(s);
          den=1;
      }
      else{
          std::string::size_type found=s.find('/');
          num=toDouble(s.substr(0,found-1));
          den=toDouble(s.substr(found+1));
      }
      semplifica();
  }
  catch (const syntax_exception& se){
      throw;
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
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

Raz* Raz::operator- (const Numero *n)const {
    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den-r->num*den,(den*r->den));
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

Raz* Raz::operator* (const Numero *n)const {
    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->num,den*r->den);
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

Raz* Raz::operator/ (const Numero *n)const {
    auto r= dynamic_cast<const Raz*>(n);
    if(r)
      return new Raz(num*r->den,den*r->num);
    throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

Raz* Raz::operator^ (int exp)const {
    if(exp==0) return new Raz(1,1);
    if(exp<0)
        return new Raz(pow(den,exp*-1), pow(num,exp*-1));
    return new Raz(pow(num,exp), pow(den,exp));
}

Raz::operator double() const{
    return static_cast<double>(num)/ static_cast<double>(den);
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

//

//metodi

std::string Raz::toString() const{
    std::string res= std::to_string(getNum())+"/"+std::to_string(getDen());
    return res;
}

Raz* Raz::solve_operation(const Dato* a, const Dato* b, char o){
    auto l=dynamic_cast<const Raz*>(a);
    auto r=dynamic_cast<const Raz*>(b);
    if(l&&r){
        try{
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
                default:
                    throw syntax_exception("Operatore non valido"); //gestire eccezione operatore errato
            }
        }
        catch (const syntax_exception& se){
            throw;
        }
        catch (const logic_exception& le){
            throw;
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

long double Raz::radice_quadrata()const {
    if(getNum()>=0)
        return sqrt(getNum()) / sqrt(getDen());
    else
        throw logic_exception("radice di numero negativo");
}




//      double numerator = std::stod(s, &size);
//      if (s.find('/') == -1) {
//          if (size != s.length())
//              throw syntax_exception("Costruzione oggetto fallita");
//          Raz aux(numerator);
//          num = aux.getNum();
//          den = aux.getDen();
//      }
//      else {
//          double denominator = std::stod(s, &size + 1);
//          if (size != s.length())
//              throw syntax_exception("Costruzione oggetto fallita"); //gestire eccezione syntax error
//          num = numerator;
//          den = denominator;
//      }