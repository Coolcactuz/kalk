public class Use{
  public static void main(String args[]){

    // ------------- TUPLA -------------------------

    Tupla t1 = new Tupla();
    Tupla t2 = new Tupla("MARCA,ASUS,MODELLO,K55VD");
    Tupla t3 = new Tupla("MARCA,ASUS,MODELLO,K55VD");

    //CASO/I D'ECCEZIONE

    // Tupla t3 = new Tupla("a,b,c");
    // Tupla t4 = new Tupla("a,,b");
    // Tupla t5 = new Tupla("a,b,");
    // Tupla t6 = new Tupla(",b,c");

    //-------------------

    System.out.println(t1.toString());
    System.out.println(t2.toString());
    System.out.println(t2.notEquals(t1));   //true
    System.out.println(t2.notEquals(t3));   //false
  }
}
