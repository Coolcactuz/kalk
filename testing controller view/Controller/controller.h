#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../View/view_manager.h"
#include <QObject>

class controller: public QObject{

Q_OBJECT

private:
  int datatype;
  view_manager* vm;

public:

  controller();
  ~controller();

  int getDatatype() const {return datatype;}

public slots:
  void setData(int);

};

#endif
