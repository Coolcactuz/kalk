#include "C_cartesiano.h"
#include "C_polare.h"
#include <cmath>

C_cartesiano::C_cartesiano(double r, double i):reale(r),immaginaria(i){};

C_cartesiano::C_cartesiano(std::string s){
  auto pos=s.find('i');
  std::string::size_type size=0;
  reale=0;
  immaginaria=0;
  try{
    if(pos==-1)
        reale=toDouble(s);
    else if(pos==s.length()-1)
        immaginaria=(pos==0?1:toDouble(s.substr(size,s.length()-1)));
    else
        throw syntax_exception("Invalid value"); //gestire eccezione syntax error
  }
  catch (const syntax_exception& se){
      throw;
  }
  catch (const std::exception& ex){
      throw syntax_exception("errore di sintassi");
  }
}

C_cartesiano::C_cartesiano():reale(0),immaginaria(0){};

C_cartesiano* C_cartesiano::operator+ (const Numero* n)const {
    if(dynamic_cast<const C_cartesiano*>(n)){
      const C_cartesiano* c=static_cast<const C_cartesiano*>(n);
      return new C_cartesiano(reale+c->reale,immaginaria+c->immaginaria);
    }
    else if(dynamic_cast<const C_polare*>(n)){
      const C_polare* cp=static_cast<const C_polare*>(n);
      const C_cartesiano* aux=static_cast<const C_cartesiano*>(cp->converti());
      C_cartesiano* result = operator+(aux);
      delete aux;
      return result;
    }
    else
    throw logic_exception("Tipo incompatibile");    //gestire eccezione di tipo incompatibile
}

C_cartesiano* C_cartesiano::operator- (const Numero* n)const {
  if(dynamic_cast<const C_cartesiano*>(n)){
    const C_cartesiano* c=static_cast<const C_cartesiano*>(n);
    return new C_cartesiano(reale-c->reale,immaginaria-c->immaginaria);
  }
  else if(dynamic_cast<const C_polare*>(n)){
    const C_polare* cp=static_cast<const C_polare*>(n);
    const C_cartesiano* aux=static_cast<const C_cartesiano*>(cp->converti());
    C_cartesiano* result = operator-(aux);
    delete aux;
    return result;
  }
  else
      throw logic_exception("Tipo incompatibile");    //gestire eccezione di tipo incompatibile
}

C_cartesiano* C_cartesiano::operator* (const Numero* n)const {
  if(dynamic_cast<const C_cartesiano*>(n)){
    const C_cartesiano* c=static_cast<const C_cartesiano*>(n);
    return new C_cartesiano(reale*c->reale-immaginaria*c->immaginaria,immaginaria*c->reale+reale*c->immaginaria);
  }
  else if(dynamic_cast<const C_polare*>(n)){
    const C_polare* cp=static_cast<const C_polare*>(n);
    const C_cartesiano* aux=static_cast<const C_cartesiano*>(cp->converti());
    C_cartesiano* result = operator*(aux);
    delete aux;
    return result;
  }
  else
      throw logic_exception("Tipo incompatibile");    //gestire eccezione di tipo incompatibile
}

C_cartesiano* C_cartesiano::operator/ (const Numero* n)const {
  if(dynamic_cast<const C_cartesiano*>(n)){
    const C_cartesiano* c= static_cast<const C_cartesiano*>(n);
    return new C_cartesiano((reale*c->reale+immaginaria*c->immaginaria)/(pow(c->reale,2)+pow(c->immaginaria,2)),(immaginaria*c->reale-reale*c->immaginaria)/(pow(c->reale,2)+pow(c->immaginaria,2)));
  }
  else if(dynamic_cast<const C_polare*>(n)){
    const C_polare* cp= static_cast<const C_polare*>(n);
    const C_cartesiano* aux= static_cast<const C_cartesiano*>(cp->converti());
    C_cartesiano* result = operator/(aux);
    delete aux;
    return result;
  }
  else
      throw logic_exception("Tipo incompatibile");    //gestire eccezione di tipo incompatibile
}

bool C_cartesiano::operator== (const Dato& d)const{
    try {
        auto aux = dynamic_cast<const C_cartesiano &>(d);
        return reale == aux.reale && immaginaria == aux.immaginaria;
    }
    catch(const std::bad_cast& error){
        return false;
    }
}

std::string C_cartesiano::toString() const{
    std::string res= std::to_string(getReale());
    if(getImmaginaria()>=0)
        res=res+"+";
    res=res+std::to_string(getImmaginaria())+"i";
    return res;
}

double C_cartesiano::getReale() const {return reale;}
double C_cartesiano::getImmaginaria() const {return immaginaria;}

C_cartesiano* C_cartesiano::coniugato() const{
    return new C_cartesiano(reale, immaginaria*-1);
}

Complesso* C_cartesiano::converti() const{
    double f=sqrt(pow(reale,2)+pow(immaginaria,2));
    double m=rad_to_deg(atan(immaginaria/reale));
    return new C_polare(f,m);
}

