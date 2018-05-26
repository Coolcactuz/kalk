#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../View/startup_view.h"
#include "../View/specialized view hierarchy/VCircuit.h"
#include <QObject>
#include <iostream>


class controller: public QObject{

Q_OBJECT

private:
  int datatype;
  startup_view* startup;
  specialized_view* specialized;


public:
  controller();
  ~controller();

  void start();

  //int getDatatype() const {return datatype;}

public slots:
  void setData(int);

};

#endif
