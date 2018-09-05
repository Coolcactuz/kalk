//classe astratta Complesso, derivata da Numero

//OBJECT -> equals()
//OBJECT -> toString()

//NUMERO -> somma()
//NUMERO -> differenza()
//NUMERO -> moltiplicazione()
//NUMERO -> divisione()

//COMPLESSO -> converti()
//COMPLESSO -> coniugato()
//COMPLESSO -> printComplesso()


abstract class Complesso extends Numero{
    public abstract Complesso converti() throws KalkException;
    public abstract Complesso coniugato() throws KalkException;

    public void printComplesso(){
      System.out.println(toString());
    }
}
