#ifndef KALK_EXCEPTION_ALERT_H
#define KALK_EXCEPTION_ALERT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class KalkExceptionAlert: public QWidget{
private:
  QVBoxLayout* l;
  QLabel* mostra_eccezione;
  QPushButton* emergenza_button;
public:
  KalkExceptionAlert(QString, bool = true);
signals:
  void emergenza1();
};

#endif
