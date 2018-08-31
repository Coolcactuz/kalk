#include "KalkPlainTextEdit.h"

void KalkPlainTextEdit::receiveString(){
  KalkButton* aux = qobject_cast<KalkButton*>(sender());

  if(aux){
    setPlainText(toPlainText() + aux->text());
  }
  else{
    //----------------
    //gestire eccezione cast fallito
    //----------------
  }
}
