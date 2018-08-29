// classe concreta Tupla, derivata da Dato
// rappresenta una tupla, vista come un insieme di coppie METADATO,DATO


// TO DO:
//   GESTIONE ECCEZIONI -> segnalate nell'implementazione dei vari metodi


//SCELTE PROGETTUALI:
// 1) override dei metodi toString(), equals()
// 2) implementazione del metodo assign()
// 3) "traduzione" in linguaggio Java delle ulteriori funzionalita' offerte dalla corrispettiva classe C++
//    a)costruttore di default
//    b)costruttore da stringa
//    c)printTupla
//    d)printDati
//    e)printMetadati
//    f)existsMetadato
//    g)searchByMetadato
//    h)searchByEntry
//    i)insert
//    l)erase
//    m)isNull
//    n)unione
//    o)differenza
//    p)intersezione
//    q)join

import java.util.Vector;
import java.util.Iterator;

class Tupla extends Dato{

  private Vector<String> metadati = new Vector<String>();
  private Vector<String> dati = new Vector<String>();


  //costruttore di tupla a partire da una stringa del tipo METADATO,DATO
  public Tupla(String s){

    if(!(s.equals(""))){

      //controllo se la stringa e' corretta
      if(s.charAt(0) == ','){
        System.out.println("la tua stringa inizia con una virgola");
        //----------------------
        //GESTIRE ECCEZIONE
        //----------------------
      }

      if(s.charAt(s.length() - 1) == ','){
        System.out.println("la tua stringa finisce con una virgola");
        //----------------------
        //GESTIRE ECCEZIONE
        //----------------------
      }


      int commas = 0;

      for(int i = 0; i < s.length(); ++i){
        if(s.charAt(i) == ','){
          ++commas;
          if(s.charAt(i+1) == ','){
            System.out.println("piu' di una virgola di seguito");
            //----------------------
            //GESTIRE ECCEZIONE
            //----------------------
          }
        }
      }

      if((commas%2) == 0){
        System.out.println("numero incorretto di virgole");
        //----------------------
        //GESTIRE ECCEZIONE
        //----------------------
      }
      //fine dei controlli sulla stringa
      //da qui si assume che la stringa abbia una sintassi corretta

      int ind = 0;

      while(ind < s.length()){

          int aux = ind;

          while(s.charAt(aux) != ','){
            ++aux;
          }

          if(metadati.contains(s.substring(ind, aux))){
            System.out.println("due o più metadati uguali");
            //----------------------
            //GESTIRE ECCEZIONE
            //----------------------
          }

          metadati.add(s.substring(ind, aux));

          ++aux;
          ind = aux;

          while((aux < s.length()) && (s.charAt(aux) != ',')){
            ++aux;
          }


          if(aux == s.length()){
            dati.add(s.substring(ind));
            ind = aux;
          }
          else{
            dati.add(s.substring(ind, aux));
            ind = aux + 1;
          }
      }

      if(dati.size() != metadati.size()){
        System.out.println("errore nella creazione della tupla: diverso numero tra metadati e dati");
        //----------------------
        //GESTIRE ECCEZIONE
        //----------------------
      }
    }

  }

  public Tupla(){
    this("");
  }

/*
  //casta d a Tupla se possibile, altrimenti lancia una eccezione
  //se il cast riesce clona i vettori del parametro nei rispettivi campi dell'oggetto di invocazione
  public void assign(Dato d){
    if(d instanceof Tupla){
      Tupla t = (Tupla) d;
      metadati = (Vector<String>) t.metadati.clone();
      dati = (Vector<String>) t.dati.clone();
    }
    else{
      System.out.println("Tupla.assign() cast fallito");
      //----------------------
      //GESTIRE ECCEZIONE
      //----------------------
    }
  }
*/

  //verifica se obj può essere castato a Tupla
  //vero se e solo se stesso vettore metadati e stesso vettore dati
  public boolean equals(Object obj){
    if(obj instanceof Tupla){
      Tupla t = (Tupla) obj;
      if((metadati.equals(t.metadati)) && (dati.equals(t.dati)))
        return true;
      else
        return false;
    }
    else{
      return false;
    }
  }


  public String toString(){
    String s = new String();
    int elementiTupla = metadati.size();

    if(elementiTupla == 0){
      return s;
    }

    for(int i = 0; i < elementiTupla-1; ++i){
      s = s + metadati.elementAt(i) + "," + dati.elementAt(i) + ",";
    }

    s = s + metadati.elementAt(elementiTupla-1) + "," + dati.elementAt(elementiTupla-1);

    return s;
  }

  //stampa l'intera Tupla
  public void printTupla(){
    System.out.println(toString());
  }

  //stampa solo i metadati
  public void printMetadati(){
    System.out.println(metadati.toString());
  }

  //stampa solo i dati
  public void printDati(){
    System.out.println(dati.toString());
  }

  //true se il metadato cercato esiste, false altrimenti
  public boolean existsMetadato(String s){
    return metadati.contains(s);
  }

  //controlla se il metadato esiste nella tupla e in caso positivo restituisce il dato associato,
  //altrimenti la stringa nulla
  public String searchByMetadato(String s){
    if(existsMetadato(s)){
      int ind = 0;
      while(!((metadati.elementAt(ind)).equals(s))){
        ind++;
      }
      //quando esce dal while metadati.elementAt(ind) è uguale a s;
      return dati.elementAt(ind);
    }
    else{
      return new String();
    }
  }

  public boolean searchByEntry(String m, String d){
    if(existsMetadato(m) && (searchByMetadato(m)).equals(d)){
      return true;
    }
    else{
      return false;
    }
  }

  public void insert(String m, String d){
    if(m.isEmpty() || d.isEmpty()){
      System.out.println("almeno una delle due string è vuota");
      //----------------------
      //GESTIRE ECCEZIONE
      //----------------------
    }
    if(metadati.contains(m)){
      System.out.println("metadato già presente");
      //----------------------
      //GESTIRE ECCEZIONE
      //----------------------
    }

    metadati.add(m);
    dati.add(d);
  }

  public void erase(){
    int numeroElementi = metadati.size();

    if(numeroElementi == 0){
      System.out.println("impossibile rimuovere elementi da tupla vuota");
      //------------------
      //GESTIRE ECCEZIONE
      //------------------
    }
    else{
      metadati.remove(numeroElementi-1);
      dati.remove(numeroElementi-1);
    }
  }

  public boolean isNull(){
    if(metadati.size() == 0){
      return true;
    }
    else{
      return false;
    }
  }


  public Tupla intersezione(Tupla t){

    Tupla res = new Tupla();

    Iterator<String> it = metadati.iterator();
    while(it.hasNext()){
      if(t.existsMetadato(it.next()) && (searchByMetadato(it.next())).equals(t.searchByMetadato(it.next()))){
        res.insert(it.next(), searchByMetadato(it.next()));
      }
    }

    return res;
  }

  public Tupla differenza(Tupla t){
    Tupla res = new Tupla();

    Iterator<String> it1 = metadati.iterator();
    while(it1.hasNext()){
      if(!(t.existsMetadato(it1.next()))){
        res.insert(it1.next(), searchByMetadato(it1.next()));
      }
    }

    Iterator<String> it2 = t.metadati.iterator();
    while(it2.hasNext()){
      if(!(existsMetadato(it2.next()))){
        res.insert(it2.next(), t.searchByMetadato(it2.next()));
      }
    }

    return res;
  }

  public Tupla join(Tupla t){
    Tupla aux = new Tupla();
    aux.assign(this);

    Iterator<String> it = t.metadati.iterator();
    while(it.hasNext()){
      if(!(existsMetadato(it.next()))){
        aux.insert(it.next(), t.searchByMetadato(it.next()));
      }
    }

    return aux;
  }
}
