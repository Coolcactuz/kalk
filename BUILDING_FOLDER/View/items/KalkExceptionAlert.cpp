#include "KalkExceptionAlert.h"

KalkExceptionAlert::KalkExceptionAlert(QString qs, bool b): l(new QVBoxLayout(this)),
        mostra_eccezione(new QLabel(qs, this)), emergenza_button(new QPushButton(this)){

  setWindowFlags(Qt::FramelessWindowHint);

  if(b){
    emergenza_button->setText("CHIUDI");
    QObject::connect(emergenza_button, SIGNAL(clicked()), this, SLOT(close()));
  }
  else{
    emergenza_button->setText("PREMI QUI PER CHIUDERE L'APPLICATIVO");
    if(QObject::connect(emergenza_button, SIGNAL(clicked()), this, SIGNAL(emergenza1())))
        std::cout << "connessione errore logico" << std::endl;

  }

  l->addWidget(mostra_eccezione);
  l->addWidget(emergenza_button);
}
