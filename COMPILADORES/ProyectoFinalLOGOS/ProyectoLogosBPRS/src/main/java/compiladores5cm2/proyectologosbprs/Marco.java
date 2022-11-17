/*
    |---------------------------------------------------|
    |              Proyecto Final: LOGO                 |
    |                 Datos del equipo                  |
    |   Integrantes: Bernal Trani Marco Antonio         |
    |                Patlani Mauricio Adriana           |
    |                Ruvalcaba Flores Martha Catalina   |
    |                Sandoval Hernández Eduardo         |
    |   Opcion: LOGO                                    |
    |   Fecha de entrega: 13 de junio de 2022           |
    |   Grupo: 5CM2                                     |
    |   Materia: Compiladores                           |
    |----------------------------------------------------|
*/
package compiladores5cm2.proyectologosbprs;

import java.util.ArrayList;

public class Marco {

    private ArrayList parametros;
    private int retorno;
    private String nombre;

    public Marco(){
        parametros = new ArrayList();
        retorno = 0;
        nombre = null;
    }
    
    public void agregarParametro(Object parametro){
        parametros.add(parametro);
    }
    
    public Object getParametro(int i){
        return parametros.get(i);
    }
    
    public void setParametros(ArrayList parametros) {
        this.parametros = parametros;
    }

    public int getRetorno() {
        return retorno;
    }

    public void setRetorno(int retorno) {
        this.retorno = retorno;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
 
}
