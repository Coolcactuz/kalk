// classe concreta Induttore, derivata da Componente


// TO DO:
//   GESTIONE ECCEZIONI -> segnalate nell'implementazione dei vari metodi


//SCELTE PROGETTUALI:
// 1) override dei metodi toString(), equals(), impedenza()
// 3) "traduzione" in linguaggio Java delle ulteriori funzionalita' offerte dalla corrispettiva classe C++
//    a)costruttore da double
//    c)costruttore di default

class Induttore extends Componente{

  private double induttanza;

  public Induttore(double d){
    induttanza = d;
    //System.out.println(this.impedenza());
    super.setImp(impedenza());
  }

  public Induttore(){
    induttanza = 0;
  }

  public double getInduttanza(){
    return induttanza;
  }

  public CCartesiano impedenza(){
    double aux = 2 * (Numero.pi) * (Componente.freq) * (induttanza/1000);
    CCartesiano result = new CCartesiano(0, aux);
    return result;
  }

  /*
  public void assign(Dato d){
    if(!(d instanceof Induttore)){
      System.out.println("Induttore.assign()-> d non e' istanza di Induttore")
      //-------------------
      //GESTIRE ECCEZIONE
      //-------------------
    }

    Induttore aux = (Induttore) d;

    super.assign(aux);

    induttanza = aux.induttanza;
  }
  */

  public boolean equals(Object obj){
    if(!(obj instanceof Induttore)){
      return false;
    }

    Induttore aux = (Induttore) obj;

    if(super.equals(aux)){
      if(induttanza == aux.induttanza){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return false;
    }
  }

  public String toString(){
    String result = super.toString();
    result = result + "INDUTTANZA: " + induttanza + "\r\n";
    return result;
  }
}
