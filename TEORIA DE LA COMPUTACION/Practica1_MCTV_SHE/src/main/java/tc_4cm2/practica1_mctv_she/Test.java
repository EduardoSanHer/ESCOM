
package tc_4cm2.practica1_mctv_she;

public class Test {
    public static void main(String []args ){
        Alfabeto prueba = new Alfabeto();
        prueba.Add('a','c');
        System.out.println("Alfabeto: " + prueba.simbolos);
        prueba.impAlfabeto();
        prueba.addCadenas();
        prueba.queEs();
        prueba.lenguajes();
        prueba.union();
        prueba.concatenacion();
        prueba.vocales();
    }
}
