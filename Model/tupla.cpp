#include "tupla.h"


//controlla l'integrità della tupla, se ci sono problemi solleva una eccezione
void tupla::check_tupla() const{

  //controlla che i vettori abbiano la stessa dimensione
  if(metadati.size() != dati.size())
    throw(syntax_exception("Diverso numero di dati e metadati"));

  //controlla che nei metadati non ci sia la stringa vuota
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
      if(*it == "")
        throw(logic_exception("Metadato nullo"))
  }
}


//costruttore di tupla a partire da una stringa del tipo METADATO, DATO
tupla::tupla(std::string s){

  if(s != ""){

    int commas = 0;
    for(std::string::const_iterator it = s.begin(); it != s.end(); it++){
      if(*it == ',')
        commas++;
    }

    if(commas%2 == 0)
      throw(syntax_exception("Impossibile creare la tupla"));


    std::string::const_iterator it = s.begin();

    while(it != s.end()){

      int sub_size = 0;   //lunghezza sottostringa
      std::string::const_iterator aux = it;   //iteratore sulla stringa ausiliario

      while(*aux != ','){
        sub_size++;
        aux++;
      }

      metadati.push_back(s.substr(it, sub_size));

      sub_size = 0;
      aux++;
      it = aux;

      while(aux != s.end() && aux != ','){
        sub_size++;
        aux++;
      }

      dati.push_back(s.substr(it,sub_size));

      if(*aux == ',')
        aux++;

      it = aux;
    }
  }
}


void tupla::print_metadati() const{
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++)
    std::cout << *it << " ";
}

void tupla::print_dati() const{
  for(std::vector<std::string>::const_iterator it = dati.begin(); it != dati.end(); it++)
    std::cout << *it << " ";
}
