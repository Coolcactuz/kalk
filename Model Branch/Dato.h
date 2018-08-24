//
// Created by luca on 18/12/17.
//

#ifndef KALK_DATO_H
#define KALK_DATO_H

#include <iostream>
#include <cmath>


class Dato{
public:
    virtual ~Dato() = default;
    virtual bool operator==(const Dato&) const =0;
    bool operator!=(const Dato& d) const{
        return !(*this == d);
    }
    virtual Dato& operator=(const Dato&) =0;
};


#endif //KALK_NUMERO_H
