#include "Controller/controller.h"

#include <QApplication>

int main(int argn, char ** args){

	QApplication app(argn, args);

	controller c;


	app.exec();
}
