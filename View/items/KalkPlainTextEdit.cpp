#include "KalkPlainTextEdit.h"


void KalkPlainTextEdit::write_on_kpte() {

  KalkButton* aux = qobject_cast<KalkButton*>(sender());

  if(aux){

    int dn = aux->getDataNumber();

    if(dn >= 0){
      setPlainText(toPlainText() + aux->text());
    }
    else{
      switch (dn) {

        case -3:
          clear();
        break;

        default:
        {
          QString tmp = toPlainText();
          tmp.chop(1);
          setPlainText(tmp);
        }
        break;
      }
    }
  }
  else{
    //----------------
    //gestire eccezione cast fallito
    //----------------
  }

}

// void KalkPlainTextEdit::show_text(QString qs){
//   setPlainText(qs);
// }
