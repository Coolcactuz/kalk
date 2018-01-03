//
// Created by luca on 03/01/18.
//

#ifndef KALK_RESISTORE_H
#define KALK_RESISTORE_H


#include "Componente.h"

class Resistore : public Componente{
private:
    C_cartesiano resistenza;
private:
    Resistore(C_cartesiano);

    C_cartesiano impedenza() const ;
    double ddp_ai_capi() const;
    double potenza() const;
};


#endif //KALK_RESISTORE_H
