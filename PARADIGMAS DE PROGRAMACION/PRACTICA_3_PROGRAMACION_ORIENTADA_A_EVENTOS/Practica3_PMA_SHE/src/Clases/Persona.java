
package Clases;

public class Persona {
    private String Nombre;
    protected int Edad;
    private String CURP;
    protected String Telefono;
    private String FactorRH;
    protected String Correo;
    private String Sexo;
    private static int cantPersonas = 0;
    
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
}