//classe concreta CCartesiano, derivata da Complesso
//rappresenta un numero complesso in forma cartesiana

//OBJECT -> equals()
//OBJECT -> toString()

//NUMERO -> somma()   ok
//NUMERO -> differenza()    ok
//NUMERO -> moltiplicazione()   ok
//NUMERO -> divisione()   ok

//COMPLESSO -> converti()   ok
//COMPLESSO -> coniugato()    ok

//CCARTESIANO ->costruttore di default    ok
//CCARTESIANO ->costruttore da due double   ok
//CCARTESIANO ->getReale()    ok
//CCARTESIANO ->getImmaginaria()    ok


class CCartesiano extends Complesso{
  private double reale;
  private double immaginaria;

  public double getReale(){
    return reale;
  }

  public double getImmaginaria(){
    return immaginaria;
  }

  public CCartesiano(double r, double i){
    reale = r;
    immaginaria = i;
  }

  public CCartesiano(){
    this(0, 0);
  }

  public Complesso converti(){
    double f = Math.sqrt(Math.pow(reale, 2) + Math.pow(immaginaria, 2));
    double m = Math.toDegrees(Math.atan(immaginaria / reale));
    CPolare result = new CPolare(f, m);
    return result;
  }

  public Complesso coniugato(){
    CCartesiano result = new CCartesiano(reale, -immaginaria);
    return result;
  }

  public Numero somma(Numero n){
    if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) n;
      CCartesiano result = new CCartesiano(reale + aux.reale, immaginaria + aux.immaginaria);
      return result;
    }
    else if(n instanceof CPolare){
      CPolare cp = (CPolare) n;
      CCartesiano aux = (CCartesiano) (cp.converti());

      Numero result = somma(aux);
      return result;
    }
    else{
      //----------------
      //GESTIRE ECCEZIONE-> tipi incompatibili
      //-----------------
      return this;
    }
  }

  public Numero differenza(Numero n){
    if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) n;
      CCartesiano result = new CCartesiano(reale - aux.reale, immaginaria - aux.immaginaria);
      return result;
    }
    else if(n instanceof CPolare){
      CPolare cp = (CPolare) n;
      CCartesiano aux = (CCartesiano) (cp.converti());

      Numero result = differenza(aux);
      return result;
    }
    else{
      //-------------------
      //GESTIRE ECCEZIONE->tipi incompatibili
      //-------------------
      return this;
    }
  }

  public Numero moltiplicazione(Numero n){
    if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) n;
      CCartesiano result = new CCartesiano((reale * aux.reale) - (immaginaria * aux.immaginaria), (immaginaria * aux.reale) + (reale * aux.immaginaria));
      return result;
    }
    else if(n instanceof CPolare){
      CPolare cp = (CPolare) n;
      CCartesiano aux = (CCartesiano) (cp.converti());

      Numero result = moltiplicazione(aux);
      return result;
    }
    else{
      //-------------------
      //GESTIRE ECCEZIONE->tipi incompatibili
      //-------------------
      return this;
    }
  }

  public Numero divisione(Numero n){
    if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) n;
      double r = ((reale * aux.reale) + (immaginaria * aux.immaginaria)) / (Math.pow(reale, 2) + Math.pow(aux.immaginaria, 2));
      double i = ((immaginaria * aux.reale) - (reale * aux.immaginaria)) / (Math.pow(reale, 2) + Math.pow(aux.immaginaria, 2));
      CCartesiano result = new CCartesiano(r, i);
      return result;
    }
    else if(n instanceof CPolare){
      CPolare cp = (CPolare) n;
      CCartesiano aux = (CCartesiano) (cp.converti());

      Numero result = divisione(aux);
      return result;
    }
    else{
      //-------------------
      //GESTIRE ECCEZIONE->tipi incompatibili
      //-------------------
      return this;
    }
  }

  public boolean equals(Object obj){
    if(!(obj instanceof CCartesiano)){
      //---------------
      //GESTIRE eccezione
      //-----------------
    }

    CCartesiano aux = (CCartesiano) obj;

    if((reale == aux.reale) && (immaginaria == aux.immaginaria)){
      return true;
    }
    else{
      return false;
    }
  }

  public String toString(){
    String result = new String(reale + " + i" + immaginaria + "\r\n");
    return result;
  }
}
