#ifndef KALK_NUMERO_H
#define KALK_NUMERO_H

#include <iostream>
#include <cmath>


class Numero{
public:

    virtual ~Numero() = default;

    virtual Numero* operator+(const Numero*)const =0;
    virtual Numero* operator-(const Numero*)const =0;
    virtual Numero* operator*(const Numero*)const =0;
    virtual Numero* operator/(const Numero*)const =0;

    virtual Numero* solve_operation(Numero*, Numero*, char) const =0;

    static double pi;
    static double e;
    static double deg_to_rad(double);
    static double rad_to_deg(double);
};


#endif //KALK_NUMERO_H
