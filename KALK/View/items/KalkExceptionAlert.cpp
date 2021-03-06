#include "KalkExceptionAlert.h"

KalkExceptionAlert::KalkExceptionAlert(QString qs, bool b): l(new QVBoxLayout(this)),
        mostra_eccezione(new QLabel(qs)), emergenza_button(new QPushButton()){

  setWindowFlags(Qt::FramelessWindowHint);

  if(b){
    emergenza_button->setText("CHIUDI");
    QObject::connect(emergenza_button, SIGNAL(clicked()), this, SLOT(close()));
  }
  else{
    emergenza_button->setText("PREMI QUI PER CHIUDERE L'APPLICATIVO");
    QObject::connect(emergenza_button, SIGNAL(clicked()), this, SIGNAL(emergenza1()));

  }

  l->addWidget(mostra_eccezione);
  l->addWidget(emergenza_button);
}
