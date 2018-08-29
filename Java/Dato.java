// classe Dato, superclasse di ogni classe della gerarchia, utilizzata per il parsing
// rappresenta il tipo di dato piu' generico possibile


// 1) Distruttore: non serve
// 2) Uguaglianza: eredita il metodo public boolean equals(Object) da Object, ma non fa overriding
// 3) Disuguaglianza: metodo notEquals(), ritorna l'opposto di equals()
// 4) Assegnazione: metodo assign(), per evitare assegnazioni tra reference con condivisione di memoria


abstract class Dato{

  public boolean notEquals(Object obj){
      return !(this.equals(obj));
  }

  //public abstract void assign(Dato d);
}
