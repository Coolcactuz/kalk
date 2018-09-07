#ifndef KALK_EXCEPTION_ALERT_H
#define KALK_EXCEPTION_ALERT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <iostream>

class KalkExceptionAlert: public QWidget{

  Q_OBJECT

private:
  QVBoxLayout* l;
  QLabel* mostra_eccezione;
  QPushButton* emergenza_button;
public:
  KalkExceptionAlert(QString, bool = true);

  //~KalkExceptionAlert(){
	//std::cout << "distruttore kalkexceptionalert" << std::endl;
  //}

signals:
  void emergenza1();
};

#endif
