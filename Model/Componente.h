//
// Created by luca on 03/01/18.
//

#ifndef KALK_COMPONENTE_H
#define KALK_COMPONENTE_H

#include "C_cartesiano.h"

class Componente : public Dato{
private:
    C_cartesiano imp;
protected:
    static double freq;
    static double volt;
public:
    Componente(C_cartesiano&);
    Componente(std::string);
    Componente();

    virtual C_cartesiano impedenza() const;

    Componente* operator+(const Componente*) const;
    Componente* operator/(const Componente*) const;
    bool operator== (const Dato&) const;
//    Componente& operator= (const Dato&);

    std::string toString() const;
    static double getVolt();
    static double getFreq();
    static void setVolt(double);
    static void setFreq(double);
    void setImp(const C_cartesiano&);

    static Componente* solve_operation(const Dato*, const Dato*, char);

};

#endif //KALK_COMPONENTE_H
