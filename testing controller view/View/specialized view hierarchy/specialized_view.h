#ifndef SPECIALIZED_VIEW_H
#define SPECIALIZED_VIEW_H

#include "../KalkButton.h"

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPlainTextEdit>


#include <string>
#include <iostream>


class specialized_view: public QWidget{

Q_OBJECT

protected:

  QVBoxLayout* external_layout;
  QHBoxLayout* header;
  QLabel * type_title;
  QVBoxLayout* upper;
  QHBoxLayout* lower;

private:

  QPushButton* go_back;
  QGridLayout* keyboard;
  QPlainTextEdit* display;


public:

//metodi comuni a tutte le viste, posso gia definirli

//costruttore e distruttore
  specialized_view();
  virtual ~specialized_view() {}


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
  virtual void plot() =0;

//mostra un menù contestuale
  //virtual show_menu() =0;



signals:

//segnale generico comune a tutte le viste, invia dati al controller
  void sendData(std::string);

  void goBack_CStart();
/*
public slots:

  void test();
*/
};


#endif
