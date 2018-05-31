#include <QApplication>
#include "VCircuit.h"

int main(int argn, char** args){

  QApplication app(argn, args);

  specialized_view* vc = new VCircuit();
  vc->show();

  return app.exec();
}
