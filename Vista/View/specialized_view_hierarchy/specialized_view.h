#ifndef SPECIALIZED_VIEW_H
#define SPECIALIZED_VIEW_H

#include "../items/KalkButton.h"

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QSpinBox>


#include <string>
#include <iostream>


class specialized_view: public QWidget{

Q_OBJECT

protected:
  QLabel * type_title;
  QHBoxLayout* lower;

private:
  QVBoxLayout* external_layout;
  QHBoxLayout* header;
  QVBoxLayout* upper;
  
  QPushButton* go_back;
  QGridLayout* generic_keyboard;
  QPlainTextEdit* display;


public:

  specialized_view();
  /*
  virtual ~specialized_view() {
    std::cout << "SONO IL DISTRUTTORE DI SPECIALIZED" << std::endl;
  }*/

signals:

  void back();

};


#endif
