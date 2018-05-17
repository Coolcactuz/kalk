#ifndef SELECT_TYPE_BUTTON_H
#define SELECT_TYPE_BUTTON_H

#include <QWidget>
#include <QPushButton>

class selectTypeButton: public QPushButton{

Q_OBJECT

private:
  int data_number;

public:
  selectTypeButton(int d, const char* s = "", QWidget* p = 0):   QPushButton(s, p),
  data_number(d){}

  int getDataNumber() const {return data_number;}
};

#endif
