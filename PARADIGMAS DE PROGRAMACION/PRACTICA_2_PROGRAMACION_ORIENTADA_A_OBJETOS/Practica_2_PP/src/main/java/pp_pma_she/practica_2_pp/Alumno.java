
package pp_pma_she.practica_2_pp;

import java.util.ArrayList;

public class Alumno extends Persona{
    private long NumMatricula;
    private static int cantAlumnos = 0;
    protected ArrayList<Calificacion> listaCalificaciones = new ArrayList<Calificacion>();
    protected int creditosInscritos = 0;
   
    public Alumno(String nom, int edad, String curp, String tel, String rh, String email, String s, long NumMat){
       super(nom,edad,curp,tel,rh,email,s);
       NumMatricula = NumMat;
       cantAlumnos++;
    }
   
    public Alumno(String nom, String curp, long NumMat){
       super(nom,curp);
       NumMatricula = NumMat;
       cantAlumnos++;
    }
   
    public long obtenerNumeroDeMatricula(){
       return NumMatricula;
    }
   
    public String toString(){
       return super.toString() + "\nNumero de matricula: " + NumMatricula;
    }
   
    public static int totalAlumnos(){
       return cantAlumnos;
    }
   
    public void obtenerMaterias(){
        System.out.println("Las materias del alumno " + super.obtenerNombre() + " son:");
        for (Materia aux : listaMaterias) {
            System.out.println(aux.obtenerNombre());
        }
    }
    
    public void agregarMateria(Materia M){
        if(listaMaterias.contains(M))
            System.out.println("**El alumno ya esta inscrito en " + M.obtenerNombre() + " **");
        else
            listaMaterias.add(M);
        obtenerCreditosInscritos();
    }
    
    public void removerMateria(Materia M){
        if(listaMaterias.contains(M))
            listaMaterias.remove(M);
        else
           System.out.println("**El alumno no esta inscrito en " + M.obtenerNombre() + " **");
        obtenerCreditosInscritos();
    }
   
    public void obtenerCalificaciones(){
        System.out.println("Las calificaciones del alumno " + super.obtenerNombre() + " son:");
        for (Calificacion aux : listaCalificaciones) {
            System.out.println(aux);
        }
    }
    
    public void agregarCalificacion(Calificacion C){
        if(listaCalificaciones.contains(C))
            System.out.println("**El alumno ya tiene calificacion en la materia**");
        else
            listaCalificaciones.add(C);
    }
    
    public void removerCalificacion(Calificacion C){
        if(listaCalificaciones.contains(C))
            listaCalificaciones.remove(C);
        else
            System.out.println("**El alumno ya no tiene calificacion en la materia");
    }
   
    public void obtenerGrupos(){
        System.out.println("Los grupos donde el(la) estudiante " + super.obtenerNombre() + " se encuentra inscrito(a) son:");
        for (Grupo aux : listaGrupos) {
            System.out.println(aux.obtenerNombre());
        }
    }
   
    public int obtenerCreditosInscritos(){
        creditosInscritos = 0;
        for (Materia aux : listaMaterias) {
            creditosInscritos += aux.obtenerCreditos();
        }
        return creditosInscritos;
    }
}
