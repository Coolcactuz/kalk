// classe concreta Tupla, derivata da Dato
// rappresenta una tupla, vista come un insieme di coppie METADATO,DATO


// TO DO:
//   GESTIONE ECCEZIONI -> segnalate nell'implementazione dei vari metodi


//SCELTE PROGETTUALI:
// 1) override dei metodi toString(), equals()
// 2) implementazione del metodo assign()         OK
// 3) "traduzione" in linguaggio Java delle ulteriori funzionalita' offerte dalla corrispettiva classe C++


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

    }

  }

  public Tupla(){
    this("");
  }


  //casta d a Tupla se possibile, altrimenti lancia una eccezione
  //se il cast riesce clona i vettori del parametro nei rispettivi campi dell'oggetto di invocazione
  public void assign(Dato d){
    if(d instanceof Tupla){
      Tupla t = (Tupla)d;
      metadati = (Vector<String>) t.metadati.clone();
      dati = (Vector<String>) t.dati.clone();
    }
    else{
      System.out.println("d non e' una istanza di Tupla");
      //----------------------
      //GESTIRE ECCEZIONE
      //----------------------
    }
  }
}
