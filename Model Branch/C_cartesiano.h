//
// Created by luca on 19/12/17.
//

#ifndef KALK_C_CARTESIANO_H
#define KALK_C_CARTESIANO_H


#include "Complesso.h"

class C_polare;


class C_cartesiano: public Complesso {

private:

    double reale;
    double immaginaria;

public:

    C_cartesiano();
    C_cartesiano(double,double =0);
    C_cartesiano(const C_cartesiano&);
    C_cartesiano(std::string);
    ~C_cartesiano();

    C_cartesiano* operator+ (const Numero*)const;
    C_cartesiano* operator- (const Numero*)const;
    C_cartesiano* operator* (const Numero*)const;
    C_cartesiano* operator/ (const Numero*)const;
    bool operator== (const Dato&)const;
    C_cartesiano& operator=(const Dato&) const;

    double getReale() const;
    double getImmaginaria() const;
    C_cartesiano* coniugato() const override;
    static C_cartesiano* create(std::string);

    // Complesso* sub_create(std::string);
    Complesso* converti()const override;
    void stampa(std::ostream&)const;
};

std::ostream& operator<<(std::ostream&, const C_cartesiano&);

#endif //KALK_C_CARTESIANO_H
