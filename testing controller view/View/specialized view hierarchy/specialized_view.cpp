#include "specialized_view.h"

specialized_view::specialized_view(view_manager* pointer): vm(pointer),
external_layout(new QVBoxLayout(this)), upper(new QVBoxLayout()),
lower(new QGridLayout()), display(new QPlainTextEdit(this)) {

  external_layout->addLayout(upper);
  external_layout->addLayout(lower);

  upper->addWidget(display);


  //riempire il QGridLayout con i KalkButton

  lower->addWidget(new KalkButton(7, "7", this), 0, 0);
  lower->addWidget(new KalkButton(8, "8", this), 0, 1);
  lower->addWidget(new KalkButton(9, "9", this), 0, 2);
  lower->addWidget(new KalkButton(4, "4", this), 1, 0);
  lower->addWidget(new KalkButton(5, "5", this), 1, 1);
  lower->addWidget(new KalkButton(6, "6", this), 1, 2);
  lower->addWidget(new KalkButton(1, "1", this), 2, 0);
  lower->addWidget(new KalkButton(2, "2", this), 2, 1);
  lower->addWidget(new KalkButton(3, "3", this), 2, 2);
  lower->addWidget(new KalkButton(0, "0", this), 3, 1);
  lower->addWidget(new KalkButton(-2, "AC", this), 3, 0);
  lower->addWidget(new KalkButton(-3, ".", this), 3, 2);
  lower->addWidget(new KalkButton(-1, "E", this), 2, 3, 1, 2);


  //connect e altra roba qua
}

//ritorna il puntatore al KalkButton con testo s
KalkButton* specialized_view::getKey(std::string s) const{
  KalkButton* result = 0;

  for(int idx = 0; idx < lower->count(); idx++){
    
  }
}
