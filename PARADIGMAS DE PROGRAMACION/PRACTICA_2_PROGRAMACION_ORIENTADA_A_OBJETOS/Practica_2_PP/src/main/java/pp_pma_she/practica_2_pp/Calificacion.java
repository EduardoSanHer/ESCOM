
package pp_pma_she.practica_2_pp;

public class Calificacion {
    private Materia M1;
    private int Parcial1;
    private int Parcial2;
    private int Parcial3;
    private int calificacionFinal;
    
    public Calificacion(Materia M){
        M1 = M;
        Parcial1 = 0;
        Parcial2 = 0;
        Parcial3 = 0;
        calificacionFinal = 0;
    }
    
    public Calificacion(Materia M, int P1){
        M1 = M;
        Parcial1 = P1;
        Parcial2 = 0;
        Parcial3 = 0;
        calificacionFinal = P1/3;
    }
    
    public Calificacion(Materia M, int P1, int P2){
        M1 = M;
        Parcial1 = P1;
        Parcial2 = P2;
        Parcial3 = 0;
        calificacionFinal = (P1 + P2)/3;
    }
    
    public Calificacion(Materia M, int P1, int P2, int P3){
        M1 = M;
        Parcial1 = P1;
        Parcial2 = P2;
        Parcial3 = P3;
        calificacionFinal = (P1 + P2 + P3)/3;
    }
    
    public void modificarCalificacion(int P1){
        Parcial1 = P1;
        calificacionFinal = (Parcial1 + Parcial2 + Parcial3)/3;
    }
    
    public void modificarCalificacion(int P1, int P2){
        Parcial1 = P1;
        Parcial2 = P2;
        calificacionFinal = (Parcial1 + Parcial2 + Parcial3)/3;
    }
    
    public void modificarCalificacion(int P1, int P2, int P3){
        Parcial1 = P1;
        Parcial2 = P2;
        Parcial3 = P3;
        calificacionFinal = (Parcial1 + Parcial2 + Parcial3)/3;
    }
    
    public int obtenerCalifPrimerP(){
        return Parcial1;
    }
    
    public int obtenerCalifSegundoP(){
        return Parcial2;
    }
    
    public int obtenerCalifTercerP(){
        return Parcial3;
    }
    public int obtenerCalifFinal(){
        return calificacionFinal;
    }
    
    public boolean aprobado(){
        return calificacionFinal >= 6;
    }
    
    public String apruebaOReprueba(){
        if(calificacionFinal<6)
            return "El alumno ha reprobado " + M1.obtenerNombre();
        else
            return "El alumno ha aprobado " + M1.obtenerNombre();
    }
    
    public String toString(){
        return "Materia: " + M1.obtenerNombre() + "\tCalificacion: " + calificacionFinal;
    }
}
