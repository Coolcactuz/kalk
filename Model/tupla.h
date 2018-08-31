//rappresenta una tupla che contiene una o più coppie di elementi nella forma METADATO,DATO
//la costruzione di una tupla avviene mediante una stringa: la stringa nulla rappresenta la tupla nulla, ossia quella con 0 coppie di elementi,
//una generica stringa deve essere composta da coppie di elementi per poter generare una tupla valida: deve attenersi alla seguente sintassi:

  //deve essere nella forma m1,d1,m2,d2....mn,dn dove m sono i metadati, d i dati
  //il numero di virgole deve essere dispari
  //non può iniziare con una virgola
  //non può finire con una virgola
  //non possono esserci una o più virgole di seguito
  //non possono esserci due o più metadati uguali
  //possono esserci due o più dati uguali
  //non vi possono essere metadati o dati corrispondenti alla stringa nulla

//da ciò deriva che in una tupla valida il numero dei metadati è uguale a quello dei dati, ed esiste una mappatura tra insieme dei dati e quello dei metadati

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

  //join
  tupla* operator%(const tupla*) const;

  //differenza
  tupla* operator-(const tupla*) const;

  //intersezione
  tupla* operator/(const tupla*) const;

//  tupla& operator=(const Dato&){};

  bool operator==(const Dato&) const;

  std::string toString() const;

  //controllo tupla vuota
  bool is_null() const;

  static tupla* solve_operation(const Dato*, const Dato*, char);
};


#endif
