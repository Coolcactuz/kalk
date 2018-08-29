//classe concreta Raz, derivata da Numero
//rappresenta un numero razionale

//TO DO:
//  GESTIRE ECCEZIONI

//1)implementazione dei metodi somma(), differenza(), moltiplicazione(), divisione() ereditati da Numero
//2)implementazione del metodo assign() ereditato da Dato
//3)implementazione dei metodi equals() e toString() ereditati da Object
//4)implementazione dei metodi della classe:
//  a)costruttore di default
//  b)costruttore da double
//  c)costruttore da stringa
//  d)costruttore con due parametri long
//  e)convertitore da Raz a double
//  f)potenza()
//  g)getNum()
//  h)getDen()
//  i)getMCD()
//  l)reciproco()
//  m)semplifica()
//  n)radiceQuadrata()
//  o)printRaz()

class Raz extends Numero{
  private long num;
  private long den;

  public Raz(long n, long d){
    if(d == 0){
      System.out.println("denominatore nullo");
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

  public Raz(String s){

  }
}
