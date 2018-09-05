//
// Created by luca on 07/12/17.
//

#ifndef KALK_RAZ_H
#define KALK_RAZ_H

#include "Numero.h"

class Raz : public Numero {

private:

    long num;
    long den;

    void semplifica ();

public:
    Raz ();
    Raz (long, long);
    Raz (std::string);
    Raz (double);

    explicit operator double () const;
    Raz* operator+ (const Numero *) const;
    Raz* operator- (const Numero *) const;
    Raz* operator* (const Numero *) const;
    Raz* operator/ (const Numero *) const;
    Raz* operator^ (int) const;
    bool operator== (const Dato&)const;
//    Raz& operator=(const Dato&);

    std::string toString() const;
    static Raz* solve_operation(const Dato*, const Dato*, char);
    long getNum () const;
    long getDen () const;
    int getMCD (long, long) const;
    Raz* reciproco () const;
    long double radice_quadrata () const;
};

std::ostream &operator<< (std::ostream &, const Raz &);

#endif //KALK_RAZ_H