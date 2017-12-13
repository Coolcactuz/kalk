//
// Created by luca on 07/12/17.
//

#ifndef KALK_RAZ_H
#define KALK_RAZ_H

#include "numero.h"

class Raz : public Numero {
private:
    int num;
    int den;
public:
    Raz(int n);
    Raz(int n, int d);
    int getNum(){return num;}
    int getDen(){return den;}
    int getMCD(int, int);
    Raz reciproco();
    explicit operator double() const;
    void semplifica();

    Raz& operator= (const Raz&);
    Raz operator+ (const Raz&);
    Raz operator- (const Raz&);
    Raz operator* (const Raz&);
    Raz operator/ (Raz);
    Raz operator^ (int);

    Raz(double d);

};

#endif //KALK_RAZ_H
