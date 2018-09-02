#include "KalkHelpWindow.h"

KalkHelpWindow::KalkHelpWindow(): l_khw(new QVBoxLayout(this)), testo_aiuto(new QPlainTextEdit("", this)),
                                            b_khw(new QPushButton("CHIUDI", this)){

  l_khw->addWidget(testo_aiuto);
  l_khw->addWidget(b_khw);

  testo_aiuto->setReadOnly(true);

  QObject::connect(b_khw, SIGNAL(clicked()), this, SLOT(close()));

}

void KalkHelpWindow::set_aiuto_raz(){
  testo_aiuto->appendPlainText("Questa vista permette la gestione del tipo Razionale.");
  testo_aiuto->appendPlainText("\n\nUn Razionale puo  essere espresso nei seguenti modi:");
  testo_aiuto->appendPlainText("\na) x/y -> dove x e y possono essere positivi, negativi, con parte decimale o senza (es. 3/5, oppure 2.3/3.6)");
  testo_aiuto->appendPlainText("\nb) x -> dove x pu essere positivo, negativo, con parte decimale oppure no(es. 3, oppure 7.34)");
  testo_aiuto->appendPlainText("\nNota Bene: non vi devono essere spaziature tra il primo numero, lo slash e il secondo");
  testo_aiuto->appendPlainText("\n\nI seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:");
  testo_aiuto->appendPlainText("\n1) somma");
  testo_aiuto->appendPlainText("\n2) sottrazione");
  testo_aiuto->appendPlainText("\n3) moltiplicazione");
  testo_aiuto->appendPlainText("\n4) divisione");
  testo_aiuto->appendPlainText("\n5) elevamento a potenza");
  testo_aiuto->appendPlainText("\n\nPer usare gli operatori:");
  testo_aiuto->appendPlainText("\na) radice quadrata (sqrt)");
  testo_aiuto->appendPlainText("\nb) reciproco (1/x)");
  testo_aiuto->appendPlainText("\nc) conversione (<->)");
  testo_aiuto->appendPlainText("\nbisogna:");
  testo_aiuto->appendPlainText("\n1) inserire l operando sotto forma di stringa");
  testo_aiuto->appendPlainText("\n2) premere il tasto enter");
  testo_aiuto->appendPlainText("\n3) premere il tasto relativo all operatore");
}


void KalkHelpWindow::set_aiuto_complesso(){
  testo_aiuto->appendPlainText("Questa vista permette la gestione dei tipi Complesso Cartesiano e Complesso Polare.");
  testo_aiuto->appendPlainText("\nIl passaggio tra questi due tipi avviene in automatico all interno di questa vista.");
  testo_aiuto->appendPlainText("\n\nModi per esprimere un Complesso Polare:");
  testo_aiuto->appendPlainText("\n1) x<y -> dove x >= 0  decimale o no, y con parte decimale o senza (es. 2.3<4)");
  testo_aiuto->appendPlainText("\nModi per esprimere un Complesso Cartesiano:");
  testo_aiuto->appendPlainText("\n1) x+iy -> dove x e y possono essere positivi, negativi, con parte decimale o senza (es. 3+i7)");
  testo_aiuto->appendPlainText("\n2) x -> x può essere positivo o negativo, con parte decimale o senza");
  testo_aiuto->appendPlainText("\nNota Bene 1: la semplice scrittura di un numero x viene interpretata come Complesso Cartesiano");
  testo_aiuto->appendPlainText("\nNota Bene 2: non vi possono essere spaziature");
  testo_aiuto->appendPlainText("\n\nI seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:");
  testo_aiuto->appendPlainText("\n1) somma");
  testo_aiuto->appendPlainText("\n1) differenza");
  testo_aiuto->appendPlainText("\n1) moltiplicazione");
  testo_aiuto->appendPlainText("\n1) divisione");
  testo_aiuto->appendPlainText("\n\nPer usare gli operatori:");
  testo_aiuto->appendPlainText("\nb) coniugato (¬)");
  testo_aiuto->appendPlainText("\nc) conversione (<->)");
  testo_aiuto->appendPlainText("\nbisogna:");
  testo_aiuto->appendPlainText("\n1) inserire l operando sotto forma di stringa");
  testo_aiuto->appendPlainText("\n2) premere il tasto enter");
  testo_aiuto->appendPlainText("\n3) premere il tasto relativo all operatore");
}

void KalkHelpWindow::set_aiuto_circuito(){
  testo_aiuto->appendPlainText("Questa vista permette la gestione del tipo Componente:");
  testo_aiuto->appendPlainText("\npermette infatti di effettuare operazioni tra Induttori, Condensatori, e Resistori.");
  testo_aiuto->appendPlainText("\nI selettori possono essere usati per settare la frequenza e il voltaggio.");
  testo_aiuto->appendPlainText("\n\nModi per esprimere un Induttore:");
  testo_aiuto->appendPlainText("\n1) Lx ->  x >= 0, con parte decimale o no (es. L45)");
  testo_aiuto->appendPlainText("\nModi per esprimere un Condensatore:");
  testo_aiuto->appendPlainText("\n1) Cx -> x >= 0 con parte decimale o senza (es. C7)");
  testo_aiuto->appendPlainText("\nModi per esprimere un Resistore:");
  testo_aiuto->appendPlainText("\n1) Rx -> x >= 0 con parte decimale o senza (es. R9)");
  testo_aiuto->appendPlainText("\nNota Bene: non vi possono essere spaziature");
  testo_aiuto->appendPlainText("\n\nI seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:");
  testo_aiuto->appendPlainText("\n1) serie (+)");
  testo_aiuto->appendPlainText("\n1) parallelo (/)");
}

void KalkHelpWindow::set_aiuto_tupla(){
  testo_aiuto->appendPlainText("Questa vista permette la gestione del tipo Tupla.");
  testo_aiuto->appendPlainText("\nUna tupla e  rappresentata da una o piu  coppie di elementi nella forma:");
  testo_aiuto->appendPlainText("\nMETADATO1,dato1,METADATO2,dato2,...METADATOn,daton");
  testo_aiuto->appendPlainText("\n\nRegole di sintassi per Tupla:");
  testo_aiuto->appendPlainText("\n1) La stringa nulla rappresenta la stringa nulla");
  testo_aiuto->appendPlainText("\n2) Essendo un insieme di coppie il numero totale di virgole deve essere dispari");
  testo_aiuto->appendPlainText("\n3) Non può iniziare con una virgola");
  testo_aiuto->appendPlainText("\n4) Non può finire con una virgola");
  testo_aiuto->appendPlainText("\n5) Non vi possono essere due o piu  virgole di seguito");
  testo_aiuto->appendPlainText("\n6) Non vi possono essere due o piu  metadati uguali");
  testo_aiuto->appendPlainText("\n7) Vi possono essere due o piu  dati uguali");
  testo_aiuto->appendPlainText("\n8) Non vi possono essere metadati o dati uguali alla stringa nulla");
  testo_aiuto->appendPlainText("\n\nES1. MARCA,apple,DISPOSITIVO,iphone,MODELLO,6s -> t1");
  testo_aiuto->appendPlainText("\nES2. MARCA,apple,DISPOSITIVO,appleTV,DISPONIBILE,si -> t2");
  testo_aiuto->appendPlainText("\n\nNota Bene 1: non vi possono essere spaziature");
  testo_aiuto->appendPlainText("\n\nI seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:");
  testo_aiuto->appendPlainText("\n1) differenza (-) -> se un METADATO appartiene a una sola delle due tuple, esso figurera  nella tupla risultato assieme al corrispondente dato");
  testo_aiuto->appendPlainText("\nES. t1-t2 = MODELLO,6s,DISPONIBILE,si");
  testo_aiuto->appendPlainText("\n\n2) intersezione (/) -> solo le coppie METADATO,dato comuni a entrambe le tuple formeranno l intersezione tra le due");
  testo_aiuto->appendPlainText("\nES. t1/t2 = MARCA,apple");
  testo_aiuto->appendPlainText("\n\n3) join (%) -> la tupla join e  ottenuta  sommando  alla tupla operando a sinistra le coppie dell operando destro con METADATO non comune");
  testo_aiuto->appendPlainText("\nES. t1%t2 = MARCA,apple,DISPOSITIVO,iphone,MODELLO,6s,DISPONIBILE,si");
  testo_aiuto->appendPlainText("\nES. t2%t1 = MARCA,apple,DISPOSITIVO,appleTV,DISPONIBILE,si,MODELLO,6s");
  testo_aiuto->appendPlainText("\n\nNota Bene 2: Attenzione, le operazioni sono CASE SENSITIVE");
}
