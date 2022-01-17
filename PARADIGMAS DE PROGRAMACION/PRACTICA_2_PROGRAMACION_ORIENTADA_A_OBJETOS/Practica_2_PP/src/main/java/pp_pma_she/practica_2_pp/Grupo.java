
package pp_pma_she.practica_2_pp;

import java.util.ArrayList;

public class Grupo {
    private String Nombre;
    private static int cantGrupos = 0;
    protected ArrayList<Materia> listaMaterias = new ArrayList<Materia>();
    
    public Grupo(String nom){
        Nombre = nom;
        cantGrupos++;
    }
    
    public String obtenerNombre(){
        return Nombre;
    }
    
    public void obtenerMaterias(){
        System.out.println("Las materias del grupo " + obtenerNombre() + " son:");
        for (Materia aux : listaMaterias) {
            aux.obtenerNombre();
        }
    }
    
    public void agregarMateria(Materia M){
        if(listaMaterias.contains(M))
            System.out.println("**El grupo ya esta inscrito en " + M.obtenerNombre() + " **");
        else
            listaMaterias.add(M);
    }
    
    public void removerMateria(Materia M){
        if(listaMaterias.contains(M))
            listaMaterias.remove(M);
        else
            System.out.println("El grupo ya no esta inscrito en " + M.obtenerNombre() + " **");
    }
    
    public void obtenerAlumnos(){
        System.out.println("Los alumnos inscritos en el grupo " + obtenerNombre() + " son:");
        for (Materia aux : listaMaterias) {
            aux.obtenerAlumnos();
        }
    }
    
    public void obtenerDocentes(){
        System.out.println("Los docentes a cargo del grupo " + obtenerNombre() + " son:");
        for (Materia aux : listaMaterias) {
            aux.obtenerDocentes();
        }
    }
}
