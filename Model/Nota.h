#ifndef NOTA_H
#define NOTA_H


#include "Raz.h"

class Nota{
private:
    int note;
    std::string tono;
    Raz tempo;

public:
    Nota(int =0, std::string ="", Raz=0);
    Nota(const Nota&);

    Nota* operator+ (const Raz&); //aumenta tempo
    Nota* operator- (const Raz&); //diminuisci tempo
    Nota* operator++ (); //aumenta tonalità
    Nota* operator-- (); //diminuisci tonalità


    int getNote() const;
    std::string getTono() const;
    Raz getTempo() const;

    void stampa(std::ostream&)const;
};


std::ostream& operator<<(std::ostream&, const Nota&);
#endif
