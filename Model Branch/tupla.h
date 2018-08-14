#ifndef TUPLA_H
#define TUPLA_H

#include <vector>
#include <string>
#include "exception.h"
#include "Dato.h"

class tupla : public Dato{
friend std::ostream& operator<<(std::ostream&, const tupla&);

private:
  std::vector<std::string> metadati;
  std::vector<std::string> dati;

  //inserire funzioni di controllo integrità?
  void check_tupla() const;

public:
  tupla(std::string = "");

  //costruttore di copia, assegnazione e distruttore possono restare
  //standard, tanto non ci sono puntatori

  //stampa il vettore dei metadati
  void print_metadati() const;

  //stampa il vettore dei dati
  void print_dati() const;

  //verifica esistenza metadato
  bool metadata_exist(std::string = "") const;

  //cerca tramite metadato
  std::string search_by_metadata(std::string) const;

  //inserisci entry
  void insert(std::string, std::string);

  //elimina entry per metadato
  void delete_by_metadata(std::string);


  //non ho ridefinito gli operatori poichè ho inteso queste operazioni
  //come operazioni tra insiemi

  //unione
  tupla unione(const tupla&) const;

  //join
  tupla join(const tupla&) const;

  //differenza
  tupla diff(const tupla&) const;

  //intersezione
  tupla intersect(const tupla&) const;


  //controllo tupla vuota
  bool is_null() const;

  tupla* solve_operation(const Dato*, const Dato*, char) const;

};


#endif
