#include "view_manager.h"
#include <QApplication>

int main(int argn, char ** args){

	QApplication app(argn, args);

	view_manager vm;

	app.exec();

}
