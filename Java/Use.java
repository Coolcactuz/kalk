public class Use{
  public static void main(String args[]){

    // -------------TUPLA-------------------------
    //    a)costruttore di default
    //    b)costruttore da stringa
    //    c)printTupla
    //    d)printDati
    //    e)printMetadati
    //    f)existsMetadato
    //    g)searchByMetadato
    //    h)searchByEntry
    //    i)insert
    //    l)erase
    //    m)isNull
    //    o)differenza
    //    p)intersezione
    //    q)join
    //    r)notEquals
    //    s)equals
    //    t)toString

    Tupla t1 = new Tupla();
    Tupla t2 = new Tupla("MARCA,apple,PRODOTTO,iphone,MODELLO,6s");

    t2.printTupla();
    t2.printDati();
    t2.printMetadati();

    System.out.println((t2.existsMetadato("PRODOTTO")) ? "PRODOTTO ESISTE" : "PRODOTTO NON ESISTE");
    System.out.println(t2.searchByMetadato("MODELLO"));
    System.out.println((t2.searchByEntry("MARCA,samsung")) ? "L'ENTRY CERCATA ESISTE" : "L'ENTRY CERCATA NON ESISTE");

    t2.insert("COLORE,grigio");
    t2.printTupla();

    t2.erase();
    t2.printTupla();

    System.out.println((t2.isNull()) ? "NULLA" : "NON NULLA");

    System.out.println((t1.notEquals(t2)) ? "T1 DIVERSO DA T2" : "T1 UGUALE A T2");
    System.out.println((t1.equals(t2)) ? "T1 UGUALE A T2" : "T1 DIVERSO DA T2");

    System.out.println("Esempio Tupla.toString()" + t2.toString());

    Tupla t3 = new Tupla("MARCA,apple,PRODOTTO,appleTV");

    (t2.intersezione(t3)).printTupla();

    t3.insert("DISPONIBILE,si");
    (t2.differenza(t3)).printTupla();

    (t2.join(t3)).printTupla();
    (t3.join(t2)).printTupla();

    //----------------------------------------------


    //----------------RAZ---------------------------
    //  a)costruttore di default    ok
    //  b)costruttore da double   ok
    //  d)costruttore con due parametri long  ok
    //  e)convertitore da Raz a double  ok
    //  f)potenza()   ok
    //  g)getNum()    ok
    //  h)getDen()    ok
    //  i)getMCD()    ok
    //  l)reciproco()   ok
    //  n)radiceQuadrata()    ok
    //  o)printRaz()    ok
    //  p)somma()
    //  q)differenza()
    //  r)moltiplicazione()
    //  s)divisione()
    //  t)equals()
    //  u)notEquals()
    //  v)toString()

    Raz ra1 = new Raz();

    double raAux1 = 0.35;
    Raz ra2 = new Raz(raAux1);

    Raz ra3 = new Raz(25, 30);

    double raAux2 = ra3.razToDouble();

    (ra3.potenza(2)).printRaz();

    System.out.println(ra3.getMCD(ra3.getNum(), ra3.getDen()));

    (ra3.reciproco()).printRaz();

    Raz ra4 = new Raz(25, 16);

    System.out.println(ra4.radiceQuadrata());

    System.out.println(ra3.equals(ra4));
    System.out.println(ra3.notEquals(ra4));

    System.out.println(ra4.toString());

    System.out.println(ra3.somma(ra4));
    System.out.println(ra3.differenza(ra4));
    System.out.println(ra3.moltiplicazione(ra4));
    System.out.println(ra3.divisione(ra4));

    //----------------------------------------------


    //----------------CPOLARE-----------------------
    //OBJECT -> equals()    ok
    //OBJECT -> toString()  ok

    //DATO -> notEquals()


    //NUMERO -> somma()
    //NUMERO -> differenza()
    //NUMERO -> moltiplicazione()
    //NUMERO -> divisione()

    //COMPLESSO -> converti()   ok
    //COMPLESSO -> coniugato()  ok
    //COMPLESSO -> printComplesso()

    //CPOLARE ->costruttore di default   ok
    //CPOLARE ->costruttore da due double   ok
    //CPOLARE ->getModulo()   ok
    //CPOLARE ->getFase()   ok

    CPolare p1 = new CPolare();
    CPolare p2 = new CPolare(7.62, 18);
    System.out.println(p2.getModulo());
    System.out.println(p2.getFase());

    (p2.converti()).printComplesso();
    (p2.coniugato()).printComplesso();

    CPolare p3 = new CPolare(5, 12);

    ((Complesso) (p2.somma(p3))).printComplesso();
    ((Complesso) (p2.differenza(p3))).printComplesso();
    ((Complesso) (p2.moltiplicazione(p3))).printComplesso();
    ((Complesso) (p2.divisione(p3))).printComplesso();

    System.out.println(p2.equals(p3));
    System.out.println(p2.notEquals(p3));
    System.out.println(p2.toString());

    //----------------------------------------------


    //----------------CCARTESIANO---------------------
    //OBJECT -> equals()
    //OBJECT -> toString()

    //DATO -> notEquals()

    //NUMERO -> somma()   ok
    //NUMERO -> differenza()    ok
    //NUMERO -> moltiplicazione()   ok
    //NUMERO -> divisione()   ok

    //COMPLESSO -> converti()   ok
    //COMPLESSO -> coniugato()    ok
    //COMPLESSO -> printComplesso()

    //CCARTESIANO ->costruttore di default    ok
    //CCARTESIANO ->costruttore da due double   ok
    //CCARTESIANO ->getReale()    ok
    //CCARTESIANO ->getImmaginaria()    ok

    CCartesiano ca1 = new CCartesiano();
    CCartesiano ca2 = new CCartesiano(3.7, 9.2);
    System.out.println(ca2.getReale());
    System.out.println(ca2.getImmaginaria());

    (ca2.converti()).printComplesso();
    (ca2.coniugato()).printComplesso();

    CCartesiano ca3 = new CCartesiano(6, 9);

    ((Complesso) (ca2.somma(ca3))).printComplesso();
    ((Complesso) (ca2.differenza(ca3))).printComplesso();
    ((Complesso) (ca2.moltiplicazione(ca3))).printComplesso();
    ((Complesso) (ca2.divisione(ca3))).printComplesso();

    System.out.println(ca2.equals(ca3));
    System.out.println(ca2.notEquals(ca3));
    System.out.println(ca2.toString());

    //-----------------------------------------------


    //----------------COMPONENTE---------------------
    //OBJECT -> equals()
    //OBJECT -> toString()

    //DATO -> notEquals()

    //COMPONENTE
    //    d)impedenza
    //    e)serie
    //    f)parallelo
    //    g)getVolt
    //    h)setVolt
    //    i)getFreq
    //    l)setFreq

    //RESISTORE
    //    a)costruttore da double
    //    c)costruttore di default

    //INDUTTORE
    //    a)costruttore da double
    //    c)costruttore di default

    //CONDENSATORE
    //    a)costruttore da double
    //    c)costruttore di default

    Resistore re1 = new Resistore();
    Resistore re2 = new Resistore(7);

    Condensatore co1 = new Condensatore();
    Condensatore co2 = new Condensatore(2);

    Induttore i1 = new Induttore();
    Induttore i2 = new Induttore(3.56);

    Componente.setVolt(14);
    Componente.setFreq(2);

    System.out.println(Componente.getVolt());
    System.out.println(Componente.getFreq());

    System.out.println(re2.impedenza());
    System.out.println(co2.impedenza());
    System.out.println(i2.impedenza());

    System.out.println(re2.equals(co2));
    System.out.println(re2.notEquals(co2));

    System.out.println(i2.toString());

    //-----------------------------------------------
  }
}
