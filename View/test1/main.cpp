#include <QApplication>
#include "startup.h"

int main(int argv, char** args){

	QApplication app(argv, args);

	Startup s;
	s.show();

	return app.exec();
}
