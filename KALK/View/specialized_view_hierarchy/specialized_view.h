#ifndef SPECIALIZED_VIEW_H
#define SPECIALIZED_VIEW_H

//#include "../items/KalkButton.h"
#include "../items/KalkPlainTextEdit.h"
#include "../items/KalkHelpWindow.h"
#include "../items/KalkExceptionAlert.h"

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QSize>
#include <QDesktopWidget>
#include <QApplication>


#include <string>
#include <iostream>


class specialized_view: public QWidget{

Q_OBJECT

protected:
  QLabel* type_title;
  QPushButton* help;
  QHBoxLayout* lower;
  KalkPlainTextEdit* display;

private:
  QVBoxLayout* external_layout;
  QHBoxLayout* header;
  QVBoxLayout* upper;

  QPushButton* go_back;
  QGridLayout* generic_keyboard;
  KalkHelpWindow* help_window;
  KalkExceptionAlert* exception_handling;


public:

  specialized_view();
  ~specialized_view();

  static void setCenterOfMonitor(QWidget*);

signals:

  void back();

  void inviaQS(QString);

  void inviaSORaz(int);
  void inviaSOComplesso(int);

  void specialized_view_inviaVolt(double);
  void specialized_view_inviaFreq(double);

  void emergenza2();

private slots:
  void raccogli_testo_corrente();

  void specops_raz();
  void specops_complesso();

  void helpRaz();
  void helpComplesso();
  void helpCircuito();
  void helpTupla();

public slots:
  void mostra_result(QString) const;
  void handle_exception(QString, bool);
};

#endif
