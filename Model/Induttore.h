#ifndef KALK_INDUTTANZA_H
#define KALK_INDUTTANZA_H


#include "Componente.h"
#include "Circuito.h"

class Induttore: public Componente{
private:
    double induttanza;
public:
    Induttore(double);
    Induttore(std::string);
    Induttore(): induttanza(0){}
    ~Induttore();

    C_cartesiano impedenza() const override;
};

#endif //KALK_INDUTTANZA_H
