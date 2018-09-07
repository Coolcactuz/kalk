#ifndef KALK_BUTTON_H
#define KALK_BUTTON_H

#include <QPushButton>
#include <QString>

#include <iostream>

class KalkButton: public QPushButton{

Q_OBJECT

private:
  int data_number;

public:
  KalkButton(int d, QString s, QWidget* p = 0): QPushButton(s, p),
  data_number(d){}

  int getDataNumber() const {return data_number;}

  //~KalkButton(){
    //std::cout <<"distruttore di: "<< text().toUtf8().constData() << std::endl;
  //}
};

#endif
