//
// Created by luca on 03/01/18.
//

#ifndef KALK_RESISTORE_H
#define KALK_RESISTORE_H


#include "Componente.h"

class Resistore : public Componente{
private:
    std::string nome;
    double resistenza;
public:
    Resistore(std::string ="NoName", double =0);

    std::string getName() const ;
    C_cartesiano impedenza() const ;
};


#endif //KALK_RESISTORE_H
