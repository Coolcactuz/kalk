//
// Created by luca on 03/01/18.
//

#ifndef KALK_COMPONENTE_H
#define KALK_COMPONENTE_H

#include "Circuito.h"

class Componente {
public:
    virtual C_cartesiano impedenza() const=0;
    virtual double ddp_ai_capi() const=0;
    virtual double potenza() const=0;
};


#endif //KALK_COMPONENTE_H
