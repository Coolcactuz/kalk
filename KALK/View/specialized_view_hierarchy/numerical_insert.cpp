#include "numerical_insert.h"

numerical_insert::numerical_insert(): numeric_keyboard(new QGridLayout()){
  lower->addLayout(numeric_keyboard);

  numeric_keyboard->addWidget(new KalkButton(7, "7"), 0, 0);
  numeric_keyboard->addWidget(new KalkButton(8, "8"), 0, 1);
  numeric_keyboard->addWidget(new KalkButton(9, "9"), 0, 2);
  numeric_keyboard->addWidget(new KalkButton(4, "4"), 1, 0);
  numeric_keyboard->addWidget(new KalkButton(5, "5"), 1, 1);
  numeric_keyboard->addWidget(new KalkButton(6, "6"), 1, 2);
  numeric_keyboard->addWidget(new KalkButton(1, "1"), 2, 0);
  numeric_keyboard->addWidget(new KalkButton(2, "2"), 2, 1);
  numeric_keyboard->addWidget(new KalkButton(3, "3"), 2, 2);
  numeric_keyboard->addWidget(new KalkButton(0, "0"), 3, 1);


    for(int j = 0; j < numeric_keyboard->count(); j++){

      QLayoutItem* aux = numeric_keyboard->itemAt(j);
      QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);

      if(tmp){
        QWidget* qw = tmp->widget();
        KalkButton* kb = dynamic_cast<KalkButton*>(qw);

        if(kb){
          QObject::connect(kb, SIGNAL(clicked()), display, SLOT(write_on_kpte()));
        }
      }
    }

}
