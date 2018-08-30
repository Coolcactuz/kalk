//classe concreta CPolare, derivata da Complesso
//rappresenta un numero complesso in forma polare

//OBJECT -> equals()    ok
//OBJECT -> toString()  ok

//NUMERO -> somma()
//NUMERO -> differenza()
//NUMERO -> moltiplicazione()
//NUMERO -> divisione()

//COMPLESSO -> converti()   ok
//COMPLESSO -> coniugato()  ok

//CCARTESIANO ->costruttore di default   ok
//CCARTESIANO ->costruttore da due double   ok
//CCARTESIANO ->getModulo()   ok
//CCARTESIANO ->getFase()   ok


class CPolare extends Complesso{
  private double modulo;
  private double fase;

  public double getFase(){
    return fase;
  }

  public double getModulo(){
    return modulo;
  }

  public CPolare(double m, double f){
    if(m < 0){
      //------------
      //GESTIRE ECCEZIONE
      //modulo negativo
      //---------------
    }
    else if(m == 0){
      modulo = 0;
      fase = 0;
    }
    else{   //m positivo
      modulo = m;

      while((f >= 360) || (f < 0)){
        if(f >= 360){
          f = f - 360;
        }
        else{
          f = f + 360;
        }
      }

      fase = f;
    }
  }

  public CPolare(){
    this(0, 0);
  }

  public Complesso converti(){
    double real = modulo * Math.cos(Math.toRadians(fase));
    double img = modulo * Math.sin(Math.toRadians(fase));

    CCartesiano result = new Ccartesiano(real, img);
    return result;
  }

  public Complesso coniugato(){
    CPolare result = new CPolare(modulo, -fase);
    return result;
  }

  public boolean equals(Object obj){
    if(!(obj instanceof CPolare)){
      //---------------
      //GESTIRE ECCEZIONE
      //---------------
    }

    CPolare aux = (CPolare) obj;

    if((modulo == aux.modulo) && (fase == aux.fase)){
      return true;
    }
    else{
      return false;
    }
  }

  public String toString(){
    String result = new String(modulo + "<" + fase + "\r\n");
    return result;
  }

  public Numero somma(Numero n){
    if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) n;
      CCartesiano cc = (CCartesiano) (converti());

      CCartesiano sommaCartesiana = (CCartesiano) aux.somma(cc);

      CPolare sommaPolare = (CPolare) (sommaCartesiana.converti());

      return sommaPolare;
    }
    else if(n instanceof CPolare){
      CPolare cp = (CPolare) n;
      CCartesiano supp = (CCartesiano) (cp.converti());

      Numero result = somma(supp);
      return result;
    }
    else{
      //-------------------
      //GESTIRE ECCEZIONE-> tipi incompatibili
      //-------------------
    }
  }

  public Numero differenza(Numero n){
    if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) (converti());
      CCartesiano cc = (CCartesiano) n;

      CCartesiano differenzaCartesiana = (CCartesiano) aux.differenza(cc);

      CPolare differenzaPolare = (CPolare) (differenzaCartesiana.converti());
      return differenzaPolare;
    }
    else if(n instanceof CPolare){
      CPolare cp = (CPolare) n;
      CCartesiano aux = (CCartesiano) (cp.converti());

      Numero result = differenza(aux);
      return result;
    }
    else{
      //-------------------
      //GESTIRE ECCEZIONE-> tipi incompatibili
      //-------------------
    }
  }

  public Numero moltiplicazione(Numero n){
    if(n instanceof CPolare){
      CPolare cp = (CPolare) n;

      double m = modulo * cp.modulo;
      double f = Math.toDegrees(Math.atan(Math.toRadians(fase)) + Math.atan(Math.toRadians(cp.fase)));

      CPolare result = new CPolare(m, f);
      return result;
    }
    else if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) n;
      CPolare cp = (CPolare) (aux.converti());

      return moltiplicazione(cp);
    }
    else{
      //-------------------
      //GESTIRE ECCEZIONE-> tipi incompatibili
      //-------------------
    }
  }

  public Numero divisione(Numero n){
    if(n instanceof CPolare){
      CPolare cp = (CPolare) n;

      double m = modulo / cp.modulo;
      double f = fase - cp.fase;

      CPolare result = new CPolare(m, f);
      return result;
    }
    else if(n instanceof CCartesiano){
      CCartesiano aux = (CCartesiano) n;
      CPolare cp = (CPolare) (aux.converti());

      return divisione(cp);
    }
    else{
      //-------------------
      //GESTIRE ECCEZIONE-> tipi incompatibili
      //-------------------
    }
  }

}
