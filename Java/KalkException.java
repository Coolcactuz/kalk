//implementazione delle eccezioni in java
//chi vuole gestire l'eccezione deve fare un controllo sul campo boolean per capire
//di che eccezione si tratta

//true = syntax_exception
//false = logic_exception


class KalkException extends Exception{
  private boolean exception_type;
  public boolean getExceptionType(){
    return exception_type;
  }
  public KalkException(String s, boolean b){
    super(s);
    exception_type = b;
  }
  public KalkException(String s){
    this(s, true);
  }
  public KalkException(){
    this("syntax exception");
  }
}
