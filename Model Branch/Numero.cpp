//
// Created by luca on 18/12/17.
//

#include "Numero.h"

double Numero::pi=3.1415926535;
double Numero::e=2.71828;

double Numero::rad_to_deg(double r) {
    return r*180/pi;
}

double Numero::deg_to_rad(double g) {
    return g*pi/180;
}
