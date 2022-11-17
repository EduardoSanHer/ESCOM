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

/*|----------------------------------------------------|*/
/*| Se definen las librerías y funciones de apoyo      |*/
/*|----------------------------------------------------|*/
%{
    import java.lang.Math;
    import java.io.*;
    import java.util.StringTokenizer;
    import java.awt.*;
    import java.awt.event.*;
    import javax.swing.*;
%}

/*|----------------------------------------------------|*/
/*|  Creación de símbolos terminales y no terminales   |*/
/*|----------------------------------------------------|*/
%token NUMBER LINE CIRCULO RECTANGULO COLOR PRINT   //Terminales para las figuras
%start list
    
/*|----------------------------------------------------|*/
/*|                    Gramática                       |*/
/*|----------------------------------------------------|*/
%%
/*
    list => *vacio*
    list => | list ';'
    list => | list inst ';'
*/
    list:    
        | list ';'
        | list inst ';'   { 
                maq.code("print"); 
                maq.code("STOP"); 
                return 1 ; 
            }   
        ;
    
/*
    inst => NUMBER
    inst => RECTANGULO NUMBER NUMBER NUMBER NUMBER  [X,Y,Ancho,Alto]
    inst => LINE NUMBER NUMBER NUMBER NUMBER        [X1,Y1,X2,Y2]
    inst => CIRCULO NUMBER NUMBER NUMBER            [Radio,X,Y]
    inst => COLOR NUMBER                            [0,1,2] <= RGB: (0,Rojo) (1,Verde) (2,Azul)
*/
    inst: NUMBER  { 
                ((Algo)$$.obj).inst = maq.code("constpush");
                maq.code(((Algo)$1.obj).simb); 
            }
        | RECTANGULO NUMBER NUMBER NUMBER NUMBER { 
                //X
                maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); 
                //Y
                maq.code("constpush");
                maq.code(((Algo)$3.obj).simb); 
                //Ancho
                maq.code("constpush");
                maq.code(((Algo)$4.obj).simb); 
                //Alto
                maq.code("constpush");
                maq.code(((Algo)$5.obj).simb); 
                maq.code("rectangulo");
            }
        | LINE NUMBER NUMBER NUMBER NUMBER { 
                //X1
                maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); 
                //Y1
                maq.code("constpush");
                maq.code(((Algo)$3.obj).simb); 
                //X2
                maq.code("constpush");
                maq.code(((Algo)$4.obj).simb); 
                //Y2
                maq.code("constpush");
                maq.code(((Algo)$5.obj).simb); 
                maq.code("line");
            }
        | CIRCULO NUMBER NUMBER NUMBER { 
                //Radio
                maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); 
                //X
                maq.code("constpush");
                maq.code(((Algo)$3.obj).simb); 
                //Y
                maq.code("constpush");
                maq.code(((Algo)$4.obj).simb); 
                maq.code("circulo");
            }
        | COLOR NUMBER {
                //NUMBER
                maq.code("constpush");
                maq.code(((Algo)$2.obj).simb); 
                maq.code("color");
            }
        ;
%%

/*|----------------------------------------------------|*/
/*|                    Código en Java                  |*/
/*|----------------------------------------------------|*/
class Algo {
    Simbolo simb;
    int inst;
                    
    public Algo(int i){ 
        inst=i; 
    }
                    
    public Algo(Simbolo s, int i){
        simb=s; inst=i;
    }
                    
}
                
public void setTokenizer(StringTokenizer st){
    this.st= st;
}
                
public void setNewline(boolean newline){
    this.newline= newline;
}
                
Tabla tabla;
Maquina maq;
                
StringTokenizer st;
boolean newline;
int yylex(){
    String s;
    int tok;
    Double d;
    Simbolo simbo;
    if (!st.hasMoreTokens())
        if (!newline) {
            newline=true; 
            return ';';  
        }
        else
            return 0;
        s = st.nextToken();
        try {
            d = Double.valueOf(s);
            yylval = new ParserVal(
                new Algo(tabla.install("", NUMBER, d.doubleValue()),0) );
            tok = NUMBER;
        } catch (Exception e){
            if(Character.isLetter(s.charAt(0))){
                if((simbo=tabla.lookup(s))==null)
                    yylval = new ParserVal(new Algo(simbo, 0));
                    tok= simbo.tipo;	
                } else {
                    tok = s.charAt(0);
                }
        }
    return tok;
}
                
void yyerror(String s){
    System.out.println("parser error: "+s);
}
                
static Parser par = new Parser(0);
static JFrame jf;
static JLabel lmuestra=new JLabel("                                 ");
static Canvas canv;
static Graphics g;
                
Parser(int foo){
    maq=new Maquina();
    tabla=new Tabla();
    tabla.install("line", LINE, 0.0);
    tabla.install("circulo", CIRCULO, 0.0);
    tabla.install("rectangulo", RECTANGULO, 0.0);
    tabla.install("color", COLOR, 0.0);
    tabla.install("print", PRINT, 0.0);
    maq.setTabla(tabla);
    jf=new JFrame("Calcula");
    canv=new Canvas();
    canv.setSize(600,600);
    jf.add("North", new PanelEjecuta(maq, this));
    jf.add("Center", canv);
    jf.setSize( 600, 700);
    jf.setVisible(true);
    g=canv.getGraphics();
    maq.setGraphics(g);
    jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);  
}
                
public static void main(String args[]){
    new Parser(); 
}