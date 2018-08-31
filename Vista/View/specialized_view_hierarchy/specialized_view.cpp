#include "specialized_view.h"

specialized_view::specialized_view(): type_title(new QLabel(this)), lower(new QHBoxLayout()), display(new KalkPlainTextEdit(this)),
  external_layout(new QVBoxLayout(this)), header(new QHBoxLayout()),  upper(new QVBoxLayout()),
  go_back(new QPushButton("BACK", this)), generic_keyboard(new QGridLayout()){

  external_layout->addLayout(header);
  external_layout->addLayout(upper);
  external_layout->addLayout(lower);

  header->addWidget(type_title);
  header->addWidget(go_back);

  upper->addWidget(display);

  lower->addLayout(generic_keyboard);

  generic_keyboard->addWidget(new KalkButton(-3, "AC", this), 0, 0);
  generic_keyboard->addWidget(new KalkButton(-2, "DEL", this), 1, 0);
  generic_keyboard->addWidget(new KalkButton(-1, "ENTER", this), 2, 0);

  QObject::connect(go_back, SIGNAL(clicked()), this, SIGNAL(back()));
}
