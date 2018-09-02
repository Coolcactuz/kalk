#include "KalkHelpWindow.h"

void KalkHelpWindow::set_aiuto_raz(){
  testo_aiuto.setText("Questa vista permette la gestione del tipo Razionale.\n\n

                        Un Razionale può essere espresso nei seguenti modi:\n
                        a) x/y -> dove x e y possono essere positivi, negativi, con parte decimale o senza (es. 3/5, oppure 2.3/3.6)\n
                        b) x -> dove x può essere positivo, negativo, con parte decimale oppure no(es. 3, oppure 7.34)\n
                        NB: non vi devono essere spaziature tra il primo numero, lo slash e il secondo\n\n

                        I seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:\n
                        1) somma\n
                        2) sottrazione\n
                        3) moltiplicazione\n
                        4) divisione\n
                        5) elevamento a potenza (es. (3/5)^2 )\n\n

                        Per usare gli operatori:\n
                        a) radice quadrata (sqrt)\n
                        b) reciproco (1/x)\n
                        c) conversione (<->)\n
                        bisogna:\n
                        1) inserire l'operando sotto forma di stringa\n
                        2) premere il tasto enter\n
                        3) premere il tasto relativo all'operatore");
}

void KalkHelpWindow::set_aiuto_complesso(){
  testo_aiuto.setText("Questa vista permette la gestione dei tipi Complesso Cartesiano e Complesso Polare.\n
                        Il passaggio tra questi due tipi avviene in automatico all'interno di questa vista.\n\n

                        Modi per esprimere un Complesso Polare:\n
                        1) x<y -> dove x >= 0  decimale o no, y con parte decimale o senza (es. 2.3<4)\n

                        Modi per esprimere un Complesso Cartesiano:\n
                        1) x+iy -> dove x e y possono essere positivi, negativi, con parte decimale o senza (es. 3+i7)\n
                        2) x -> x può essere positivo o negativo, con parte decimale o senza\n

                        NB 1: la semplice scrittura di un numero x viene interpretata come Complesso Cartesiano\n
                        NB 2: non vi possono essere spaziature\n\n

                        I seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:\n
                        1) somma\n
                        2) sottrazione\n
                        3) moltiplicazione\n
                        4) divisione\n\n

                        Per usare gli operatori:\n
                        a) coniugato (¬)\n
                        b) conversione (<->)\n
                        bisogna:\n
                        1) inserire l'operando sotto forma di stringa\n
                        2) premere il tasto enter\n
                        3) premere il tasto relativo all'operatore");
}

void KalkHelpWindow::set_aiuto_circuito(){
  testo_aiuto.setText("Questa vista permette la gestione del tipo Componente:\n
                        permette infatti di effettuare operazioni tra Induttori, Condensatori, e Resistori.\n\n

                        Modi per esprimere un Induttore:\n
                        1) Lx ->  x >= 0, con parte decimale o no (es. L45)\n

                        Modi per esprimere un Condensatore:\n
                        2) Cx -> x >= 0 con parte decimale o senza (es. C7)\n

                        Modi per esprimere un Resistore:\n
                        2) Rx -> x >= 0 con parte decimale o senza (es. R9)\n

                        NB: non vi possono essere spaziature\n\n

                        I seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:\n
                        1) serie (+)\n
                        2) parallelo (/)");
}

void KalkHelpWindow::set_aiuto_tupla(){
  testo_aiuto.setText("Questa vista permette la gestione del tipo Tupla.\n
                        Una tupla è rappresentata da una o più coppie di elementi nella forma:\n\n

                        METADATO1,dato1,METADATO2,dato2,...METADATOn,daton\n\n

                        Regole di sintassi per Tupla:\n
                        1) La stringa nulla rappresenta la stringa nulla\n
                        2) Essendo un insieme di coppie il numero totale di virgole deve essere dispari\n
                        3) Non può iniziare con una virgola\n
                        4) Non può finire con una virgola\n
                        5) Non vi possono essere due o più virgole di seguito\n
                        6) Non vi possono essere due o più metadati uguali\n
                        7) Vi possono essere due o più dati uguali\n
                        8) Non vi possono essere metadati o dati uguali alla stringa nulla\n\n

                        ES1. MARCA,apple,DISPOSITIVO,iphone,MODELLO,6s -> t1
                        ES2. MARCA,apple,DISPOSITIVO,appleTV,DISPONIBILE,si -> t2

                        NB 1: non vi possono essere spaziature\n\n

                        I seguenti operatori sono inseribili direttamente nella stringa che si vuol elaborare:\n
                        1) differenza (-) -> se un METADATO appartiene a una sola delle due tuple, esso figurerà nella tupla risultato assieme al corrispondente dato\n
                          ES. t1-t2 = MODELLO,6s,DISPONIBILE,si\n\n

                        2) intersezione (/) -> solo le coppie METADATO,dato comuni a entrambe le tuple formeranno l'intersezione tra le due\n
                          ES. t1/t2 = MARCA,apple\n\n

                        3) join (%) -> la tupla join è ottenuta 'sommando' alla tupla operando a sinistra le coppie dell'operando destro con METADATO non comune\n
                          ES. t1%t2 = MARCA,apple,DISPOSITIVO,iphone,MODELLO,6s,DISPONIBILE,si\n
                          ES. t2%t1 = MARCA,apple,DISPOSITIVO,appleTV,DISPONIBILE,si,MODELLO,6s\n\n

                        NB 2: Attenzione, le operazioni sono CASE SENSITIVE");
}
