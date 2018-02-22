//
// Created by luca on 10/01/18.
//

#ifndef KALK_CONDENSATORE_H
#define KALK_CONDENSATORE_H


#include "Componente.h"
#include "Circuito.h"

class Condensatore: public Componente{
private:
    std::string nome;
    double capacita;
public:
    Condensatore(std::string ="NoName", double =0);
    //~Condensatore ();

    std::string getName() const override;
    C_cartesiano impedenza() const override;
};

#endif //KALK_CONDENSATORE_H
