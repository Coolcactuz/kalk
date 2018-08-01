#include "specialized_view.h"

specialized_view::specialized_view(): external_layout(new QVBoxLayout(this)),
header(new QHBoxLayout()), type_title(new QLabel(this)), upper(new QVBoxLayout()),
lower(new QHBoxLayout()), go_back(new QPushButton("SELEZIONA TIPO", this)),
keyboard(new QGridLayout()),display(new QPlainTextEdit(this)){

  external_layout->addLayout(header);
  external_layout->addLayout(upper);
  external_layout->addLayout(lower);

  header->addWidget(type_title);
  header->addWidget(go_back);

  lower->addLayout(keyboard);

  upper->addWidget(display);


  //riempire il QGridLayout con i KalkButton

  keyboard->addWidget(new KalkButton(7, "7", this), 0, 0);
  keyboard->addWidget(new KalkButton(8, "8", this), 0, 1);
  keyboard->addWidget(new KalkButton(9, "9", this), 0, 2);
  keyboard->addWidget(new KalkButton(4, "4", this), 1, 0);
  keyboard->addWidget(new KalkButton(5, "5", this), 1, 1);
  keyboard->addWidget(new KalkButton(6, "6", this), 1, 2);
  keyboard->addWidget(new KalkButton(1, "1", this), 2, 0);
  keyboard->addWidget(new KalkButton(2, "2", this), 2, 1);
  keyboard->addWidget(new KalkButton(3, "3", this), 2, 2);
  keyboard->addWidget(new KalkButton(0, "0", this), 3, 1);
  keyboard->addWidget(new KalkButton(-4, "AC", this), 0, 3);
  keyboard->addWidget(new KalkButton(-3, "DEL", this), 1, 3);
  keyboard->addWidget(new KalkButton(-2, ".", this), 2, 3);
  keyboard->addWidget(new KalkButton(-1, "ENTER", this), 3, 3);


  //connect e altra roba qua

  QObject::connect(go_back, SIGNAL(clicked()), this, SIGNAL(goBack_CStart()));
}

/*
void specialized_view::test(){
  std::cout << "goBack_CStart"<< std::endl;
}
*/
