
package Clases;

public class Grupo {
    private String Nombre;
    private String Codigo;
    private Docente unDocente;
    
    public Grupo(String nom, String cod, Docente unDocente){
        Nombre = nom;
        Codigo = cod;
        unDocente = unDocente;
    }
    
    public String obtenerCodigo() {
        return Codigo;
    }

    public void darCodigo(String codigo) {
        this.Codigo = codigo;
    }
    
    public String obtenerNombre(){
        return Nombre;
    } 
    
    public void setNombre(String nombre) {
        Nombre = nombre;
    }
    
    public Docente getUnDocente() {
        return unDocente;
    }

    public void setUnDocente(Docente unDocente) {
        this.unDocente = unDocente;
    }
    
    public String toString() {
        return obtenerNombre();
    }  
}
