//
// Created by luca on 14/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include "C_cartesiano.h"
#include "Componente.h"

class Circuito {
  //friend class const_iterator;
private:
    class nodo{
        friend class Circuito;
    private:
        Componente* obj;
        nodo* left;
        nodo* right;
        nodo* father;
        std::string operation;
    public:
        nodo(Componente* =0, nodo* =0, nodo* =0, nodo* =0, std::string ="0");
        ~nodo();
    };
    nodo*start;
public:
    /*class const_iterator {
        friend class Circuito;
    private:
        const nodo* ptr;
        const_iterator(nodo* n=0): ptr(n) {}
    public:
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
        const_iterator operator++();
        const_iterator operator--();
    }*/
    static double freq;
    static double volt;
    Circuito(Componente* =0);
    ~Circuito ();

    C_cartesiano impEquivalente(nodo*) const ;
    C_cartesiano Corrente_totale() const ;

    Circuito& operator=(const Circuito&);

    //nodo* copy(nodo*);

};

#endif //KALK_CIRCUITO_H
