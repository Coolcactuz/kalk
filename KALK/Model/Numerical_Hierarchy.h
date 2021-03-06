#ifndef KALK_NUMERICAL_HIERARCHY_H
#define KALK_NUMERICAL_HIERARCHY_H

#include "Raz.h"
#include "C_cartesiano.h"
#include "C_polare.h"
#include "Hierarchy_Handler.h"

class Numerical_Hierarchy : public Hierarchy_Handler {
private:
    void load_operators();

public:
    Numerical_Hierarchy();
    Complesso* create_complex(std::string) const;
    Raz* create(std::string) const;
};


#endif //KALK_NUMERICAL_HIERARCHY_H
