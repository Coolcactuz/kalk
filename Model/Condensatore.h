
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
    Condensatore():capacita(0){}
    ~Condensatore();

    C_cartesiano impedenza() const override;
};

#endif //KALK_CONDENSATORE_H
