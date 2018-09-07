#ifndef KALK_CONDENSATORE_H
#define KALK_CONDENSATORE_H


#include "Componente.h"

class Condensatore: public Componente{
private:
    double capacita;
public:
    Condensatore(double);
    Condensatore(std::string);
    Condensatore();

    bool operator== (const Dato&) const;

    std::string toString() const;
    double getCapacita() const;
    C_cartesiano impedenza() const override;
};

#endif //KALK_CONDENSATORE_H
