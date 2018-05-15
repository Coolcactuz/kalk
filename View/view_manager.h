#ifndef VIEW_MANAGER_H
#define VIEW_MANAGER_H

#include <QObject>

/* classe view_manager: deve gestire la vista iniziale (startup_view), e sulla
base del tipo scelto dall'utente creare la giusta incarnazione della vista per
la manipolazione dei dati */

/* view_manager controlla la vista iniziale e quella specializzata mediante due
puntatori alle stesse, che devono essere opportunamente gestiti */

class view_manager: public QObject{ //QObject richiede un puntatore all'
                                    //eventuale padre
private:

  //ricordarsi di inizializzarle come figlie di view_manager
  //esiste una sola view_manager per esecuzione ed è una variabile automatica
  //il che significa che alla sua distruzione verranno distrutti anche gli
  //oggetti puntati

  startup_view* startup;
  specialized_view* specialized;

  //----------------------gestione viste------------------------------------

  //DEVE ESSERE UNO SLOT PER POTER RICOMINCIARE IL CICLO
  /* start() elimina le eventuali viste esistenti puntate dai due puntatori, e
  si occupa di creare quella di startup per la selezione del tipo */
  void start();

  /* newSpecialized() crea la vista specializzata sulla base del tipo
  comunicatogli dal controller */
  void newSpecialized(int);

public:

  //gestione oggetto view_manager
  view_manager(QObject* = 0);

};

#endif
