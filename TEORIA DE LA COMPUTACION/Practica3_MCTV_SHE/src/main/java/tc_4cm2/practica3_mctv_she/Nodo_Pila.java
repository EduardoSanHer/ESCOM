
package tc_4cm2.practica3_mctv_she;

public class Nodo_Pila {
    private String dato;
    private Nodo_Pila siguiente;
    
    public Nodo_Pila(){
        dato=null;
        siguiente=null;
    }
    
    public Nodo_Pila(String d){
        dato=d;
        siguiente=null;
    }
    
    public Nodo_Pila(String d,Nodo_Pila s){
        dato=d;
        siguiente=s;
    }
    
    public String getDatoNodo(){
        return dato;
    }
    
    public void setDato(String dato){
        this.dato = dato;
    }
    
    public Nodo_Pila getSiguiente(){
        return siguiente;
    }
    
    public void setSiguiente(Nodo_Pila Siguiente){
        this.siguiente = Siguiente;
    }
}
