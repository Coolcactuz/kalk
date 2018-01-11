//
// Created by luca on 03/01/18.
//

#ifndef KALK_COMPONENTE_H
#define KALK_COMPONENTE_H

#include "Macro.h"
#include "C_cartesiano.h"

class Componente {
public:
    virtual std::string getName() const=0;
    virtual C_cartesiano impedenza() const=0;


};


#endif //KALK_COMPONENTE_H
