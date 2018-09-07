#include "C_polare.h"
#include <cmath>

C_polare::C_polare():modulo(0),fase(0){};

C_polare::C_polare(double m, double f) {
    if(m<0) throw logic_exception("Modulo negativo");    //GESTIRE ECCEZIONE
    else if(m==0){
      modulo=0;
      fase=0;
    }
    else{
        modulo=m;
        while(f>=360 || f<0){
          f=((f>=360)?(f-360):(360+f));
        }
        fase=f;
    }
}

C_polare::C_polare(std::string s) {
    auto pos = s.find('<');
    modulo = 0;
    fase = 0;
    try {
        if (pos == std::string::npos)
            modulo = toDouble(s);
        else if (pos != s.length() - 1) {
            modulo = toDouble(s.substr(0,pos));
            if (modulo == 0)
                fase = 0;
            else
                fase = toDouble(s.substr(pos+1));
        }
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

C_polare* C_polare::operator+ (const Numero* n)const{
    if(dynamic_cast<const C_cartesiano*>(n)) {
        const C_cartesiano* aux = static_cast<const C_cartesiano*>(this->converti());
        const C_cartesiano* cc= static_cast<const C_cartesiano*>(n);
        C_cartesiano* somma= aux->operator+(cc);
        delete aux;
        C_polare* somma_polare= static_cast<C_polare*>(somma->converti());
        delete somma;
        return somma_polare;
    }
    else if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        const C_cartesiano* supp= static_cast<const C_cartesiano*>(cp->converti());
        C_polare* result=this->operator+(supp);
        delete supp;
        return result;
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

C_polare* C_polare::operator- (const Numero* n)const{
    if(dynamic_cast<const C_cartesiano*>(n)) {
        const C_cartesiano* aux = static_cast<const C_cartesiano*>(this->converti());
        const C_cartesiano* cc= static_cast<const C_cartesiano*>(n);
        C_cartesiano* diff= aux->operator-(cc);
        delete aux;
        C_polare* diff_polare= static_cast<C_polare*>(diff->converti());
        delete diff;
        return diff_polare;
    }
    else if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        const C_cartesiano* supp= static_cast<const C_cartesiano*>(cp->converti());
        C_polare* result=this->operator-(supp);
        delete supp;
        return result;
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}
C_polare* C_polare::operator* (const Numero* n)const{
    if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        double m=modulo*cp->modulo;
        double f=rad_to_deg(atan(deg_to_rad(fase))+atan(deg_to_rad(cp->fase)));
        return new C_polare(m,f);
    }
    else if(dynamic_cast<const C_cartesiano*>(n)){
        const C_cartesiano* aux= static_cast<const C_cartesiano*>(n);
        const C_polare* supp= static_cast<const C_polare*>(aux->converti());
        C_polare* result=this->operator*(supp);
        delete supp;
        return result;
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

C_polare* C_polare::operator/ (const Numero* n)const{
    if(dynamic_cast<const C_polare*>(n)){
        const C_polare* cp= static_cast<const C_polare*>(n);
        double m=modulo/cp->modulo;
        double f=fase-cp->fase;
        return new C_polare(m,f);
    }
    else if(dynamic_cast<const C_cartesiano*>(n)){
        const C_cartesiano* aux= static_cast<const C_cartesiano*>(n);
        const C_polare* supp= static_cast<const C_polare*>(aux->converti());
        C_polare* result=this->operator/(supp);
        delete supp;
        return result;
    }
    else
        throw logic_exception("Tipo incompatibile"); //gestire eccezione
}

bool C_polare::operator== (const Dato& d)const {
    try{
        auto aux = dynamic_cast<const C_polare &>(d);
        return modulo == aux.modulo && fase == aux.fase;
    }
    catch(const std::bad_cast& error){
        return false;
    }
}

std::string C_polare::toString() const{
    std::string res= std::to_string(getModulo())+"<"+std::to_string(getFase());
    return res;
}

Complesso* C_polare::converti() const{
    double real=modulo*cos(deg_to_rad(fase));
    double img=modulo*sin(deg_to_rad(fase));
    return new C_cartesiano(real,img);
}

C_polare* C_polare::coniugato() const {
    return new C_polare(modulo,fase*-1);
}

double C_polare::getModulo() const {return modulo;}

double C_polare::getFase() const {return fase;}

