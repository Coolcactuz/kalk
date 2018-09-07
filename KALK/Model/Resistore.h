#ifndef KALK_RESISTORE_H
#define KALK_RESISTORE_H


#include "Componente.h"

class Resistore : public Componente{
private:
    double resistenza;
public:
    Resistore(double);
    Resistore(std::string);
    Resistore();

    bool operator== (const Dato &) const;

    std::string toString() const;
    double getResistenza() const;
    C_cartesiano impedenza() const override;
};

#endif //KALK_RESISTORE_H
