#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../View/controller_view.h"
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

signals:

  void data_controller_to_GUI(QString);

public slots:

  void defineTC(int);
  void data_GUI_to_controller(QString);

  void soraz_logic(int);
  void socomplesso_logic(int);

};

#endif
