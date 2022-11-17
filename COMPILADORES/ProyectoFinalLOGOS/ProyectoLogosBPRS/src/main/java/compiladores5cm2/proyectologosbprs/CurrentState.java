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

import java.awt.Color;
import java.util.ArrayList;

public class CurrentState {

    ArrayList<Linea> lineas;
    double x;
    double y;
    int angulo;
    Color color;
    
    public CurrentState(){
        x = 0.0;
        y = 0.0;
        lineas = new ArrayList<Linea>(); 
        color = Color.WHITE;
    }
    
    public void agregarLinea(Linea linea){
        lineas.add(linea);
    }
    
    public void setPosicion(double x, double y){
        this.x = x;
        this.y = y;
    }
    
    public void limpiar(){
        lineas.clear();
    }

    public ArrayList<Linea> getLineas() {
        return lineas;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public int getAngulo() {
        return angulo;
    }

    public void setAngulo(int angulo) {
        this.angulo = angulo;
    } 

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    @Override
    public String toString(){
        String valor = "";
        for(int i = 0; i < lineas.size(); i++)
            valor += lineas.get(i)+", ";
        valor += "x:"+x+" y:"+y+" angulo: "+angulo;
        return valor;
    }
    
}
