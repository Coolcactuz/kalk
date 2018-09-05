//
// Created by luca on 02/08/18.
//

#ifndef KALK_HIERARCHY_HANDLER_H
#define KALK_HIERARCHY_HANDLER_H

#include <list>
#include <string>
#include <iostream>
#include "Dato.h"

class Hierarchy_Handler {
protected:
    std::list<char> class_operators;

    virtual void load_operators() =0;

public:
    Hierarchy_Handler();
    virtual ~Hierarchy_Handler() {
        std::cout << "distruttore hh" << '\n';

    }

    void add_operator(char);
    void remove_operator(char);
    virtual bool is_operator(char) const;
    virtual Dato* create(std::string)const =0;
    bool operator==(Hierarchy_Handler&) const;
//    bool operator!=(Hierarchy_Handler&) const;
};


#endif //KALK_HIERARCHY_HANDLER_H
