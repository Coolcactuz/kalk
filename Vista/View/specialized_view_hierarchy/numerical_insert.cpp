#include "numerical_insert.h"

numerical_insert::numerical_insert(): numeric_keyboard(new QGridLayout()){
  lower->addLayout(numeric_keyboard);

  numeric_keyboard->addWidget(new KalkButton(7, "7", this), 0, 0);
  numeric_keyboard->addWidget(new KalkButton(8, "8", this), 0, 1);
  numeric_keyboard->addWidget(new KalkButton(9, "9", this), 0, 2);
  numeric_keyboard->addWidget(new KalkButton(4, "4", this), 1, 0);
  numeric_keyboard->addWidget(new KalkButton(5, "5", this), 1, 1);
  numeric_keyboard->addWidget(new KalkButton(6, "6", this), 1, 2);
  numeric_keyboard->addWidget(new KalkButton(1, "1", this), 2, 0);
  numeric_keyboard->addWidget(new KalkButton(2, "2", this), 2, 1);
  numeric_keyboard->addWidget(new KalkButton(3, "3", this), 2, 2);
  numeric_keyboard->addWidget(new KalkButton(0, "0", this), 3, 1);


    for(int j = 0; j < numeric_keyboard->count(); j++){
      QLayoutItem* aux = numeric_keyboard->itemAt(j);
      QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);
      if(aux){
        QWidget* qw = tmp->widget();
        KalkButton* kb = dynamic_cast<KalkButton*>(qw);
        QObject::connect(kb, SIGNAL(clicked()), display, SLOT(receiveString()));
      }
    }

}
