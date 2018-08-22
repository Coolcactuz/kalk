#ifndef SPECIALIZED_VIEW_H
#define SPECIALIZED_VIEW_H

#include "../items/KalkButton.h"

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPlainTextEdit>


#include <string>
#include <iostream>


class specialized_view: public QWidget{

Q_OBJECT

protected:

  QVBoxLayout* external_layout;
  QHBoxLayout* header;
  QLabel * type_title;
  QVBoxLayout* upper;
  QHBoxLayout* lower;

private:

  QPushButton* go_back;
  QGridLayout* keyboard;
  QPlainTextEdit* display;


public:

  specialized_view();
  virtual ~specialized_view() {}


//ridimensiona la vista affinchè occupi il massimo dello schermo
  virtual void resize_max() =0;

signals:

//segnale generico comune a tutte le viste, invia dati al controller
  void sendData(std::string);

  void goBack_CStart();
};


#endif
