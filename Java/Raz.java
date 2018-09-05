//classe concreta Raz, derivata da Numero
//rappresenta un numero razionale

//TO DO:
//  GESTIRE ECCEZIONI

//1)implementazione dei metodi somma(), differenza(), moltiplicazione(), divisione() ereditati da Numero    ok
//3)implementazione dei metodi equals() e toString() ereditati da Object    ok
//4)implementazione dei metodi della classe:
//  a)costruttore di default    ok
//  b)costruttore da double   ok
//  d)costruttore con due parametri long  ok
//  e)convertitore da Raz a double  ok
//  f)potenza()   ok
//  g)getNum()    ok
//  h)getDen()    ok
//  i)getMCD()    ok
//  l)reciproco()   ok
//  m)semplifica()  ok
//  n)radiceQuadrata()    ok
//  o)printRaz()    ok


class Raz extends Numero{
  private long num;
  private long den;

  public Raz(long n, long d) throws KalkException{
    if(d == 0){
      throw new KalkException("denominatore nullo");
      //-----------------
      //GESTIRE ECCEZIONE
      //-----------------
    }
    else if(n == 0){
      num = 0;
      den = 1;
    }
    else if(d < 0){
      num = -n;
      den = -d;
    }
    else{
      num = n;
      den = d;
    }

    semplifica();
  }

  public Raz(double d) throws KalkException{
    int i = 1;

    while((d - (Math.floor(d * Math.pow(10, i)) / Math.pow(10, i))) != 0){
      i++;
    }

    long auxNum = (long) (d * Math.pow(10, i));
    long auxDen = (long) (Math.pow(10, i));

    Raz aux = new Raz(auxNum, auxDen);

    num = aux.getNum();
    den = aux.getDen();
  }

  public Raz() throws KalkException{
    this(0,1);
  }

  public double razToDouble(){
    double result = num / den;
    return result;
  }

  public Raz potenza(int exp) throws KalkException{
    if(exp == 0){
      Raz result = new Raz(1, 1);
      return result;
    }
    else if(exp < 0){
      Raz result = new Raz(((long) Math.pow(den, -exp)), ((long) Math.pow(num, -exp)));
      return result;
    }
    else{
      Raz result = new Raz(((long) Math.pow(num, exp)), ((long) Math.pow(den, exp)));
      return result;
    }
  }

  public long getNum(){
    return num;
  }

  public long getDen(){
    return den;
  }

  public long getMCD(long a, long b){
    long r = 0;

    while(b != 0){
      r = a % b;
      a = b;
      b = r;
    }

    if(a >= 0){
      return a;
    }
    else{
      return -a;
    }
  }

  public Raz reciproco() throws KalkException{
    Raz result = new Raz(den, num);
    return result;
  }

  private void semplifica(){
    long mcd = getMCD(num, den);
    num = num / mcd;
    den = den / mcd;
  }

  public double radiceQuadrata(){
    double result = (Math.sqrt(num) / Math.sqrt(den));
    return result;
  }

  public void printRaz(){
    System.out.println(toString());
  }

  public Numero somma(Numero n) throws KalkException{
    if(!(n instanceof Raz)){
      //gestire eccezione
      throw new KalkException("cast fallito", false);
    }

    Raz aux = (Raz) n;

    Raz result = new Raz(num * aux.den + aux.num * den, den * aux.den);
    return result;
  }

  public Numero differenza(Numero n) throws KalkException{
    if(!(n instanceof Raz)){
      //gestire eccezione
      throw new KalkException("cast fallito", false);
    }

    Raz aux = (Raz) n;

    Raz result = new Raz(num * aux.den - aux.num * den, den * aux.den);
    return result;
  }

  public Numero moltiplicazione(Numero n) throws KalkException{
    if(!(n instanceof Raz)){
      //gestire eccezione
      throw new KalkException("cast fallito", false);
    }

    Raz aux = (Raz) n;

    Raz result = new Raz(num * aux.num, den * aux.den);
    return result;
  }

  public Numero divisione(Numero n) throws KalkException{
    if(!(n instanceof Raz)){
      //gestire eccezione
      throw new KalkException("cast fallito", false);
    }

    Raz aux = (Raz) n;

    Raz result = new Raz(num * aux.den, den * aux.num);
    return result;
  }

  /*
  public void assign(Dato d){
    if(!(d instanceof Raz)){
      System.out.println("cast fallito");
      //gestire eccezione
    }

    Raz aux = (Raz) d;

    num = aux.num;
    den = aux.den;
  }*/

  public boolean equals(Object obj){
    if(!(obj instanceof Raz)){
      return false;
    }

    Raz aux = (Raz) obj;

    if((num == aux.num) && (den == aux.den)){
      return true;
    }
    else{
      return false;
    }
  }

  public String toString(){
    String result = new String(num + "/" + den);
    return result;
  }
}
