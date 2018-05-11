//
// Created by luca on 03/01/18.
//

#ifndef KALK_COMPONENTE_H
#define KALK_COMPONENTE_H

#include "C_cartesiano.h"

class Componente{
private:
    C_cartesiano imp;
    std::string nome;
public:
    Componente(C_cartesiano = 0, std::string = "NoName");
    virtual ~Componente ();

    virtual std::string getName() const;
    virtual C_cartesiano impedenza() const;
    void rename();
    void setImp(const C_cartesiano& );

    Componente* operator+(const Componente*) const;
    Componente* operator/(const Componente*) const;

};

#endif //KALK_COMPONENTE_H
