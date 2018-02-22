//
// Created by luca on 03/01/18.
//

#include "Componente.h"

C_cartesiano Componente::operator+ (const Componente & c) const {
    return *( impedenza()+ c.impedenza());
}

C_cartesiano Componente::operator/ (const Componente & c) const {
    return *(*(impedenza()*c.impedenza()) / *(impedenza()+c.impedenza()));
}
