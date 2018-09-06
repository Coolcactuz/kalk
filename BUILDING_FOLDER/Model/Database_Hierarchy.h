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
    tupla* create(std::string) const;
};


#endif //KALK_DATABASE_HIERARCHY_H
