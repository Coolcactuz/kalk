#include "specialized_view.h"

specialized_view::specialized_view(): external_layout(new QVBoxLayout(this)),
header(new QHBoxLayout()), type_title(new QLabel(this)), upper(new QVBoxLayout()),
lower(new QHBoxLayout()), go_back(new QPushButton("BACK", this)),
keyboard(new QGridLayout()),display(new QPlainTextEdit(this)){

  external_layout->addLayout(header);
  external_layout->addLayout(upper);
  external_layout->addLayout(lower);

  header->addWidget(type_title);
  header->addWidget(go_back);

  upper->addWidget(display);

  lower->addLayout(keyboard);

  keyboard->addWidget(new KalkButton(-3, "AC", this), 0, 0);
  keyboard->addWidget(new KalkButton(-2, "DEL", this), 1, 0);
  keyboard->addWidget(new KalkButton(-1, "ENTER", this), 2, 0);

  QObject::connect(go_back, SIGNAL(clicked()), this, SIGNAL(back()));
}
