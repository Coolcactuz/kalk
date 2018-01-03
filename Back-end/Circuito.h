//
// Created by luca on 03/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include "Componente.h"
#include "C_cartesiano.h"

class Circuito {
private:
    class Iterator{
    public:
        Componente* obj;
        Iterator* prec;
        Iterator* succ;

        Iterator(Componente*);

        Iterator* operator++();
        Iterator* operator--();
    };
    double voltaggio;
    double amperaggio;
    Iterator* start;

};


#endif //KALK_CIRCUITO_H
