
package pp_pma_she.practica_2_pp;

import java.util.ArrayList;

public class Tutor extends Docente{
    private static int cantTutores = 0;
    private int cantAlumnos = 0;
    private int maxAlumnos = 10;
    protected ArrayList<Alumno> listaAlumnos = new ArrayList<Alumno>();
    
    public Tutor(String nom, int edad, String curp, String tel, String rh, String email, String s, long ID, String area){
        super(nom,edad,curp,tel,rh,email,s,ID,area);
        cantTutores++;
    }
    
    public Tutor(String nom, String curp, long ID, String area){
        super(nom,curp,ID,area);
        cantTutores++;
    }
    
    public void agregarAlumno(Alumno A){
        if(cantAlumnos<10){
            if(!listaAlumnos.contains(A)){
                listaAlumnos.add(A);
                cantAlumnos++;
            }
            else
                System.out.println("**El alumno ya se encuentra**");
        }
        else
            System.out.println("**El tutor ya tiene la cantidad maxima de alumnos permitidos**");
    }
    
    public void removerAlumno(Alumno A){
        if(listaAlumnos.contains(A)){
            listaAlumnos.remove(A);
            cantAlumnos--;
        }
        else
            System.out.println("**El alumno no se encuentra**");
    }
    
    public void obtenerAlumnos(){
        System.out.println("Los alumnos tutorados por el docente " + super.obtenerNombre() + " son:");
        for (Alumno aux : listaAlumnos) {
            System.out.println(aux.obtenerNombre());
        }
    }
    
    public static int totalTutores(){
        return cantTutores;
    }
}
