//
// Created by luca on 03/01/18.
//

#include "Resistore.h"

Resistore::Resistore(C_cartesiano r):resistenza(r){}

C_cartesiano Resistore::impedenza() const{
    return resistenza;
}

double Resistore::ddp_ai_capi() const{

}

double Resistore::potenza() const{

}