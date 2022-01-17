
package ada_sandovalhernandez.practica2;

import java.util.Arrays;

class Elemento{
    public int Elem;
    public String origen;

    //Constructor del Elemento
    public Elemento(int e, String o){
        Elem = e;
        origen = o;
    }
    
    //Determina si dos elementos son iguales
    public boolean equals(Elemento x){
        return (this.Elem==x.Elem);
    }
    
    //Determina cuál es el mayor de dos elementos
    public int max(Elemento x){
        if(Elem>x.Elem)
           return this.Elem;
        else
           return x.Elem;
    }
    
    //Imprime el elemento
    public String toString(){
        return Elem + " ";
    }
    
}

class Matriz{
    public int a;
    public int b;
    public Elemento E[][];
    public int R[];
    public char Rc[];
    
    //Constructor de Matriz para enteros
    public Matriz(int x[], int y[], int a, int b){
        this.a = a;
        this.b = b;
        Elemento E1[][] = new Elemento[a][b];
        E = E1;
        //****Esta parte del codigo es la que crea la Matriz con las longitudes acumuladas y los origenes****
        for(int i=0 ; i<a ; i++)
            for(int j=0 ; j<b ; j++){
                if(i==0 || j==0)
                    E[i][j] = new Elemento(0,"000");
                else if((i!=0 || j!=0) && (x[j-1]==y[i-1]))
                    E[i][j] = new Elemento(E[i-1][j-1].Elem+1,"Dia");
                else if((i!=0 || j!=0) && (x[j-1]!=y[i-1]) && (E[i][j-1]!=E[i-1][j])){
                    String o1;
                    if(E[i][j-1].Elem>E[i-1][j].Elem){
                        o1 = "Izq";
                    }
                    else{
                        o1 = "Sup";
                    }
                    E[i][j] = new Elemento(E[i][j-1].max(E[i-1][j]),o1);
                }
                else
                    E[i][j] = new Elemento(E[i-1][j].Elem,"Sup");
            }
        //*************************************************************************************************
        //****Esta parte crea el arreglo donde se guarda la subsecuencia mayor a partir de la ultima casilla****
        int i = a-1, j = b-1, aux = E[i][j].Elem-1, R1[] = new int[aux+1];
        R = R1;
        while(i>0){
            if(y[i-1]==x[j-1]){
                R[aux] = x[j-1];
                aux--;
                if(E[i][j].origen.equals("Sup"))
                    i--;
                else if(E[i][j].origen.equals("Dia")){
                    i--;
                    j--;
                }
                else
                    j--;
            }
            else{
                if(E[i][j].origen.equals("Sup"))
                    i--;
                else if(E[i][j].origen.equals("Dia")){
                    i--;
                    j--;
                }
                else
                    j--;
            }
        }
        //*************************************************************************************************
    }
    
    //Constructor de Matriz para caracteres
    public Matriz(char x[], char y[], int a, int b){
        this.a = a;
        this.b = b;
        Elemento E1[][] = new Elemento[a][b];
        E = E1;
        //****Esta parte del codigo es la que crea la Matriz con las longitudes acumuladas y lo origenes****
        for(int i=0 ; i<a ; i++)
            for(int j=0 ; j<b ; j++){
                if(i==0 || j==0)
                    E[i][j] = new Elemento(0,"000");
                else if((i!=0 || j!=0) && (Character.compare(x[j-1],y[i-1])==0))//(x[j-1]==y[i-1])
                    E[i][j] = new Elemento(E[i-1][j-1].Elem+1,"Dia");
                else if((i!=0 || j!=0) && (Character.compare(x[j-1],y[i-1])!=0) && (E[i][j-1]!=E[i-1][j])){
                    int a1, b1;
                    String o1;
                    if(E[i][j-1].Elem>E[i-1][j].Elem){
                        a1 = i;
                        b1 = j-1;
                        o1 = "Izq";
                    }
                    else{
                        a1 = i-1;
                        b1 = j;
                        o1 = "Sup";
                    }
                    E[i][j] = new Elemento(E[i][j-1].max(E[i-1][j]),o1);
                }
                else
                    E[i][j] = new Elemento(E[i-1][j].Elem,"Sup");
            }
        //*************************************************************************************************
        //****Esta parte crea el arreglo donde se guarda la subsecuencia mayor a partir de la ultima casilla****
        int i = a-1, j = b-1, aux = E[i][j].Elem-1;
        char R2[] = new char[aux+1];
        Rc = R2;
        while(i>0){
            if(Character.compare(x[j-1],y[i-1])==0){
                Rc[aux] = x[j-1];
                aux--;
                if(E[i][j].origen.equals("Sup"))
                    i--;
                else if(E[i][j].origen.equals("Dia")){
                    i--;
                    j--;
                }
                else
                    j--;
            }
            else{
                if(E[i][j].origen.equals("Sup"))
                    i--;
                else if(E[i][j].origen.equals("Dia")){
                    i--;
                    j--;
                }
                else
                    j--;
            }
        }
        //*************************************************************************************************
    }
    
    //Este metodo imprime la Matriz de longitudes
    public void impMatriz(){
        System.out.println("----------------------------------------");
        for(int x=0 ; x < E.length ; x++){
            for(int y=0 ; y < E[x].length ; y++)
                System.out.print(" |" + E[x][y]+ "| ");   
            System.out.println("\n");
        }
        System.out.println("----------------------------------------");
    }
    
    //Este metodo imprime la matriz de origenes
    public void impOrigenes(){
        System.out.println("----------------------------------------");
        for(int x=0 ; x < E.length ; x++){
            for(int y=0 ; y < E[x].length ; y++)
                System.out.print(" |" + E[x][y].origen+ "| ");   
            System.out.println("\n");
        }
        System.out.println("----------------------------------------");
    }
    
    //Este metodo imprime el arreglo donde se guarda la subseciencia maxima de numeros enteros
    public void impResultadoInt(){  
        System.out.println("----------------------------------------");
        System.out.println("El resultado es:" + Arrays.toString(R));
        System.out.println("----------------------------------------");
    }

    //Este metodo imprime el arreglo donde se guarda la subseciencia maxima de caracteres
    public void impResultadoChar(){  
        System.out.println("----------------------------------------");
        System.out.println("El resultado es:" + Arrays.toString(Rc));
        System.out.println("----------------------------------------");
    }
    
}

public class Subsecuencia {
    public static void main(String[] args){
        System.out.println("*****Prueba 1*****");
        int x1[] = {1,0,0,1};
        int y1[] = {0,1,0,1,0,0};
        Matriz M1 = new Matriz(x1,y1,7,5);
        System.out.println("Matriz de longitudes");
        M1.impMatriz();
        System.out.println("Matriz de origenes");
        M1.impOrigenes();
        M1.impResultadoInt();
        
        System.out.println("*****Prueba 2*****");
        char x2[] = {'a','b','c','d','e','f','g','h','i','j'};
        char y2[] = {'e','c','d','g','i'};
        Matriz M2 = new Matriz(x2,y2,6,11);
        System.out.println("Matriz de longitudes");
        M2.impMatriz();
        System.out.println("Matriz de origenes");
        M2.impOrigenes();
        M2.impResultadoChar();
        
        System.out.println("*****Prueba 3*****");
        int x[] = {1,1,0,1,0,1,1,0};
        int y[] = {0,1,0,1,1,0};
        Matriz M = new Matriz(x,y,7,9);
        System.out.println("Matriz de longitudes");
        M.impMatriz();
        System.out.println("Matriz de origenes");
        M.impOrigenes();
        M.impResultadoInt();
        
        System.out.println("*****Prueba extra*****");
        int x4[] = {1,1,0,1,0,1};
        int y4[] = {1,1,0,1,1,0};
        Matriz M4 = new Matriz(x4,y4,7,7);
        System.out.println("Matriz de longitudes");
        M4.impMatriz();
        System.out.println("Matriz de origenes");
        M4.impOrigenes();
        M4.impResultadoInt();
        
        /*
        System.out.println("*****Prueba 4*****");
        char x3[] = {'a','b','c','b','d','a','b'};
        char y3[] = {'b','d','c','a','b','a'};
        Matriz M3 = new Matriz(x3,y3,7,8);
        System.out.println("Matriz de longitudes");
        M3.impMatriz();
        System.out.println("Matriz de origenes");
        M3.impOrigenes();
        M3.impResultadoChar();
        */
        
    }
}