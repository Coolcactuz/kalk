//
// Created by luca on 01/08/18.
//

#ifndef KALK_CIRCUIT_HIERARCHY_H
#define KALK_CIRCUIT_HIERARCHY_H

#include "Resistore.h"
#include "Induttore.h"
#include "Condensatore.h"
#include "Hierarchy_Handler.h"

class Circuit_Hierarchy : public Hierarchy_Handler {
private:
    void load_operators();

public:
    Circuit_Hierarchy();
    Componente* create(std::string) const;

//    C_cartesiano impEquivalente() const ;
    C_cartesiano Corrente_totale(const C_cartesiano&) const ;

};


#endif //KALK_CIRCUIT_HIERARCHY_H
