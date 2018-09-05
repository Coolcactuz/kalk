#ifndef KALK_INDUTTANZA_H
#define KALK_INDUTTANZA_H


#include "Componente.h"

class Induttore: public Componente{
private:
    double induttanza;
public:
    Induttore(double);
    Induttore(std::string);
    Induttore();

    bool operator== (const Dato&) const;

    std::string toString() const;
    double getInduttanza() const;
    C_cartesiano impedenza() const override;
};

#endif //KALK_INDUTTANZA_H
