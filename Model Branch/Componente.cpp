//
// Created by luca on 03/01/18.
//

#include "Componente.h"

Componente::Componente(C_cartesiano c): imp(c){}

Componente::Componente(std::string s){
    auto pos=s.find('Z');
    if(pos == 0)
        imp=std::stod(s.substr(1));
    else
        throw(0) //gestire eccezione errore sintassi
}

Componente::Componente(): imp(0){}
Componente::~Componente(){}

Componente* Componente::operator+ (const Componente* c) const{
    C_cartesiano c1=impedenza();
    C_cartesiano c2=c->impedenza();
    return new Componente(*((&c1)->operator+(&c2)));
}

Componente* Componente::operator/ (const Componente* c) const {
    C_cartesiano c1=impedenza();
    C_cartesiano c2=c->impedenza();
    return new Componente(*(((&c1)->operator*(&c2))->operator/((&c1)->operator+(&c2))));
}

bool Componente::operator== (const Dato& d) const{
   auto aux= dynamic_cast<Componente&>(d);
   if(aux)
       return imp==aux.imp;
   return false;
}

Componente& Componente::operator= (const Dato& d){
    auto aux= dynamic_cast<Componente&>(d);
    if(aux){
        imp = aux.imp;
        return *this;
    }
    throw (0);
}

Componente* Componente::solve_operation(const Dato* l, const Dato* r, char o){
    auto l=dynamic_cast<const Componente*>(a);
    auto r=dynamic_cast<const Componente*>(b);
    if(a && b){
        switch(o) {
            case '+':
                return dynamic_cast<Componente*>(l->operator+(r));
            case '*':
                return dynamic_cast<Componente*>(l->operator*(r));
            default:
                throw (0); //gestire eccezione operatore errato
        }
    }
}

C_cartesiano Componente::impedenza() const{
  return imp;
}

void Componente::setImp(const C_cartesiano c ){
  this->imp=c;
}
