#include "tupla.h"


// //controlla l'integrità della tupla
// void tupla::check_tupla() const{
//
//   //controlla che i vettori abbiano la stessa dimensione
//   if(metadati.size() != dati.size())
//     //eccezione
//
//   //controlla che nei metadati non ci sia la stringa vuota
//   for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
//       if(*it == "")
//         //eccezione
//   }
//
//   // //controlla che non ci sia un metadato ripetuto
//   // bool check_repetition = false;
//   //
//   // for(std::vector<std::string>::const_iterator i = metadati.begin(); i != metadati.end() && !check_repetition; i++){
//   //     for(std::vector<std::string>::const_iterator j = std::next(i); j != metadati.end() && !check_repetition; j++){
//   //       if(*i == *j)
//   //         check_repetition = true;
//   //     }
//   // }
//   //
//   // if(check_repetition)
//   //   //eccezione
// }


//costruttore di tupla a partire da una stringa del tipo METADATO,DATO
tupla::tupla(std::string s){

  if(s != ""){

    if(s[0] == ',')
      throw syntax_exception("La stringa inizia con una virgola");

    if(s[s.size() - 1] == ',')
      throw syntax_exception("La stringa finisce con una virgola");

    int commas = 0;
    for(std::string::const_iterator it = s.begin(); it != s.end(); it++){
      if(*it == ','){
        commas++;
        if(*(std::next(it)) == ',')
          throw syntax_exception("Due o più virgole sono di seguito");
      }
    }

    if(!(commas%2))
      throw syntax_exception("Errore nel numero delle virgole");

    //std::string::const_iterator it = s.begin();

    unsigned int ind = 0;

    while(ind < s.size()){

      int sub_size = 0;
      unsigned int aux = ind;

      while(s[aux] != ','){
        sub_size++;
        aux++;
      }

      //a questo punto s.substr(ind, sub_size) è il metadato da inserire
      //controllo se è già presente nel vettore dei metadati, e in tal caso lancio una eccezione

      for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
        if(*it == s.substr(ind, sub_size))
            throw syntax_exception("metadato presente due o più volte");
      }

      //controllo che all'interno della stringa non sia presente un carattere speciale
      std::size_t found_metadato = (s.substr(ind, sub_size)).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890");

      if(found_metadato != std::string::npos)
          throw syntax_exception("carattere non consentito");

      //se arrivo qui nessun metadato già presente nel vettore è uguale a quello che voglio inserire e all'interno del metadato stesso non ci
      //sono caratteri speciali, quindi posso farlo
      metadati.push_back(s.substr(ind, sub_size));

      sub_size = 0;
      aux++;
      ind = aux;

      while(aux < s.size() && s[aux] != ','){
        sub_size++;
        aux++;
      }

      //controllo che nel dato da inserire non ci siano caratteri speciali
      std::size_t found_dato = (s.substr(ind, sub_size)).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890");

      if(found_dato != std::string::npos)
          throw syntax_exception("carattere non consentito");

      dati.push_back(s.substr(ind,sub_size));

      if(aux < s.size())
        aux++;

      ind = aux;
    }

    if(dati.size() != metadati.size())
      throw logic_exception("errore creazione tupla");
  }
}

//stampa il vettore dei metadati
void tupla::print_metadati() const{
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++)
    std::cout << *it << " ";
}

//stampa il vettore dei dati
void tupla::print_dati() const{
  for(std::vector<std::string>::const_iterator it = dati.begin(); it != dati.end(); it++)
    std::cout << *it << " ";
}

//true se esiste il particolare metadato cercato, false altrimenti
bool tupla::exist_metadati(std::string s) const{
  bool res = false;
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end() && !res; it++){
    if(*it == s)
      res = true;
  }
  return res;
}

//restituisce il dato corrispondente al metadato cercato, se quest'ultimo esiste
std::string tupla::search_by_metadati(std::string s) const{

  if(exist_metadati(s)){
    int ind = 0;

    while(metadati[ind] != s)
      ind++;

    return dati[ind];
  }
  else
    return std::string();
}

//verifica l'esistenza di una intera entry
bool tupla::search_by_entry(std::string m, std::string d) const{
  return exist_metadati(m) && search_by_metadati(m)==d;
}

//inserisce una entry nella tupla
void tupla::insert(std::string m, std::string d){
  if(m == ""  ||  d == ""){
    throw syntax_exception("stai inserendo una stringa nulla");
  }

  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
    if(*it == m){
      throw logic_exception("impossibile inserire: metadato già presente");
    }
  }

  metadati.push_back(m);
  dati.push_back(d);
}

//elimina la ultima entry
void tupla::erase(){
  if(is_null()){
    throw logic_exception("impossibile eliminare ultima entry: tupla vuota");
  }
  else{
    metadati.pop_back();
    dati.pop_back();
  }
}

//verifica se la tupla è nulla
bool tupla::is_null() const{
  return metadati.size() == 0;
}

//stampa l'intera tupla
std::ostream& operator<<(std::ostream& out, const tupla& t){

  for(std::vector<std::string>::const_iterator it = t.metadati.begin(); it != t.metadati.end(); it++){
    out << *it << "   ";

  }

  out << std::endl;

  for(std::vector<std::string>::const_iterator it = t.dati.begin(); it != t.dati.end(); it++)
    out << *it << "   ";

  return out;
}


//restituisce una tupla che è intersezione di due tuple: l'intersezione è intesa come stesso campo METADATO
//e stesso campo DATO
tupla* tupla::operator/(const tupla* t) const{

  tupla* res = new tupla();

  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
      if(t->exist_metadati(*it) && (t->search_by_metadati(*it) == search_by_metadati(*it)))
        res->insert(*it, search_by_metadati(*it));
  }

  return res;
}

//restituisce una tupla che è differenza di due tuple
tupla* tupla::operator-(const tupla* t) const{

  tupla* res = new tupla();

  //for che scorre i metadati dell'oggetto di invocazione
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
    if(!(t->exist_metadati(*it)))
      res->insert(*it, search_by_metadati(*it));
  }

  //for che scorre i metadati della tupla parametro
  for(std::vector<std::string>::const_iterator it = t->metadati.begin(); it != t->metadati.end(); it++){
    if(!(exist_metadati(*it)))
      res->insert(*it, t->search_by_metadati(*it));
  }

  return res;
}


//restituisce il join tra due tuple
//ATTENZIONE: il join non è caratterizzato dalla proprietà commutativa
tupla* tupla::operator%(const tupla* t) const{

  tupla* res = new tupla();
  res->metadati = metadati;
  res->dati = dati;

  for(std::vector<std::string>::const_iterator it = t->metadati.begin(); it!=t->metadati.end(); ++it){
    if(!(exist_metadati(*it))){
      res->insert(*it, t->search_by_metadati(*it));
    }
  }
  return res;
}


bool tupla::operator== (const Dato& d) const{
  try{
    auto aux= dynamic_cast<const tupla&>(d);
    return metadati==aux.metadati && dati==aux.dati;
  }
  catch(const std::bad_cast& error){
    return false;
  }
}

std::string tupla::toString() const{
  std::string res="";
  auto cit_metadati=metadati.cbegin();
  auto cit_dati=metadati.cbegin();
  for(;cit_metadati!=metadati.cend() && cit_dati!=dati.cend(); ++cit_metadati, ++cit_dati){
    if(cit_metadati!=metadati.cbegin() && cit_dati!=dati.cbegin())
      res=res+",";
    res=res+(*cit_metadati)+","+(*cit_dati);
  }
  return res;
}

tupla* tupla::solve_operation(const Dato* a, const Dato* b, char o){
    auto l=dynamic_cast<const tupla*>(a);
    auto r=dynamic_cast<const tupla*>(b);
    if(l && r){
        try {
            switch (o) {
                case '-':
                    return l->operator-(r);

                case '/':
                    return l->operator/(r);

                case '%':
                    return l->operator%(r);

                default:
                    throw syntax_exception("Operatore inesistente");
            }
        }
        catch(const syntax_exception& se){
            throw ;
        }
        catch(const logic_exception& le){
            throw ;
        }
    }
    else
        throw logic_exception("tipo di dati errato");
}