//
// Created by luca on 03/01/18.
//

#ifndef KALK_RESISTORE_H
#define KALK_RESISTORE_H


#include "Componente.h"
#include "Circuito.h"

class Resistore : public Componente{
private:
    double resistenza;
public:
    Resistore(double =0,std::string ="NoName");
    ~Resistore();

    C_cartesiano impedenza() const override;
};

#endif //KALK_RESISTORE_H
