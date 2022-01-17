
package Clases;

public class Docente extends Persona implements Metodos{
    private String IDProfesor;
    private String Area;
    
    public Docente(String nom, int edad, String curp, String tel, String rh, String email, String s, String ID, String area){
       super(nom,edad,curp,tel,rh,email,s);
       IDProfesor = ID;
       Area = area;
    }

    public String obtenerID(){
        return IDProfesor;
    }
    
    public String obtenerArea(){
        return Area;
    }
    
    public void cambiarArea(String NewArea){
        Area = NewArea;
    }
    
    public String toString(){
        return super.toString() + "\nID: " + IDProfesor + "\nArea: " + Area;
    }

    @Override
    public void obtenerMaterias() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void agregarMateria(Materia M) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void removerMateria(Materia M) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void obtenerGrupos() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
