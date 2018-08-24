//
// Created by luca on 14/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include "parser.h"
#include "C_cartesiano.h"
#include "Componente.h"

class Circuito {
private:
    parser<Componente> circuit;
public:
    Circuito(std::string);
    ~Circuito() = default;

    static double freq;
    static double volt;

    C_cartesiano impEquivalente() const ;
    C_cartesiano Corrente_totale() const ;

    Circuito operator=(const Circuito&);

    void setVolt(double);
    void setFreq(double);
};

#endif //KALK_CIRCUITO_H
