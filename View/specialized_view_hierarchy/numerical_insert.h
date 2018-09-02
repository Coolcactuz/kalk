#ifndef NUMERICAL_INSERT_H
#define NUMERICAL_INSERT_H

#include "specialized_view.h"

class numerical_insert: public specialized_view{
private:
  QGridLayout* numeric_keyboard;
public:
  numerical_insert();
};

#endif
