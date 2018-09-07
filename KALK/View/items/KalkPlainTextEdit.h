#ifndef KALK_PLAINTEXTEDIT_H
#define KALK_PLAINTEXTEDIT_H

#include <QPlainTextEdit>
#include <QString>

#include <iostream>

#include "KalkButton.h"
// #include "../specialized_view_hierarchy/VTupla.h"
// #include "../specialized_view_hierarchy/VCircuito.h"
// #include "../specialized_view_hierarchy/VComplesso.h"
// #include "../specialized_view_hierarchy/VRazionale.h"


class KalkPlainTextEdit: public QPlainTextEdit{

  Q_OBJECT

public:
  KalkPlainTextEdit(QWidget* p = 0): QPlainTextEdit(p) {}

//  ~KalkPlainTextEdit(){
//      std::cout << "distruttore kpte" << std::endl;
//  }

public slots:
  void write_on_kpte();
};

#endif
