#include "startup_view.h"
#include <QApplication>

int main(int argn, char ** args){

	QApplication app(argn, args);

	startup_view s;
  s.show();
	std::cout << "inizio" << std::endl;

	app.exec();
}
