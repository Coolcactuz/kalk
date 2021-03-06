// classe concreta Resistore, derivata da Componente


// TO DO:
//   GESTIONE ECCEZIONI -> segnalate nell'implementazione dei vari metodi


//SCELTE PROGETTUALI:
// 1) override dei metodi toString(), equals(), impedenza()
// 3) "traduzione" in linguaggio Java delle ulteriori funzionalita' offerte dalla corrispettiva classe C++
//    a)costruttore da double
//    c)costruttore di default

class Resistore extends Componente{

  private double resistenza;

  public Resistore(double d){
    resistenza = d;
    super.setImp(impedenza());
  }

  public double getResistenza(){
    return resistenza;
  }

  public Resistore(){
    this(0);
  }

  public CCartesiano impedenza(){
    CCartesiano result = new CCartesiano(resistenza, 0);
    return result;
  }

  /*
  public void assign(Dato d){
    if(!(d instanceof Resistore)){
      System.out.println("Resistore.assign()-> d non e' istanza di Resistore");
      //------------------
      //GESTIRE ECCEZIONE
      //------------------
    }

    Resistore aux = (Resistore) d;

    super.assign(aux);

    resistenza = aux.resistenza;
  }
  */

  public boolean equals(Object obj){
    if(!(obj instanceof Resistore)){
      return false;
    }

    Resistore aux = (Resistore) obj;

    if(super.equals(aux)){
      if(resistenza == aux.resistenza){
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
    result = result + "RESISTENZA: " + resistenza + "\r\n";
    return result;
  }

}
