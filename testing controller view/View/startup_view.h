#ifndef STARTUP_VIEW_H
#define STARTUP_VIEW_H

#include "KalkButton.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <iostream>

/* fornisce una interfaccia per la selezione del tipo, comunica l'informazione
al controller e cede il controllo */

class startup_view : public QWidget{

Q_OBJECT

private:

  QVBoxLayout* external_layout;
  QHBoxLayout* upper;
  QHBoxLayout* lower;
  QLabel* kalk_label;
  KalkButton* nota;
  KalkButton* circuito;
  QComboBox* tipi_numerici;

public:

  startup_view();
  ~startup_view();

public slots:

  void datatype_su();

signals:

  void exchange_datatype(int);

};

#endif
