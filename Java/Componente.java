// classe concreta Componente, derivata da Dato
// rappresenta un generico componente, tra Resistore, Induttore, Condensatore


// TO DO:
//   GESTIONE ECCEZIONI -> segnalate nell'implementazione dei vari metodi


//SCELTE PROGETTUALI:
// 1) override dei metodi toString(), equals()
// 2) implementazione del metodo assign()
// 3) "traduzione" in linguaggio Java delle ulteriori funzionalita' offerte dalla corrispettiva classe C++
//    a)costruttore con un parametro CCartesiano
//    b)costruttore con un parametro String
//    c)costruttore di default
//    d)impedenza
//    e)serie
//    f)parallelo
//    g)getVolt
//    h)setVolt
//    i)getFreq
//    l)setFreq
//    m)setImp
//    n)solveOperation


class Componente extends Dato{

  private CCartesiano imp;

  protected static double freq = 0;
  protected static double volt = 0;

  public Componente(CCartesiano c){
    imp = c;
  }

  public Componente(){
    this(0);
  }

  public Componente(String s){
    if(s.charAt(0) == 'Z'){
      imp = Double.parseDouble(s.substring(1));
    }
    else{
      System.out.println("errore di sintassi nella costruzione di Componente");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }
  }

  public CCartesiano impedenza(){
    return imp;
  }

  public Componente serie(Componente c){
    CCartesiano impThis = impedenza();
    CCartesiano impParameter = c.impedenza();
    Componente result = new Componente(impThis.somma(impParameter));
    return result;
  }

  public Componente parallelo(Componente c){
    CCartesiano impThis = impedenza();
    CCartesiano impParameter = c.impedenza();
    Componente result = new Componente((impThis.moltiplicazione(impParameter)).divisione(impThis.somma(impParameter)));
    return result;
  }

  public static double getVolt(){
    return volt;
  }

  public static double getFreq(){
    return freq;
  }

  public void setVolt(double v){
    if(v >= 0){
      volt = v;
    }
    else{
      System.out.println("volt negativi");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }
  }

  public void setFreq(double f){
    if(f >= 0){
      freq = f;
    }
    else{
      System.out.println("frequenza negativa");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }
  }

  public void setImp(CCartesiano c){
    imp = c;
  }

  public static Componente solveOperation(Dato d1, Dato d2, String s){
    if(!(d1 instanceof Componente)){
      System.out.println("Componente.solveOperation()->d1 non è una istanza di Componente");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }
    if(!(d2 instanceof Componente)){
      System.out.println("Componente.solveOperation()->d2 non è una istanza di Componente");
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }

    Componente aux1 = (Componente) d1;
    Componente aux2 = (Componente) d2;

    switch(s){

        case "serie":
          Componente result = aux1.serie(aux2);
          return result;
        break;

        case "parallelo":
          Componente result = aux1.parallelo(aux2);
          return result;
        break;

        default:
          System.out.println("Componente.solveOperation()->errore nell'operatore");
          //---------------
          //GESTIRE ECCEZIONE
          //---------------
        break;

    }
  }

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

  public boolean equals(Object obj){
    if(!(obj instanceof Componente)){
      System.out.println("Componente.equals()->obj non è istanza di Componente");
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
    result = result + "IMPEDENZA: " + imp.toString() + ";\r\n";
    result = result + "VOLTAGGIO: " + volt + ";\r\n";
    result = result + "FREQUENZA: " + freq + ";\r\n";
    return result;
  }
}
