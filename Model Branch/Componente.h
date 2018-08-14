//
// Created by luca on 03/01/18.
//

#ifndef KALK_COMPONENTE_H
#define KALK_COMPONENTE_H

#include "C_cartesiano.h"
#include "Dato.h"

class Componente : public Dato{
private:
    C_cartesiano imp;
public:
    Componente(C_cartesiano);
    Componente(std::string);
    Componente();
    virtual ~Componente ();

    virtual C_cartesiano impedenza() const;

    void setImp(const C_cartesiano);
    static Componente* create(std::string);

    Componente* operator+(const Componente*) const;
    Componente* operator/(const Componente*) const;

    static Componente* solve_operation(const Dato*, const Dato*, char);

};

#endif //KALK_COMPONENTE_H
