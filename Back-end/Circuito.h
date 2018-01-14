//
// Created by luca on 14/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

class Componente;

class Circuito {
private:
    class nodo{
    private:
        Componente* obj;
        nodo* left;
        nodo* right;
        //std::string operation;
    public:
        nodo();
        ~nodo();
    };
    nodo*start;
public:
    static double freq;
    static double volt;

};


#endif //KALK_CIRCUITO_H
