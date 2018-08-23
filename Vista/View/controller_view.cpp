#include "controller_view.h"

controller_view::controller_view(): StartupV(new startup_view()), SpecializedV(0) {
  QObject::connect(StartupV, SIGNAL(type_FStartupTController(int)), this, SLOT(createSpecialized(int)));

  setCenterOfMonitor(StartupV);
  StartupV->show();
}

void controller_view::setCenterOfMonitor(QWidget* widget) const{
  QSize size = widget->sizeHint();
  QDesktopWidget* desktop = QApplication::desktop();
  int width = desktop->width();
  int height = desktop->height();
  int mw = size.width();
  int mh = size.height();
  int centerW = (width/2) - (mw/2);
  int centerH = (height/2) - (mh/2);
  widget->move(centerW, centerH);
}

void controller_view::createSpecialized(int i){

  switch(i){
    case 1:
      SpecializedV = new VRazionale();
      break;
    case 2:
      SpecializedV = new VComplesso();
      break;
    case 3:
      SpecializedV = new VTupla();
      break;
    case 4:
      SpecializedV = new VCircuito();
      break;
  }

  QObject::connect(SpecializedV, SIGNAL(back()), this, SLOT(createStartup()));

  StartupV->close();
  delete StartupV;
  StartupV = 0;

  setCenterOfMonitor(SpecializedV);
  SpecializedV->show();
}


void controller_view::createStartup(){

  StartupV = new startup_view();
  QObject::connect(StartupV, SIGNAL(type_FStartupTController(int)), this, SLOT(createSpecialized(int)));

  SpecializedV->close();
  delete SpecializedV;
  SpecializedV = 0;

  setCenterOfMonitor(StartupV);
  StartupV->show();
}


controller_view::~controller_view(){

  if(StartupV)
    delete StartupV;

  if(SpecializedV)
    delete SpecializedV;

  std::cout << "SONO IL DISTRUTTORE DI CONTROLLER VIEW" << std::endl;

}
