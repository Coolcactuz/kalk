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


//costruttore di tupla a partire da una stringa del tipo METADATO, DATO
tupla::tupla(std::string s){

  if(s != ""){

    int commas = 0;
    for(std::string::const_iterator it = s.begin(); it != s.end(); it++){
      if(*it == ',')
        commas++;
    }

    // if(commas%2 == 0)
    //   throw exception("Diverso numero tra dati e metadati");


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

      if(s[aux] == ',')
        aux++;

      ind = aux;
    }

    // try{
    //   check_tupla();
    // }
    //
    // catch(exception e){
    //     throw e;
    // }
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

//restituisce il dato corrispondente al metadato cercato, se quest'ultimo esiste, altrimenti lancia una eccezione
std::string tupla::search_by_metadati(std::string s) const{

  if(exist_metadati(s)){
    int ind = 0;

    while(metadati[ind] != s)
      ind++;

    return dati[ind];
  }
  // else
  //   throw exception("Metadato inesistente");
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
tupla tupla::unione(const tupla& t) const{

  tupla res = t;
  res.metadati.insert(res.metadati.end(), metadati.begin(), metadati.end());
  res.dati.insert(res.dati.end(), dati.begin(), dati.end());

  // try{
  //   res.check_tupla();
  // }
  //
  // catch(exception e){
  //     throw e;
  // }

  return res;
}

//restituisce una tupla che è intersezione di due tuple: l'intersezione è intesa come stesso campo METADATO
//e stesso campo DATO. Restituisce una eccezione in caso di errore
tupla tupla::intersect(const tupla& t) const{

  tupla res;
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
      if(t.exist_metadati(*it) && (t.search_by_metadati(*it) == search_by_metadati(*it))
        && !(res.search_by_entry(*it, search_by_metadati(*it))))

        res.insert(*it, search_by_metadati(*it));
  }

  // try{
  //   res.check_tupla();
  // }
  //
  // catch(exception e){
  //     throw e;
  // }

  return res;

}

//restituisce una tupla che è differenza di due tuple, una eccezione in caso di errore
tupla tupla::diff(const tupla& t) const{

  tupla res;
  //for che scorre i metadati dell'oggetto di invocazione
  for(std::vector<std::string>::const_iterator it = metadati.begin(); it != metadati.end(); it++){
    if(!(t.exist_metadati(*it)) || (t.search_by_metadati(*it) != search_by_metadati(*it)))
      res.insert(*it, search_by_metadati(*it));
  }
  //for che scorre i metadato della tupla parametro
  for(std::vector<std::string>::const_iterator it = t.metadati.begin(); it != t.metadati.end(); it++){
    if(!(exist_metadati(*it)) || (t.search_by_metadati(*it) != search_by_metadati(*it)))
      res.insert(*it, t.search_by_metadati(*it));
  }

  // try{
  //   res.check_tupla();
  // }
  //
  // catch(exception e){
  //     throw e;
  // }

  return res;
}

//restituisce il join tra due tuple, una eccezione altrimenti
tupla tupla::join(const tupla& t) const{

  tupla aux1 = diff(t);
  tupla aux2 = intersect(t);

  tupla res = aux1.unione(aux2);

  // try{
  //   res.check_tupla();
  // }
  //
  // catch(exception e){
  //     throw e;
  // }

  return res;
}


int main(){

  tupla b("NOME,NICK,COGNOME,VETTORELLO");

  tupla t("NOME,GUIDO,COGNOME,VETTORELLO,COGNOME,VETTORELLO");


  return 0;
}
