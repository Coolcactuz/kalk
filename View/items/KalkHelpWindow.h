#ifndef KALK_HELP_WINDOW_H
#define KALK_HELP_WINDOW_H

#include <QLabel>

class KalkHelpWindow: public QWidget{
private:
  QLabel testo_aiuto;
public:
  void set_aiuto_raz();
  void set_aiuto_circuito();
  void set_aiuto_complesso();
  void set_aiuto_tupla();
};

#endif
