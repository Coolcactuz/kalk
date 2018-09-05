#ifndef KALK_HELP_WINDOW_H
#define KALK_HELP_WINDOW_H

#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

class KalkHelpWindow: public QWidget{

  Q_OBJECT

private:
  QVBoxLayout* l_khw;
  QPlainTextEdit* testo_aiuto;
  QPushButton* b_khw;

public:

  KalkHelpWindow();

  void set_aiuto_raz() const;
  void set_aiuto_circuito() const;
  void set_aiuto_complesso() const;
  void set_aiuto_tupla() const;
};

#endif
