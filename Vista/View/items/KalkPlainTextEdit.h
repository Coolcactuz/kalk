#ifndef KALK_PLAINTEXTEDIT_H
#define KALK_PLAINTEXTEDIT_H

#include <QPlainTextEdit>

#include "KalkButton.h"

class KalkPlainTextEdit: public QPlainTextEdit{

  Q_OBJECT

public:
  KalkPlainTextEdit(QWidget* p = 0): QPlainTextEdit(p) {}

public slots:
  void receiveString();
};

#endif
