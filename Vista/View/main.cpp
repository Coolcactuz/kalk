#include "specialized_view_hierarchy/VComplesso.h"
#include "specialized_view_hierarchy/VTupla.h"
#include "specialized_view_hierarchy/VCircuito.h"
#include "specialized_view_hierarchy/VRazionale.h"


#include <QApplication>

int main(int argn, char ** args){

	QApplication app(argn, args);

	VComplesso s;
  s.show();
	std::cout << "inizio" << std::endl;

	app.exec();
}
