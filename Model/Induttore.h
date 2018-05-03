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
    //~Induttore();

    std::string getName() const override;
    C_cartesiano impedenza() const override;
};

#endif //KALK_INDUTTANZA_H
