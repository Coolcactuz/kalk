#ifndef STARTUP_VIEW_H
#define STARTUP_VIEW_H

#include "../items/KalkButton.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <iostream>

/* fornisce una interfaccia per la selezione del tipo */

class startup_view : public QWidget{

Q_OBJECT

private:

  QVBoxLayout* external_layout;
  QHBoxLayout* upper;
  QHBoxLayout* lower;

  QLabel* kalk_label;
  KalkButton* tupla;
  KalkButton* circuito;
  KalkButton* razionale;
  KalkButton* complesso;


public:

  startup_view();

  //~startup_view();

signals:

  void type_FStartupTController(int);

private slots:

  void type_FButtonTStartup();

};

#endif
