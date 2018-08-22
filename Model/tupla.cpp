#include "tupla.h"


// //controlla l'integrità della tupla, se ci sono problemi solleva una eccezione
// void tupla::check_tupla() const{
//
//   //controlla che i vettori abbiano la stessa dimensione
//   if(metadati.size() != dati.size())
//     throw exception("Diverso numero di dati e metadati");
//
//   //controlla che nei metadati non ci sia la stringa vuota
//   for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
//       if(*it == "")
//         throw exception("Metadato nullo");
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
//   //   throw exception("Metadato ripetuto");
// }


//costruttore di tupla a partire da una stringa del tipo METADATO,DATO
tupla::tupla(std::string s){

  if(s != ""){

    int commas = 0;
    for(std::string::const_iterator it = s.begin(); it != s.end(); it++){
      if(*it == ','){
        commas++;
        if(*(std::next(it)) == ',')
          throw syntax_exception("Due o più virgole sono di seguito");
      }
    }

    if(commas%2 == 0)
      throw syntax_exception("Errore nel numero delle virgole");

    if(s[0] == ",")
      throw syntax_exception("La stringa inizia con una virgola");

    if(s[s.size() - 1] == ",")
      throw syntax_exception("La stringa finisce con una virgola");

    //std::string::const_iterator it = s.begin();

    int ind = 0;

    while(ind < s.size()){

      int sub_size = 0;
      int aux = ind;

      while(s[aux] != ','){
        sub_size++;
        aux++;
      }

      metadati.push_back(s.substr(ind, sub_size));

      sub_size = 0;
      aux++;
      ind = aux;

      while(aux < s.size() && s[aux] != ','){
        sub_size++;
        aux++;
      }

      dati.push_back(s.substr(ind,sub_size));

      if(aux < s.size())
        aux++;

      ind = aux;
    }

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
    return "METADATO INESISTENTE"
}

//verifica l'esistenza di una intera entry
bool tupla::search_by_entry(std::string m, std::string d) const{
  return exist_metadati(m) && search_by_metadati(m)==d;
}

//inserisce una entry nella tupla
void tupla::insert(std::string m, std::string d){
  metadati.push_back(m);
  dati.push_back(d);
}

//elimina la ultima entry
void tupla::erase(){
  metadati.pop_back();
  dati.pop_back();
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

//restituisce l'unione di due tuple, una eccezione in caso di errore
tupla tupla::operator+(const tupla& t) const{

  tupla res = t;
  res.metadati.insert(res.metadati.end(), metadati.begin(), metadati.end());
  res.dati.insert(res.dati.end(), dati.begin(), dati.end());

  return res;
}

//restituisce una tupla che è intersezione di due tuple: l'intersezione è intesa come stesso campo METADATO
//e stesso campo DATO
tupla tupla::operator/(const tupla& t) const{

  tupla res;
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
      if(t.exist_metadati(*it) && (t.search_by_metadati(*it) == search_by_metadati(*it))
        && !(res.search_by_entry(*it, search_by_metadati(*it))))

        res.insert(*it, search_by_metadati(*it));
  }

  return res;
}

//restituisce una tupla che è differenza di due tuple
tupla tupla::operator-(const tupla& t) const{

  tupla res;

  //for che scorre i metadati dell'oggetto di invocazione
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
    if(!(t.exist_metadati(*it)) || (t.search_by_metadati(*it) != search_by_metadati(*it)))
      res.insert(*it, search_by_metadati(*it));
  }

  //for che scorre i metadati della tupla parametro
  for(std::vector<std::string>::const_iterator it = t.metadati.begin(); it != t.metadati.end(); it++){
    if(!(exist_metadati(*it)) || (t.search_by_metadati(*it) != search_by_metadati(*it)))
      res.insert(*it, t.search_by_metadati(*it));
  }

  return res;
}


//restituisce il join tra due tuple
tupla tupla::operator%(const tupla& t) const{

  tupla aux1 = operator-(t);
  tupla aux2 = operator/(t);

  tupla res = aux1+aux2;

  return res;
}
