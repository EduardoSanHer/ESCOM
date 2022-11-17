/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 2                      |
    |   Tema: Uso de Java para modo gráfico     |
    |   Opcion: Dibujo de circulos, lineas y	|
    |           rectangulos                     |
    |   Fecha de entrega: 22 de abril de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/
//package compiladores.parser;  //<= Para ejecutar en NetBeans

import java.awt.*;
import java.util.*;
import java.lang.reflect.*;

class  Maquina {
    Tabla tabla;
    Stack pila;
    Vector prog;
    
    static int pc=0;
    int progbase=0;
    boolean returning=false;
    
    Method metodo;
    Method metodos[];
    Class c;
    Graphics g;
    double angulo;
    int x=0, y=0;
    Class parames[];
    
    Maquina(){
    }
    
    public void setTabla(Tabla t){ 
        tabla = t; 
    }
    
    public void setGraphics(Graphics g){ 
        this.g=g; 
    }
    
    Maquina(Graphics g){ 
        this.g=g; 
    }
    
    public Vector getProg(){ 
        return prog; 
    }
    
    void initcode(){
        pila=new Stack();
        prog=new Vector();
    }
    
    Object pop(){ 
        return pila.pop(); 
    }
    
    int code(Object f){
        System.out.println("Gen ("+f+") size="+prog.size());
        prog.addElement(f);
        return prog.size()-1;
    }
    
    void execute(int p){
        String inst;
        System.out.println("progsize="+prog.size());
        for(pc=0;pc < prog.size(); pc=pc+1){
            System.out.println("pc="+pc+" inst "+prog.elementAt(pc));
        }
        for(pc=p; !(inst=(String)prog.elementAt(pc)).equals("STOP") && !returning;){
            //for(pc=p;pc < prog.size();){
            try {
                //System.out.println("111 pc= "+pc);
                inst=(String)prog.elementAt(pc);
                pc=pc+1;
                System.out.println("222 pc= "+pc+" instr "+inst);
                c=this.getClass();
                //System.out.println("clase "+c.getName());
                metodo=c.getDeclaredMethod(inst, null);
                metodo.invoke(this, null);
            }
            catch(NoSuchMethodException e){
                System.out.println("No metodo "+e);
            }
            catch(InvocationTargetException e){
                System.out.println(e);
            }
            catch(IllegalAccessException e){
                System.out.println(e);
            }
        }
    }
    
    void constpush(){
        Simbolo s;
        Double d;
        s=(Simbolo)prog.elementAt(pc);
        pc=pc+1;
        pila.push(new Double(s.val));
    }
    
    void color(){
        Color colors[]={Color.red,Color.green,Color.blue};
        double d1;
        d1=((Double)pila.pop()).doubleValue();
        if(g!=null){
            g.setColor(colors[(int)d1]);
        }
    }
    

    void line(){
        double X1, Y1, X2, Y2;
        //Y1
        Y1 = ((Double)pila.pop()).doubleValue();
        //X1
        X1 = ((Double)pila.pop()).doubleValue();
        //Y2
        Y2 = ((Double)pila.pop()).doubleValue();
        //X2
        X2 = ((Double)pila.pop()).doubleValue();
        
        if(g!=null){
            (   new Linea((int)X1, (int)Y1, (int)X2, (int)Y2)   ).dibuja(g);
        }
    }
    
    void circulo(){
        double radio, X, Y;
        //X
        X = ((Double)pila.pop()).doubleValue();
        //Radio
        radio = ((Double)pila.pop()).doubleValue();
        //Y
        Y = ((Double)pila.pop()).doubleValue();
        if(g!=null){
            (   new Circulo((int)radio, (int)X, (int)Y)    ).dibuja(g);
        }
    }
    

    void rectangulo(){
        double X, Y, ancho, alto;
        //Alto
        alto = ((Double)pila.pop()).doubleValue();
        //Ancho
        ancho = ((Double)pila.pop()).doubleValue();
        //Y
        Y = ((Double)pila.pop()).doubleValue();
        //X
        X = ((Double)pila.pop()).doubleValue();
        if(g!=null){
            (   new Rectangulo((int)X, (int)Y, (int)ancho, (int)alto )  ).dibuja(g);
        }
    }
    
    void print(){
        Double d;
        d=(Double)pila.pop();
        System.out.println(""+d.doubleValue());
    }
    
    void prexpr(){
        Double d;
        d=(Double)pila.pop();
        System.out.print("["+d.doubleValue()+"]");
    }
    
}