// classe Dato, superclasse di ogni classe della gerarchia, utilizzata per il parsing
// rappresenta il tipo di dato piu' generico possibile

// SCELTE PROGETTUALI:
// Distruttore: non serve
// Uguaglianza: eredita il metodo public boolean equals(Object) da Object, ma non fa overriding
// Disuguaglianza: metodo notEquals(), ritorna l'opposto di equals()
// Assegnazione: metodo assign(), per evitare assegnazioni tra reference con condivisione di memoria


abstract class Dato{

  public boolean notEquals(Object obj){
      return !(this.equals(obj));
  }

  public abstract Dato assign(Dato d);
}
