#ifndef KALK_DATO_H
#define KALK_DATO_H

#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>
#include "exception.h"

class Dato{
protected:
    static double toDouble(std::string s){
        if(s.length()==0) {
            std::cout<<"errore qui"<<std::endl;
            throw syntax_exception("errore di sintassi");
        }
        std::cout<<s<<std::endl;
        std::string::size_type size=0;
        double res=std::stod(s, &size);
        if(size==s.length())
            return res;
        throw syntax_exception("errore di sintassi");
    }
public:
    virtual ~Dato() = default;
    virtual bool operator==(const Dato&) const =0;
    virtual std::string toString() const =0;
};


#endif //KALK_NUMERO_H
