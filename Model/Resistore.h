#ifndef KALK_RESISTORE_H
#define KALK_RESISTORE_H


#include "Componente.h"
#include "Circuito.h"

class Resistore : public Componente{
private:
    double resistenza;
public:
    Resistore(double);
    Resistore(std::string);
    Resistore(): resistenza(0){}
    ~Resistore();

    C_cartesiano impedenza() const override;
};

#endif //KALK_RESISTORE_H
