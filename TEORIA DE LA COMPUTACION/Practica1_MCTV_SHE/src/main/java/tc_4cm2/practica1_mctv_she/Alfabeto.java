
package tc_4cm2.practica1_mctv_she;

import java.util.*;

import java.util.Scanner;

public class Alfabeto {
    public ArrayList<String> simbolos = new ArrayList<String>();
    public ArrayList<String> l1 = new ArrayList<String>();
    public ArrayList<String> l2 = new ArrayList<String>();
    public ArrayList<String> lU = new ArrayList<String>();
    public ArrayList<String> lC = new ArrayList<String>();
    public String w1 = new String();
    public String w2 = new String();
    public int tamano;
    public int tamanoelemento;
    
    public Alfabeto(){
        tamano = 0;
        tamanoelemento = 0;
    }
    
    //Introduce los elementos del alfabeto uno por uno
    public void Add(){
        boolean i = true;
        Scanner in;
        String simbolo = "0";
        int aux;
        System.out.println("Ingrese los simbolos del alfabeto uno por uno");
                System.out.println("Agrega el primer simbolo: ");
        while(i){
            //System.out.println("---------------------------------------------");
            in = new Scanner(System.in);
            simbolo = in.nextLine();
            if(simbolos.contains(simbolo))
                System.out.println("*El alfabeto ya cuenta con ese simbolo*");
            else{
                simbolos.add(simbolo);
                tamano++;
            }
            //System.out.println("---------------------------------------------");
            System.out.println("¿Quieres ingresar otro simbolo? 1(Yes)/2(No): ");
            aux = in.nextInt();
            if((aux!=1) && (tamano > 2) ){
                i = false;
            }
            else if(aux!=1 && tamano<3){
                System.out.println("**Tienes que ingresar al menos 3 simbolos**");
                System.out.println("Agrega el siguiente simbolo: ");
            }
            else{
                System.out.println("Agrega el siguiente simbolo: ");
            }
        }
        tamanoelemento = simbolo.length();
        //stem.out.println("El tamano del elemento es: " + tamanoelemento);
        System.out.println("*Se han ingresado todos los caracteres*");
    }
    
    //Funciona igual que Add(char A, char B) pero solo con enteros
    public void Add(int A, int B){
        if(A<B){
            for(int i=A ; i<=B ; i++)
                simbolos.add(String.valueOf(i));
            System.out.println("*Se han ingresado todos los caracteres*");
        }
        else{
            System.out.println("*El rango no es valido*\nIngrese el valor de A:");
            Scanner in = new Scanner(System.in);
            A = in.nextInt();
            System.out.println("Ingrese el valor de B:");
            B = in.nextInt();
            Add(A,B);
        }
        tamanoelemento = 1;
    }
    
    //Introduce los elementos al alfabeto mediante un rango segun el codigo ASCII
    public void Add(char A, char B){
        int asciiA = A, asciiB = B;
        if(asciiA<asciiB){
            for(int i=asciiA ; i<=asciiB ; i++)
                simbolos.add(Character.toString(i));
            System.out.println("*Se han ingresado todos los caracteres*");
        }
        else{
            System.out.println("*El rango no es valido*\nIngrese el valor de A:");
            Scanner in = new Scanner(System.in);
            A = in.next().charAt(0);
            System.out.println("Ingrese el valor de B:");
            B = in.next().charAt(0);
            Add(A,B);
        }
        tamanoelemento = 1;
    }
    
    //Convierte una cadena del alfabeto a un ArrayList
    public ArrayList stringToArrayList(String w){
        ArrayList<String> aux = new ArrayList<String>();
        for(int i=0 ; i<w.length() ; i += tamanoelemento){
            StringBuilder s = new StringBuilder();
            if(tamanoelemento>1){
                for(int j=0 ; j<tamanoelemento ; j++){
                    //System.out.println(w.charAt(i+j));
                    s.append(w.charAt(i+j));
                }
            }
            else
                s.append(w.charAt(i));
            aux.add(s.toString());
        }
        //System.out.println(aux);
        return aux;
    }
    
    /*Comprueba las cadenas w1 y w2 y si son correctas las agrega, sino, pide que sean
        ingresadas de nuevo*/
    public void addCadenas(String w1, String w2){
        this.w1 = w1;
        this.w2 = w2;
        System.out.println("Cadena w1: " + w1);
        System.out.println("Cadena w2: " + w2);
        
        if(checkCadena(this.w1))
            System.out.println("*La cadena w1 es valida*");
        else
            System.out.println("*La cadena w1 es invalida*");
        
        if(checkCadena(this.w2))
            System.out.println("*La cadena w2 es valida*");
        else
            System.out.println("*La cadena w2 es invalida*");
        
        Scanner in;
        
        if(!checkCadena(this.w1)){
            System.out.println("Por favor ingrese una cadena w1 valida");
            in = new Scanner(System.in);
            w1 = in.nextLine();
        }
        
        if(!checkCadena(this.w2)){
            System.out.println("Por favor ingrese una cadena w2 valida");
            in = new Scanner(System.in);
            w2 = in.nextLine();
        }
        
        if(!checkCadena(this.w1))
            addCadenas(w1,w2);
    }
    
    public void addCadenas(){
        Scanner in;
        System.out.println("Por favor ingrese una cadena w1 valida");
        in = new Scanner(System.in);
        w1 = in.nextLine();
        
        System.out.println("Por favor ingrese una cadena w2 valida");
        in = new Scanner(System.in);
        w2 = in.nextLine();
        
        if(checkCadena(w1))
            System.out.println("*La cadena w1 es valida*");
        else
            while(!checkCadena(w1)){
            System.out.println("*La cadena w1 es invalida*");
            System.out.println("Por favor ingrese una cadena w1 valida");
            in = new Scanner(System.in);
            w1 = in.nextLine();
            }
        
        if(checkCadena(this.w2))
            System.out.println("*La cadena w2 es valida*");
        else
            while(!checkCadena(w2)){
            System.out.println("*La cadena w2 es invalida*");
            System.out.println("Por favor ingrese una cadena w2 valida");
            in = new Scanner(System.in);
            w2 = in.nextLine();
            }
        
        System.out.println("Cadena w1: " + w1);
        System.out.println("Cadena w2: " + w2);
    }
    
    //Comprueba si una cadena es correcta segun el alfabeto
    public boolean checkCadena(String w){
        if(w.length()%tamanoelemento!=0)
            return false;
        ArrayList<String> arrayW = new ArrayList<String>();
        arrayW = stringToArrayList(w);
        boolean bw = true;
        
        for(int i=0 ; i<arrayW.size() ; i++){
            bw = simbolos.contains(arrayW.get(i));
            if(!bw)
                break;
        }
        return bw;
            
    }
    
    //Imprime todos los elementos del alfabeto
    public void impAlfabeto(){
        System.out.println("*Los elementos en el alfabeto son:*");
        for (String aux : simbolos) {
            System.out.println(": " + aux);
        }
    }
    
    //*********************************************************************
    /*Estos metodos comprueban si w1 es prefijo, sufijo o subcadena de w2.
        No funcionan del todo bien*/
    public boolean prefijo(String w1, String w2){
        boolean r = true;
        if(w1.length()==0)
            return r;
        for(int i = 0; i<w2.length()-1 && r==true; i++)
            if(w1.charAt(i)!=w2.charAt(i))
                r = false;
        return r;
    }
    
    public boolean sufijo(String w1, String w2){
        boolean r = true;
        if(w1.length()==0)
            return r;
        int k = w2.length()-1;
        for(int i = w1.length()-1; i>=0 && r==true; i--, k--)
            if(w1.charAt(i)!=w2.charAt(k))
                r = false;
        return r;
    }
    
    public boolean subchain(String w1, String w2){
        return w2.contains(w1) || w1.length()==0;
    }
    //**********************************************************************
    
    //Este metodo comprueba si w1 es una subsecuencia de w2
    public boolean subSecuence(String w1, String w2){
        //Convierte w1 de string a arraylist
        ArrayList<String> aux1 = new ArrayList<String>();
        aux1 = stringToArrayList(w1);
        //System.out.println(aux1);
        
        //Convierte w2 de string a arraylist
        ArrayList<String> aux2 = new ArrayList<String>();
        aux2 = stringToArrayList(w2);
        //System.out.println(aux2);
        
        ArrayList<String> aux3 = (ArrayList<String>) aux1.clone();
        ArrayList<String> aux4 = (ArrayList<String>) aux2.clone();
        for(String x: aux1){
            String a = x;
            for(String y: aux2){
                String b = y;
                //System.out.println("Aux3" + aux3);
                aux4.remove(0);
                aux2 = (ArrayList<String>) aux4.clone();
                if(a.equals(b)){
                    aux3.remove(0);
                    break;
                }
            }
        }
        //System.out.println(aux3);
        return aux3.isEmpty();
    }
    
    //Este metodo realiza lo que pide la practica en el punto 3
    public void queEs(){
        //Comprueba si w1 es prefijo de w2
        if(w2.startsWith(w1)){
            if(w2.equals(w1))
                System.out.println("**W1 es prefijo no propio de W2**");
            else
                System.out.println("**W1 es prefijo propio de W2**");
        }
        //Comprueba si w1 es sufijo de w2
        if(w2.endsWith(w1)){
            if(w2.equals(w1))
                System.out.println("**W1 es sufijo no propio de W2**");
            else
                System.out.println("**W1 es sufijo propio de W2**");
        }
        //Comprueba si w1 es subcadena de w2
        if(w2.contains(w1)){
            if(w2.equals(w1))
                System.out.println("**W1 es subcadena no propia de W2**");
            else
                System.out.println("**W1 es subcadena propia de W2**");
        }
        //Comprueba si w1 es subsecuencia de w2
        if(subSecuence(w1,w2)){
            if(w2.equals(w1))
                System.out.println("**W1 es subsecuencia no propia de W2**");
            else
                System.out.println("**W1 es subsecuencia propia de W2**");
        }
    }
    
    //Este metodo genera dos lenguajes a partir de el alfabeto, numero de elementos y 
    // longitud de estos
    public void lenguajes(){
        Scanner in;
        System.out.println("Por favor ingrese el numero de elementos: ");
        in = new Scanner(System.in);
        int numElem = in.nextInt();
        
        System.out.println("Por favor ingrese la longitud de los elementos: ");
        in = new Scanner(System.in);
        int longitud = in.nextInt();
        
        Random aleatorio = new Random();
        
        for(int i=0 ; i<numElem ; i++){
            StringBuilder s = new StringBuilder();
            for(int j=0 ; j<longitud ; j++){
                s.append(simbolos.get(aleatorio.nextInt(simbolos.size())));
            }
            l1.add(s.toString());
        }
        
        for(int i=0 ; i<numElem ; i++){
            StringBuilder s = new StringBuilder();
            for(int j=0 ; j<longitud ; j++){
                s.append(simbolos.get(aleatorio.nextInt(simbolos.size())));
            }
            l2.add(s.toString());
        }
        System.out.println("L1: " + l1);
        System.out.println("L2: " + l2);
    }
    
    //Este metodo une los lenguajes L1 y L2
    public void union(){
        for(String y: l1)
            lU.add(y);
        for(String x: l2)
            if(!lU.contains(x))
                lU.add(x);
        System.out.println("LU: " + lU);
    }
    
    //Este metodo concatena los lenguajes L1 y L2
    public void concatenacion(){
        for(String x: l1)
            for(String y: l2)
                lC.add(x+y);
        System.out.println("LC: " + lC);
    }
    
    //Este metodo comprueba el inciso a del punto 7
    public void vocales (){
        Scanner in;
        System.out.println("Por favor ingrese una palabra para ser validada: ");
        in = new Scanner(System.in);
        String w = in.nextLine();
        boolean r = true;
        char aux = 'a';
        for(int i=0 ; i<w.length() ; i++){
            switch(w.charAt(i)){
                case 'a':
                    if(aux== 'u' || aux=='a')
                        aux = 'a';
                    else
                        r = false;
                    break;
                case 'e':
                    if((aux=='a' || aux=='e'))
                        aux = 'e';
                    else
                        r = false;
                    break;
                case 'i':
                    if(aux=='e' || aux=='i')
                        aux = 'i';
                    else
                        r = false;
                    break;
                case 'o':
                    if(aux=='i' || aux=='o')
                        aux = 'o';
                    else
                        r = false;
                    break;
                case 'u':
                    if(aux=='o' || aux=='u')
                        aux = 'u';
                    else
                        r = false;
                    break;
                    
            }
        }
        if(!w.contains("a") || !w.contains("e") || !w.contains("i") || !w.contains("o") 
                || !w.contains("u") )
            r = false;
        if(r)
            System.out.println("**Palabra correcta**");
        else
            System.out.println("**Palabra incorrecta**");
        
    }
}
