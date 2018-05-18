#ifndef KALK_BUTTON_H
#define KALK_BUTTON_H

#include <QWidget>
#include <QPushButton>

class KalkButton: public QPushButton{

Q_OBJECT

private:
  int data_number;

public:
  KalkButton(int d, const char* s = "", QWidget* p = 0):   QPushButton(s, p),
  data_number(d){}

  int getDataNumber() const {return data_number;}
};

#endif
