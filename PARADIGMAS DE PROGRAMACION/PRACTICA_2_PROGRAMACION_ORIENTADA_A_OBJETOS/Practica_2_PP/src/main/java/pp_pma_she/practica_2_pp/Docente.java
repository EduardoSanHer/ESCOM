
package pp_pma_she.practica_2_pp;

public class Docente extends Persona{
    private long IDProfesor;
    private String Area;
    private static int cantDocentes = 0;
    
    public Docente(String nom, int edad, String curp, String tel, String rh, String email, String s, long ID, String area){
       super(nom,edad,curp,tel,rh,email,s);
       IDProfesor = ID;
       Area = area;
       cantDocentes++;
    }
   
    public Docente(String nom, String curp, long ID, String area){
       super(nom,curp);
       IDProfesor = ID;
       Area = area;
       cantDocentes++;
    }
    
    public long obtenerID(){
        return IDProfesor;
    }
    
    public String obtenerArea(){
        return Area;
    }
    
    public void cambiarArea(String NewArea){
        Area = NewArea;
    }
    
    public void obtenerMaterias(){
        System.out.println("Las materias que el(la) docente " + super.obtenerNombre() + " imparte son:");
        for (Materia aux : listaMaterias) {
            System.out.println(aux.obtenerNombre());
        }
    }
    
    public void agregarMateria(Materia M){
        if(listaMaterias.contains(M))
            System.out.println("**La materia " + M.obtenerNombre() + " ya es impartida por el(la) profesor(a)**");
        else
        listaMaterias.add(M);
    }
    
    public void removerMateria(Materia M){
        if(listaMaterias.contains(M))
            listaMaterias.remove(M);
        else
            System.out.println("**La materia " + M.obtenerNombre() + " no es impartida por el(la) profesor(a)**");
    }
    
    public String toString(){
        return super.toString() + "\nID: " + IDProfesor + "\nArea: " + Area;
    }
    
    public static int totalDocentes(){
        return cantDocentes;
    }
    
    public void obtenerGrupos(){
        System.out.println("Los grupos a cargo de el(la) docente " + super.obtenerNombre() + " son:");
        for (Grupo aux : listaGrupos) {
            System.out.println(aux.obtenerNombre());
        }
    }
}
