#ifndef SELECT_TYPE_BUTTON_H
#define SELECT_TYPE_BUTTON_H

#include <QPushButton>
#include <string>

class selectTypeButton: public QPushButton{

private:
  int data_number;

public:
  selectTypeButton(int d, std::string s = "", QWidget* p = 0): data_number(d),
    QPushButton(s, p) {}

  int getDataNumber() const {return data_number;}
};

#endif
