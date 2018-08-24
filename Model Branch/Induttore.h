//
// Created by luca on 10/01/18.
//

#ifndef KALK_INDUTTANZA_H
#define KALK_INDUTTANZA_H


#include "Componente.h"
#include "Circuito.h"

class Induttore: public Componente{
private:
    double induttanza;
public:
    Induttore(double);
    Induttore(std::string);
    Induttore();
    ~Induttore();

    bool operator== (const Dato&) const;
    Induttore& operator= (const Dato&);

    C_cartesiano impedenza() const override;
};

#endif //KALK_INDUTTANZA_H
