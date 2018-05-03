//
// Created by luca on 14/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include "C_cartesiano.h"
#include "Componente.h"

class Circuito {
private:
    class nodo{
        friend class Circuito;
    private:
        Componente* obj;
        nodo* left;
        nodo* right;
        std::string operation;
    public:
        nodo(Componente* =0, nodo* =0, nodo* =0, std::string ="0");
        ~nodo();
    };
    nodo*start;
public:
    Circuito(Componente* =0);
    ~Circuito ();
    static double freq;
    static C_cartesiano volt;

    C_cartesiano impEquivalente(nodo*) const ;
    C_cartesiano Corrente_totale() const ;

    Circuito& operator=(const Circuito&);
    nodo* copy(nodo*);

};

#endif //KALK_CIRCUITO_H
