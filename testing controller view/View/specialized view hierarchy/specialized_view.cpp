#include "specialized_view.h"

specialized_view::specialized_view(view_manager* pointer): vm(pointer),
external_layout(new QVBoxLayout(this)), upper(new QVBoxLayout()),
lower(new QGridLayout()), display(new QPlainTextEdit(this)) {

  external_layout->addLayout(upper);
  external_layout->addLayout(lower);

  upper->addWidget(display);


  //riempire il QGridLayout con i KalkButton

  

  //connect e altra roba qua
}
