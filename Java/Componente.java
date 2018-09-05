// classe concreta Componente, derivata da Dato
// rappresenta un generico componente, tra Resistore, Induttore, Condensatore


// TO DO:
//   GESTIONE ECCEZIONI -> segnalate nell'implementazione dei vari metodi


//SCELTE PROGETTUALI:
// 1) override dei metodi toString(), equals()
// 3) "traduzione" in linguaggio Java delle ulteriori funzionalita' offerte dalla corrispettiva classe C++
//    a)costruttore con un parametro CCartesiano
//    c)costruttore di default
//    d)impedenza
//    e)serie
//    f)parallelo
//    g)getVolt
//    h)setVolt
//    i)getFreq
//    l)setFreq
//    m)setImp


class Componente extends Dato{

  private CCartesiano imp;

  protected static double freq = 0;
  protected static double volt = 0;

  public Componente(CCartesiano c){
    imp = c;
  }

  public Componente(){
    this(new CCartesiano());
  }

  public CCartesiano impedenza(){
    return imp;
  }

  public Componente serie(Componente c){
    CCartesiano impThis = impedenza();
    CCartesiano impParameter = c.impedenza();
    Componente result = new Componente(((CCartesiano) impThis.somma(impParameter)));
    return result;
  }

  public Componente parallelo(Componente c){
    CCartesiano impThis = impedenza();
    CCartesiano impParameter = c.impedenza();
    Componente result = new Componente(((CCartesiano) (impThis.moltiplicazione(impParameter)).divisione(impThis.somma(impParameter))));
    return result;
  }

  public static double getVolt(){
    return volt;
  }

  public static double getFreq(){
    return freq;
  }

  public static void setVolt(double v) throws KalkException{
    if(v >= 0){
      volt = v;
    }
    else{
      throw new KalkException("volt negativi");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }
  }

  public static void setFreq(double f) throws KalkException{
    if(f >= 0){
      freq = f;
    }
    else{
      throw new KalkException("frequenza negativa");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }
  }

  protected void setImp(CCartesiano c){
    imp = c;
  }

  /*
  public void assign(Dato d){
    if(!(d instanceof Componente)){
      System.out.println("Componente.assign()->d non è istanza di Componente");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }

    Componente aux = (Componente) d;

    setImp(aux.impedenza());
  }
  */

  public boolean equals(Object obj) throws KalkException{
    if(!(obj instanceof Componente)){
      throw new KalkException("Componente.equals()->obj non è istanza di Componente", false);
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }

    Componente aux = (Componente) obj;

    if(imp.equals(aux.imp)){
      return true;
    }
    else{
      return false;
    }
  }

  public String toString(){
    String result = new String();
    result = result + "IMPEDENZA: " + imp.toString();
    result = result + "VOLTAGGIO: " + volt + "\r\n";
    result = result + "FREQUENZA: " + freq + "\r\n";
    return result;
  }
}
