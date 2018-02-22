//
// Created by luca on 03/01/18.
//

#ifndef KALK_RESISTORE_H
#define KALK_RESISTORE_H


#include "Componente.h"
#include "Circuito.h"

class Resistore : public Componente{
private:
    std::string nome;
    double resistenza;
public:
    Resistore(std::string ="NoName", double =0);
    //~Resistore();

    std::string getName() const override ;
    C_cartesiano impedenza() const override;
};


#endif //KALK_RESISTORE_H
