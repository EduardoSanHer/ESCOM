
package ada_sandovalhernandez.practica3_algoritmosvoraces_she;

import java.util.ArrayList;

class Asignacion{
    public String Nombre;
    public String Tarea;
    public int Costo;
    
    public Asignacion(String Nombre, String Tarea, int Costo){
        this.Nombre = Nombre;
        this.Tarea = Tarea;
        this.Costo = Costo;
    }
}

class Tabla{
    public String Nombres[];
    public String Tareas[];
    public int Costos[][];
    public ArrayList<Asignacion> listaAsignaciones;
    public ArrayList<Asignacion> listaAsignaciones2;
    public ArrayList<String> listaTrabajadores;
    public ArrayList<String> listaTareas;
    
    public Tabla(int n){
        Nombres = new String[n];
        Tareas = new String[n];
        Costos = new int[n][n];
        listaAsignaciones = new ArrayList<Asignacion>();
        listaAsignaciones2 = new ArrayList<Asignacion>();
        listaTrabajadores = new ArrayList<String>();
        listaTareas = new ArrayList<String>();
    }
    
    //Este método resuelve el problema por la primera opcion
    public void Opcion1(){
        for(int i=0 ; i<Nombres.length ; i++){
            int aux = 10000, pos = 0 ;
            for(int j=0 ; j<Nombres.length ; j++){
                if(!listaTrabajadores.contains(Nombres[j])){
                    if(Costos[j][i]<aux){
                        aux = Costos[j][i];
                        pos = j;
                    }
                }
            }
            listaTrabajadores.add(Nombres[pos]);
            Asignacion a = new Asignacion(Nombres[pos],Tareas[i],Costos[pos][i]);
            listaAsignaciones.add(a);
        }
    }
    
    //Este método resuelve el problema por la segunda opcion
    public void Opcion2(){
        for(int i=0 ; i<Nombres.length ; i++){
            int aux = 10000, pos = 0 ;
            for(int j=0 ; j<Nombres.length ; j++){
                if(!listaTareas.contains(Tareas[j])){
                    if(Costos[i][j]<aux){
                        aux = Costos[i][j];
                        pos = j;
                    }
                }
            }
            listaTareas.add(Tareas[pos]);
            Asignacion a = new Asignacion(Nombres[i],Tareas[pos],Costos[i][pos]);
            listaAsignaciones2.add(a);
        }
    }
    
    /*
    public String impTrabajadores(int n){
        if(n<Nombres.length)
            return Nombres[n] + " " + impTrabajadores(n+1);
        else
            return "|";
    }
    */
    
    //Este metodo imprime las tareas
    public String impTareas(int n){
        if(n<Tareas.length)
            return Tareas[n] + "\t" + impTareas(n+1);
        else
            return "|";
    }
    
    //Este metodo imprime una determinada fila de la matriz de costos
    public String impFilaCostos(int f,int n){
        if(n<Costos.length)
            return Costos[f][n] + "\t\t" + impFilaCostos(f,n+1);
        else
            return "|";
    }
    
    //Este metodo imprime la tabla completa, utiliza los metodos anteriores
    public void impTabla(){
        System.out.println("---------------------------------------------");
        System.out.println("Trabajador" + "   " + impTareas(0)/*Arrays.toString(Tareas) impTrabajadores(0)*/);
        for(int i=0 ; i<Nombres.length ; i++)
            System.out.println(Nombres[i] + "    \t" + impFilaCostos(i,0));
        System.out.println("---------------------------------------------");
    }
    
    //Este metodo determina el costo total de la primera opcion
    public int costoTotal(){
        int a = 0;
        for (Asignacion aux : listaAsignaciones)
            a += aux.Costo;
        return a;
    }
    
    //Este metodo determina el costo total de la segunda  opcion
    public int costoTotal2(){
        int a = 0;
        for (Asignacion aux : listaAsignaciones2)
            a += aux.Costo;
        return a;
    }
    
    public void impAsignaciones(){
        System.out.println("-----------------Opcion 1---------------------");
        System.out.println("Seleccion final\nTrabajador\tTarea    \tCosto");
        System.out.println("---------------------------------------------");
        for (Asignacion aux : listaAsignaciones)
            System.out.println(aux.Nombre + "    \t" + aux.Tarea + "\t" + aux.Costo);
        System.out.println("---------------------------------------------");
        System.out.println("El costo total es: " + costoTotal());
        System.out.println("---------------------------------------------");
    }
    
    public void impAsignaciones2(){
        System.out.println("-----------------Opcion 2---------------------");
        System.out.println("Seleccion final\nTrabajador\tTarea    \tCosto");
        System.out.println("---------------------------------------------");
        for (Asignacion aux : listaAsignaciones2)
            System.out.println(aux.Nombre + "    \t" + aux.Tarea + "\t" + aux.Costo);
        System.out.println("---------------------------------------------");
        System.out.println("El costo total es: " + costoTotal2());
        System.out.println("---------------------------------------------");
    }
    
}

public class AsignacionTareas {
    public static void main(String[] args){
        String trabajadores[] = {"Jaime","Felipe","Cesar","Bernardo","Alan"};
        String tareas[] = {"Carpinteria","Plomeria","Electricidad","Jardineria","Albanileria"};
        int costos[][] = new int[5][5];
        costos[0][0] = 1100;
        costos[0][1] = 800;
        costos[0][2] = 830;
        costos[0][3] = 400;
        costos[0][4] = 3500;
        costos[1][0] = 1900;
        costos[1][1] = 350;
        costos[1][2] = 450;
        costos[1][3] = 400;
        costos[1][4] = 3000;
        costos[2][0] = 1000;
        costos[2][1] = 500;
        costos[2][2] = 510;
        costos[2][3] = 550;
        costos[2][4] = 1900;
        costos[3][0] = 1700;
        costos[3][1] = 320;
        costos[3][2] = 700;
        costos[3][3] = 500;
        costos[3][4] = 4900;
        costos[4][0] = 2000;
        costos[4][1] = 300;
        costos[4][2] = 600;
        costos[4][3] = 280;
        costos[4][4] = 2000;
        
        Tabla T1 = new Tabla(5);
        T1.Nombres = trabajadores;
        T1.Tareas = tareas;
        T1.Costos = costos;
        T1.Opcion1();
        T1.Opcion2();
        T1.impTabla();
        T1.impAsignaciones();
        T1.impAsignaciones2();
        
        
        String trabajadores2[] = {"Jaime","Felipe","Cesar"};
        String tareas2[] = {"Carpinteria","Plomeria","Electricidad"};
        int costos2[][] = new int[3][3];
        costos2[0][0] = 1100;
        costos2[0][1] = 800;
        costos2[0][2] = 830;
        costos2[1][0] = 1000;
        costos2[1][1] = 350;
        costos2[1][2] = 450;
        costos2[2][0] = 4000;
        costos2[2][1] = 500;
        costos2[2][2] = 510;
        
        Tabla T2 = new Tabla(3);
        T2.Nombres = trabajadores2;
        T2.Tareas = tareas2;
        T2.Costos = costos2;
        T2.Opcion1();
        T2.Opcion2();
        T2.impTabla();
        T2.impAsignaciones();
        T2.impAsignaciones2();
    }
}
