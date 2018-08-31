#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Vista/View/controller_view.h"
#include "../Model/parser.h"
#include <QObject>

class controller: public QObject{

Q_OBJECT

private:
  int datatype;
  view_manager* vm;

public:

  controller();

  int getDatatype() const {return datatype;}

public slots:
  void setData(int);

};

#endif
