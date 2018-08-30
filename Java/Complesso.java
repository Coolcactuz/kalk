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


class Complesso extends Numero{
    public abstract Complesso converti();
    public abstract Complesso coniugato();

    public void printComplesso(){
      System.out.println(toString());
    }
}
