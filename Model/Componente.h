#ifndef KALK_COMPONENTE_H
#define KALK_COMPONENTE_H

#include "C_cartesiano.h"

class Componente{
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

    Componente* solve_operation(const Componente*, const Componente*, char)const ;

};

#endif //KALK_COMPONENTE_H
