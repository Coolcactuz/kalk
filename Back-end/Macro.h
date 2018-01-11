//
// Created by luca on 03/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include <cmath>
#include "Componente.h"

class Componente;

class Macro {
private:
    class Micro{
        friend class Macro;
    private:
        Componente* obj;
        Micro* father;
        Micro* serie;
        Micro* parallelo;
    public:
        Micro(Componente* =0,Micro* =0,Micro* =0,Micro* =0);
        ~Micro();


    };
    Micro* start;
    Macro* next;
    Macro* prev;

public:
    Macro(Componente* =0, Macro* =0, Macro* =0);
    ~Macro();

    Macro* operator+(Componente*);


};


#endif //KALK_CIRCUITO_H
