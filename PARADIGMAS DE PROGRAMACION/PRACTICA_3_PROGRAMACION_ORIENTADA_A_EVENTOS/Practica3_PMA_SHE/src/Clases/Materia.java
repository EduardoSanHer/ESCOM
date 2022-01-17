
package Clases;
import java.util.*;

class Materia {
    private String Nombre;
    private String IDMateria;
    private int cantHoras;
    private int cantCreditos;
    private static int cantMaterias = 0;
    protected ArrayList<Docente> listaDocentes = new ArrayList<Docente>();
    protected ArrayList<Alumno> listaAlumnos = new ArrayList<Alumno>();
    
    public Materia(String nom, String ID, int cH, int cC){
        Nombre = nom;
        IDMateria = ID;
        cantHoras = cH;
        cantCreditos = cC;
        cantMaterias++;
    }
    
    public String obtenerNombre(){
        return Nombre;
    }
    
    public String obtenerID(){
        return IDMateria;
    }
    
    public int obtenerHoras(){
        return cantHoras;
    }
    
    public int obtenerCreditos(){
        return cantCreditos;
    }
    
    public static int totalMaterias(){
        return cantMaterias;
    }
    
    public void obtenerDocentes(){
        System.out.println("Los docentes que imparten " + Nombre + " son:");
        for (Docente aux : listaDocentes) {
            System.out.println(aux.obtenerNombre());
        }
    }
    
    public void agregarDocente(Docente D){
        if(listaDocentes.contains(D))
            System.out.println("**El docente ya se encuentra en la materia**");
        else
            listaDocentes.add(D);
    }
    
    public void removerDocente(Docente D){
        if(listaDocentes.contains(D))
            listaDocentes.remove(D);
        else
            System.out.println("**El docente no se encuentra en la materia**");
    }
    
    public void obtenerAlumnos(){
        System.out.println("Los alumnos inscritos en " + Nombre + " son:");
        for (Alumno aux : listaAlumnos) {
            System.out.println(aux.obtenerNombre());
        }
    }
    
    public void agregarAlumno(Alumno A){
        if(listaAlumnos.contains(A))
            System.out.println("**El alumno ya se encuentra en la materia**");
        else
            listaAlumnos.add(A);
    }
    
    public void removerAlumno(Alumno A){
        if(listaAlumnos.contains(A))
            listaAlumnos.remove(A);
        else
            System.out.println("**El alumno no se encuentra en la materia**");
    }
    
    public String toString(){
        return "Materia: " + Nombre + "\nID: " + IDMateria + "\nCantidad de horas: " + cantHoras + "\nCantidad de creditos: "
                + cantCreditos;
    }
}
