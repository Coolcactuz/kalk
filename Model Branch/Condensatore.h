//
// Created by luca on 10/01/18.
//

#ifndef KALK_CONDENSATORE_H
#define KALK_CONDENSATORE_H


#include "Componente.h"
#include "Circuito.h"

class Condensatore: public Componente{
private:
    double capacita;
public:
    Condensatore(double);
    Condensatore(std::string);
    Condensatore();
    ~Condensatore ();

    C_cartesiano impedenza() const override;
};

#endif //KALK_CONDENSATORE_H
