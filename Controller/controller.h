#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Vista/View/controller_view.h"
#include "../Model/parser.h"

#include <string>

#include <QObject>

class controller: public QObject{

Q_OBJECT

private:

  controller_view* cv;

  int tipo_corrente;
  Dato* oggetto_corrente;
  QString from_gui;

  //void inizia_sessione();

public:

  controller();
  ~controller();

public slots:

  void defineTC(int);
  void data_GUI_to_controller(QString);

};

#endif
