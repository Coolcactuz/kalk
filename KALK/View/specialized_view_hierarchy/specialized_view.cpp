#include "specialized_view.h"

specialized_view::specialized_view(): type_title(new QLabel()), help(new QPushButton("SERVE AIUTO?")),
  lower(new QHBoxLayout()), display(new KalkPlainTextEdit()), external_layout(new QVBoxLayout(this)),
  header(new QHBoxLayout()),  upper(new QVBoxLayout()), go_back(new QPushButton("BACK")),
  generic_keyboard(new QGridLayout()), help_window(0), exception_handling(0){

  external_layout->addLayout(header);
  external_layout->addLayout(upper);
  external_layout->addLayout(lower);

  header->addWidget(type_title);
  header->addWidget(help);
  header->addWidget(go_back);

  upper->addWidget(display);

  lower->addLayout(generic_keyboard);

  generic_keyboard->addWidget(new KalkButton(-3, "AC"), 0, 0);
  generic_keyboard->addWidget(new KalkButton(-2, "DEL"), 0, 1);
  generic_keyboard->addWidget(new KalkButton(0, "("), 1, 0);
  generic_keyboard->addWidget(new KalkButton(1, ")"), 1, 1);
  generic_keyboard->addWidget(new KalkButton(2, "."), 2, 0);
  generic_keyboard->addWidget(new KalkButton(-1, "ENTER"), 2, 1);

  for(int i = 0; i < generic_keyboard->count(); i++){
    QLayoutItem* aux = generic_keyboard->itemAt(i);
    QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);

    if(tmp){
      QWidget* qw = tmp->widget();
      KalkButton* kb = dynamic_cast<KalkButton*>(qw);

      if(kb){

        if(kb->getDataNumber() == -1){
          QObject::connect(kb, SIGNAL(clicked()), this, SLOT(raccogli_testo_corrente()));
        }
        else{
          QObject::connect(kb, SIGNAL(clicked()), display, SLOT(write_on_kpte()));
        }

      }
    }

  }

  QObject::connect(go_back, SIGNAL(clicked()), this, SIGNAL(back()));
}

void specialized_view::raccogli_testo_corrente(){
  QString aux = display->toPlainText();
  emit inviaQS(aux);
}

void specialized_view::mostra_result(QString res) const{
  display->setPlainText(res);
}

void specialized_view::specops_raz(){
  KalkButton* aux = qobject_cast<KalkButton*>(sender());

  if(aux){
    emit inviaSORaz(aux->getDataNumber());
  }
}

void specialized_view::setCenterOfMonitor(QWidget* widget){
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

void specialized_view::handle_exception(QString s, bool b){

  if(exception_handling){
    delete exception_handling;
  }

  if(b){
    display->clear();
    exception_handling = new KalkExceptionAlert(s);
    setCenterOfMonitor(exception_handling);
    exception_handling->show();
  }
  else{
    exception_handling = new KalkExceptionAlert(s, false);
    QObject::connect(exception_handling, SIGNAL(emergenza1()), this, SIGNAL(emergenza2()));
    setCenterOfMonitor(exception_handling);
    exception_handling->show();
  }
}



void specialized_view::specops_complesso(){
  KalkButton* aux = qobject_cast<KalkButton*>(sender());

  if(aux){
    emit inviaSOComplesso(aux->getDataNumber());
  }

}

void specialized_view::helpRaz(){

  if(help_window){
    delete help_window;
  }

  help_window = new KalkHelpWindow();

  help_window->set_aiuto_raz();

  //hide();

  handle_exception(QString("ciao"), true);

  help_window->showMaximized();
}

void specialized_view::helpComplesso(){

  if(help_window){
    delete help_window;
  }

  help_window = new KalkHelpWindow();

  help_window->set_aiuto_complesso();

  help_window->showMaximized();
}

void specialized_view::helpCircuito(){
  if(help_window){
    delete help_window;
  }

  help_window = new KalkHelpWindow();

  help_window->set_aiuto_circuito();

  help_window->showMaximized();
}

void specialized_view::helpTupla(){
  if(help_window){
    delete help_window;
  }

  help_window = new KalkHelpWindow();

  help_window->set_aiuto_tupla();

  help_window->showMaximized();
}

specialized_view::~specialized_view(){
  if(help_window){
    delete help_window;
  }

  if(exception_handling){
    delete exception_handling;
  }
}
