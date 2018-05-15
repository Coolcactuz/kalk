#ifndef SESSION_BUFFER_H
#define SESSION_BUFFER_H

/* un oggetto della classe session_buffer gestisce un file che riporta tutti gli input inseriti in una singola sessione: deve
mettere a disposizione operazioni per la scrittura e per il recupero dei dati, e eliminare gli input piu' vecchi se il file supera una
certa dimensione. Si vogliono inoltre delle operazioni di esportazione e importazione per permettere all' utente di operare all'
interno di sessioni personali */

#include <fstream>

class session_buffer{

//implementazione interna del buffer
private:

//controlla la dimensione occupata dal buffer e prendi provvedimenti se supera una certa soglia
checkDimension()

public:

//scrivi sul buffer
write()

//leggi dal buffer
read()

//esporta il buffer
export()

//importa un buffer dell'utente
import()

};


#endif
