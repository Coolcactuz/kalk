//
// Created by luca on 01/08/18.
//

#ifndef KALK_DATABASE_HIERARCHY_H
#define KALK_DATABASE_HIERARCHY_H

#include <string>
#include "tupla.h"
#include "Hierarchy_Handler.h"

class Database_Hierarchy : public Hierarchy_Handler {
private:
    void load_operators();

public:
    Database_Hierarchy();
    ~Database_Hierarchy()=default;
    static tupla* create(std::string);

};


#endif //KALK_DATABASE_HIERARCHY_H
