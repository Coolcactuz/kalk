//
// Created by luca on 07/12/17.
//

#ifndef KALK_RAZ_H
#define KALK_RAZ_H

#include <iostream>
using std::cout;

class Raz {
private:
    long num;
    long den;
public:
    Raz(int n);
    Raz(long n, long d);
    Raz(double d);

    explicit operator double() const;
    Raz& operator= (const Raz&);
    Raz operator+ (const Raz&);
    Raz operator- (const Raz&);
    Raz operator* (const Raz&);
    Raz operator/ (Raz);
    Raz operator^ (int);

    long getNum()const {return num;}
    long getDen()const {return den;}
    int getMCD(long, long)const ;
    Raz reciproco()const ;
    void semplifica();
    long double radice_quadrata()const ;
    long double radice_cubica()const ;
};

#endif //KALK_RAZ_H
