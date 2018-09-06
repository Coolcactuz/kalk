#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../View/controller_view.h"
#include "../Model/parser.h"

#include <string>
#include <stdlib.h>
#include <iostream>

#include <QObject>

class controller: public QObject{

Q_OBJECT

private:

  controller_view* cv;

  int tipo_corrente;
  //Dato* oggetto_corrente;
  QString from_gui;

  Complesso* conv_complesso;
  double conv_raz;

  void check_string(std::string) const;

  //void inizia_sessione();

public:

  controller();
  ~controller();

signals:

  void data_controller_to_GUI(QString);

  void CtV_exception(QString, bool);

private slots:

  void defineTC(int);
  void data_GUI_to_controller(QString);

  void soraz_logic(int);
  void socomplesso_logic(int);

  void circuito_cambia_volt(double);
  void circuito_cambia_freq(double);

  void gestisci_emergenza();
};

#endif
