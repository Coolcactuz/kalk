//classe astratta Numero, estende Dato ed e' superclasse di tutti i tipi numerici

//TO DO:
//  GESTIRE ECCEZIONI: segnalate nel codice

abstract class Numero extends Dato{
  public final static double pi = 3.1415926535;
  //public static double e = 2.71828;

  public abstract Numero somma(Numero n);
  public abstract Numero differenza(Numero n);
  public abstract Numero moltiplicazione(Numero n);
  public abstract Numero divisione(Numero n);
}
