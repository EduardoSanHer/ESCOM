
package Clases;

public class Alumno extends Persona implements Metodos{
    private String NumMatricula;
   
    public Alumno(String nom, int edad, String curp, String tel, String rh, String email, String s, String NumMat){
       super(nom,edad,curp,tel,rh,email,s);
       NumMatricula = NumMat;
    }
   
    public String obtenerNumeroDeMatricula(){
       return NumMatricula;
    }
   
    public String toString(){
       return super.toString() + "\nNumero de matricula: " + NumMatricula;
    }

    public void obtenerMaterias() {
        throw new UnsupportedOperationException("Not supported yet."); 
    }

    public void agregarMateria(Materia M) {
        throw new UnsupportedOperationException("Not supported yet."); 
    }

    public void removerMateria(Materia M) {
        throw new UnsupportedOperationException("Not supported yet."); 
    }

    public void obtenerGrupos() {
        throw new UnsupportedOperationException("Not supported yet."); 
    }
}
