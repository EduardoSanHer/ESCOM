
package pp_pma_she.practica_2_pp;

import java.util.ArrayList;


public class Persona {
    private String Nombre;
    protected int Edad;
    private String CURP;
    protected String Telefono;
    private String FactorRH;
    protected String Correo;
    private String Sexo;
    private static int cantPersonas = 0;
    protected ArrayList<Materia> listaMaterias = new ArrayList<Materia>();
    protected ArrayList<Grupo> listaGrupos = new ArrayList<Grupo>();
    
    
    public Persona (String nom, int edad, String curp, String tel, String rh, String email, String s){
        Nombre = nom;
        Edad = edad;
        CURP = curp;
        Telefono = tel;
        FactorRH = rh;
        Correo = email;
        Sexo = s;
        cantPersonas++;
    }
    
    public Persona (String nom, String curp){
        Nombre = nom;
        Edad = 0;
        CURP = curp;
        Telefono = "No especificado";
        FactorRH = "No especificado";
        Correo = "No especificado";
        Sexo = "No especificado";
        cantPersonas++;
    }
    
    public String obtenerNombre(){
        return Nombre;
    }
    
    public int obtenerEdad(){
        return Edad;
    }
    
    public void establecerEdad(int Edad){
        this.Edad = Edad;
    }
    
    public String obtenerCURP(){
        return CURP;
    }
    
    public String obtenerTelefono(){
        return Telefono;
    }
    
    public void establecerTelefono(String Telefono){
        this.Telefono = Telefono;
    }
    
    public String obtenerFactorRH(){
        return FactorRH;
    }
    
    public void establecerFactorRH(String FactorRH){
        this.FactorRH = FactorRH;
    }
    
    public String obtenerCorreo(){
        return Correo;
    }
    
    public void establecerCorreo(String Correo){
        this.Correo = Correo;
    }
    
    public String obtenerSexo(){
        return Sexo;
    }
    
    public String toString(){
        return "Nombre: " + Nombre + "\nEdad: " + Edad + "\nCURP: " + CURP + "\nTelefono: " + Telefono 
                + "\nFactor RH: " + FactorRH + "\nCorreo: " + Correo + "\nSexo: " + Sexo;
    }
    
    public static int totalPersonas(){
        return cantPersonas;
    }
    
    public void agregarGrupo(Grupo G){
        listaGrupos.add(G);
    }
    
    public void removerGrupo(Grupo G){
        listaGrupos.remove(G);
    }
}
