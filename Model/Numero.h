//
// Created by luca on 18/12/17.
//

#ifndef KALK_NUMERO_H
#define KALK_NUMERO_H

#include <iostream>
#include <cmath>

class Numero{
/*
protected:
  static double subparse(std::string s);
*/

public:

    virtual Numero* operator+(const Numero*)const =0;
    virtual Numero* operator-(const Numero*)const =0;
    virtual Numero* operator*(const Numero*)const =0;
    virtual Numero* operator/(const Numero*)const =0;

    static double pi;
    static double e;
    static double deg_to_rad(double);
    static double rad_to_deg(double);
};


#endif //KALK_NUMERO_H
