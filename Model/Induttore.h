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
    Induttore(double =0,std::string ="NoName");
    ~Induttore();

    C_cartesiano impedenza() const override;
};

#endif //KALK_INDUTTANZA_H
