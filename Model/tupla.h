#ifndef TUPLA_H
#define TUPLA_H

#include <vector>
#include <string>
#include "exception.h"

class tupla{
friend std::ostream& operator<<(std::ostream&, const tupla&);

private:
  std::vector<std::string> metadati;
  std::vector<std::string> dati;

  // //funzione di controllo integrità
  // void check_tupla() const;

public:
  tupla(std::string = "");

  //costruttore di copia, assegnazione e distruttore possono restare
  //standard, tanto non ci sono puntatori

  //stampa il vettore dei metadati
  void print_metadati() const;

  //stampa il vettore dei dati
  void print_dati() const;

  //verifica esistenza metadato
  bool exist_metadati(std::string) const;

  //cerca tramite metadato
  std::string search_by_metadati(std::string) const;

  //ricerca per intera entry
  bool search_by_entry(std::string, std::string) const;

  //inserisce una entry alla fine
  void insert(std::string, std::string);

  //elimina l'ultima entry
  void erase();


  //unione
  tupla operator+(const tupla&) const;

  //join
  tupla operator%(const tupla&) const;

  //differenza
  tupla operator-(const tupla&) const;

  //intersezione
  tupla operator/(const tupla&) const;


  //controllo tupla vuota
  bool is_null() const;
};


#endif
