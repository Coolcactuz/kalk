#ifndef SPECIALIZED_VIEW_H
#define SPECIALIZED_VIEW_H

#include "../KalkButton.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <string>

class view_manager;

class specialized_view: public QWidget{
private:

  view_manager* vm;
  QVBoxLayout* external_layout;
  QVBoxLayout* upper;
  QGridLayout* lower;
  QPlainTextEdit* display;

  //metodo di accesso ai KalkButton della tastiera mediante puntatore lower,
  //magari virtuale

  virtual KalkButton* getKey(std::string) const;

public:

//metodi comuni a tutte le viste, posso gia definirli

//costruttore e distruttore
  specialized_view(view_manager* = 0);
  virtual ~specialized_view();

//chiama il metodo start() di view manager per poter ricominciare il ciclo
  void select_type();


//DECIDERE SE FARE O MENO
//vista contestuale: se la finestra è maximized appare il bottone per
//unmaximizzare, altrimenti il contrario

/*
//ridimensiona la vista affinchè occupi il massimo dello schermo
  void resize_max();

//ridimensiona la vista affinchè occupi una certa percentuale dello schermo
  void unmaximize()
*/


//DA FARE UNA VOLTA SISTEMATO IL CONTROLLER
/*
//chiama la funzione di salvataggio del buffer di sessione e chiudi kalk
  save_and_quit()
*/


//metodi virtuali puri, servono ulteriori informazioni per poterli definire


//plotta l'oggetto corrente
  virtual plot() =0;

//mostra un menù contestuale
  virtual show_menu() =0;



signals:

//segnale generico comune a tutte le viste, invia dati al controller
  void sendData(std::string);
};


#endif
