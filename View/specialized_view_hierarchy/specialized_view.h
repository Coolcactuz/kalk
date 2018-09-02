#ifndef SPECIALIZED_VIEW_H
#define SPECIALIZED_VIEW_H

//#include "../items/KalkButton.h"
#include "../items/KalkPlainTextEdit.h"
#include "../items/KalkHelpWindow.h"

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDoubleSpinBox>


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
  KalkHelpWindow* help_window;


public:

  specialized_view();
  ~specialized_view();

signals:

  void back();

  void inviaQS(QString);

  void inviaSORaz(int);
  void inviaSOComplesso(int);

  void specialized_view_inviaVolt(double);
  void specialized_view_inviaFreq(double);

public slots:

  void raccogli_testo_corrente();
  void mostra_result(QString);

  void specops_raz();
  void specops_complesso();

  void helpRaz();
  void helpComplesso();
  void helpCircuito();
  void helpTupla();

};

#endif
