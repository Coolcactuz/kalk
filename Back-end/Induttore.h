//
// Created by luca on 10/01/18.
//

#ifndef KALK_INDUTTANZA_H
#define KALK_INDUTTANZA_H


#include "Componente.h"

class Induttore: public Componente{
private:
    std::string nome;
    double induttanza;
public:
    Induttore(std::string ="NoName", double =0);

    std::string getName() const ;
    C_cartesiano impedenza() const ;
};

#endif //KALK_INDUTTANZA_H
