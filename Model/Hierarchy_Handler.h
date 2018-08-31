//
// Created by luca on 02/08/18.
//

#ifndef KALK_HIERARCHY_HANDLER_H
#define KALK_HIERARCHY_HANDLER_H

#include <list>

class Hierarchy_Handler {
protected:
    std::list<const char> class_operators;

    virtual void add_operator(const char);
    virtual void remove_operator(const char);

    virtual void load_operators() =0;

public:
    Hierarchy_Handler();
    virtual ~Hierarchy_Handler();
    virtual bool is_operator(const char) const;
    bool operator==(Hierarchy_Handler&) const;
//    bool operator!=(Hierarchy_Handler&) const;
};


#endif //KALK_HIERARCHY_HANDLER_H
