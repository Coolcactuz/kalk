#ifndef CONTROLLER_VIEW_H
#define CONTROLLER_VIEW_H

#include <iostream>
#include <string>

#include <QObject>

#include "startup/startup_view.h"
#include "specialized_view_hierarchy/VTupla.h"
#include "specialized_view_hierarchy/VCircuito.h"
#include "specialized_view_hierarchy/VRazionale.h"
#include "specialized_view_hierarchy/VComplesso.h"


#include <QSize>
#include <QDesktopWidget>
#include <QApplication>


class controller_view: public QObject{

  Q_OBJECT

private:

  startup_view* StartupV;
  specialized_view* SpecializedV;


public:

  controller_view();
  ~controller_view();

signals:

  void inviaTipo(int);
  void inviaStringa(QString);
  void inviaResult(QString);

  void SOComplesso(int);
  void SORaz(int);

  void controller_view_inviaFreq(double);
  void controller_view_inviaVolt(double);

  void pass_exception(QString, bool);

  void emergenza3();

private slots:

  void createSpecialized(int);
  void createStartup();

};


#endif
