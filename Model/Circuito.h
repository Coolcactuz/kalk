#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include "parser.h"
#include "C_cartesiano.h"
#include "Componente.h"
#include <vector>

class Circuito {
private:
    typename parser<Componente>::node* start;
public:
    Circuito(std::string);
    ~Circuito ();

    static double freq;
    static double volt;

    C_cartesiano impEquivalente() const ;
    C_cartesiano Corrente_totale() const ;

    void setVolt(double);
    void setFreq(double);
};

#endif //KALK_CIRCUITO_H
