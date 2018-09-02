#ifndef SPECIALIZED_VIEW_H
#define SPECIALIZED_VIEW_H

//#include "../items/KalkButton.h"
#include "../items/KalkPlainTextEdit.h"

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpinBox>


#include <string>
#include <iostream>


class specialized_view: public QWidget{

Q_OBJECT

protected:
  QLabel* type_title;
  QPushButton* help;
  QHBoxLayout* lower;
  KalkPlainTextEdit* display;

private:
  QVBoxLayout* external_layout;
  QHBoxLayout* header;
  QVBoxLayout* upper;

  QPushButton* go_back;
  QGridLayout* generic_keyboard;


public:

  specialized_view();
  /*
  virtual ~specialized_view() {
    std::cout << "SONO IL DISTRUTTORE DI SPECIALIZED" << std::endl;
  }*/

signals:

  void back();

  void inviaQS(QString);

  void inviaSORaz(int);
  void inviaSOComplesso(int);

public slots:

  void raccogli_testo_corrente();
  void mostra_result(QString);

  void specops_raz();
  void specops_complesso();
};

#endif
