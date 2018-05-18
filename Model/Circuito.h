//
// Created by luca on 14/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include "C_cartesiano.h"
#include "Componente.h"
#include <vector>

class Circuito {
private:
    std::vector<Componente*> v;
public:
    Circuito(Componente* =0);
    ~Circuito ();

    static double freq;
    static double volt;

    C_cartesiano impEquivalente() const ;
    C_cartesiano Corrente_totale() const ;

    void setVolt(double);
    void setFreq(double);
    //bool checkName(std::string);
};

#endif //KALK_CIRCUITO_H
