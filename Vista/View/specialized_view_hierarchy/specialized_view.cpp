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

  for(int i = 0; i < generic_keyboard->count(); i++){
    QLayoutItem* aux = generic_keyboard->itemAt(i);
    QWidgetItem* tmp = dynamic_cast<QWidgetItem*>(aux);

    if(tmp){
      QWidget* qw = tmp->widget();
      KalkButton* kb = dynamic_cast<KalkButton*>(qw);

      if(kb){

        if(kb->getDataNumber() == -1){
          QObject::connect(kb, SIGNAL(clicked()), this, SLOT(raccogli_testo_corrente()));
        }
        else{
          QObject::connect(kb, SIGNAL(clicked()), display, SLOT(write_on_kpte()));
        }

      }
    }

  }

  QObject::connect(go_back, SIGNAL(clicked()), this, SIGNAL(back()));
}

void specialized_view::raccogli_testo_corrente(){
  QString aux = display->toPlainText();
  emit inviaQS(aux);
}
