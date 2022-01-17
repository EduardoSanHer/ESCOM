
package tc_4cm2.practica3_mctv_she;

import java.util.ArrayList;

public class Pila {
    private Nodo_Pila top;
    private int tamanoPila;
    
    public Pila(){
        top = null;
        tamanoPila = 0;
    }
    
    public boolean esVacia(){
        return top==null;
    }
    
    public int getTamano(){
        return tamanoPila;
    }
    
    public void apilar(String dato){
        Nodo_Pila N = new Nodo_Pila();
        N.setDato(dato);
        if(esVacia())
            top = N;
        else{
            N.setSiguiente(top);
            top = N;
        }
        tamanoPila++;
    }
    
    public void desapilar(){
        if(!esVacia()){
            top = top.getSiguiente();
            tamanoPila--;
        }
    }
    
    public String getTop() /*throws Exception*/{
        if(!esVacia()){
            return top.getDatoNodo();
        }
        else{
            return "Z";
            //throw new Exception("La pila esta vacia");
        }
    }
    
    public boolean buscar(String dato){
        Nodo_Pila aux = top;
        boolean existe = false;
        while(!existe && aux!=null){
            if(dato == aux.getDatoNodo())
                existe = true;
            else
                aux = aux.getSiguiente();
        }
        return existe;
    }
    
    public void eliminar(){
        top = null;
        tamanoPila = 0;
    }
    
    public void imprimirPila(){
        Nodo_Pila aux = top;
        System.out.print("|");
        while(aux != null){
            System.out.print("  " + aux.getDatoNodo() + "  ");
            aux = aux.getSiguiente();
        }
        System.out.println("");
    }
    
    public Pila copiarPila(){
        Nodo_Pila aux = top;
        Pila NPila = new Pila();
        while(aux != null){
            NPila.apilar(aux.getDatoNodo());
            aux = aux.getSiguiente();
        }
        Pila NNPila = new Pila();
        aux = NPila.top;
        while(aux != null){
            NNPila.apilar(aux.getDatoNodo());
            aux = aux.getSiguiente();
        }
        return NNPila;
    }
    
}
