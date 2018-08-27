//
// Created by luca on 14/01/18.
//

#ifndef KALK_CIRCUITO_H
#define KALK_CIRCUITO_H

#include "parser.h"

class Circuito {
private:
    parser<Componente> circuit;
public:
    Circuito(std::string);
    ~Circuito() = default;

    Circuito operator=(const Circuito&);
};

#endif //KALK_CIRCUITO_H
