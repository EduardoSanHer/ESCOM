
package tc_4cm2.practica2_mctv_she;

import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;

public class Automata {
    public int NumChars, indice;
    public String Token;
    public ArrayList<String> ArrayToken = new ArrayList<String>();//No se uso al final
    public ArrayList<String> octal = new ArrayList<String>();
    public ArrayList<String> decimal = new ArrayList<String>();
    public ArrayList<String> hexadecimal = new ArrayList<String>();
    public ArrayList<String> alfabeto = new ArrayList<String>();
    
    Automata(String Token){
        this.Token = Token;
        NumChars = Token.length();
        int i;
        for(i = 0 ; i < 10 ; i++)
            decimal.add(String.valueOf(i));
        for(i = 0 ; i < 8 ; i++)
            octal.add(String.valueOf(i));
        for(i = 'A' ; i <= 'F' ; i++)
            hexadecimal.add(Character.toString(i));
        for(i = 'a' ; i <= 'f' ; i++)
            hexadecimal.add(Character.toString(i));
        for(i = 'A' ; i <= 'Z' ; i++)
            alfabeto.add(Character.toString(i));
        for(i = 'a' ; i <= 'z' ; i++)
            alfabeto.add(Character.toString(i));
        indice = 0;
    }
    
    public void giveToken(String Token){
        this.Token = Token;
        NumChars = Token.length();
        indice = 0;
    }
    
    //No se uso al final
    public ArrayList stringToArrayList(String w){
        ArrayList<String> aux = new ArrayList<String>();
        for(int i=0 ; i<w.length() ; i++){
            StringBuilder s = new StringBuilder();
            s.append(w.charAt(i));
            aux.add(s.toString());
        }
        //System.out.println(aux);
        return aux;
    }
    
    boolean q0(){
        //ArrayToken = stringToArrayList(Token);
        //System.out.println(ArrayToken.toString());
        //System.out.println(Token.charAt(0));
        //System.out.println(NumChars);
        //char Aux = Token.charAt(indice);
        String Aux = Token.substring(indice,indice+1);
        
        if(Aux.equals("+") || Aux.equals("-"))
            return q1();
        else if(Aux.equals("0"))
            return q2();
        else if(decimal.contains(Aux))
            return q3();
        else
            return false;
    }
    
    boolean q1(){
        indice++;
        if(indice<NumChars){
            //char Aux = Token.charAt(indice);
            String Aux = Token.substring(indice,indice+1);
            if(Aux.equals("0"))
                return q2();
            else if(decimal.contains(Aux))
                return q3();
            else
                return false;
        }
        else
            return false;
    }
    
    boolean q2(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(Aux.equals("."))
                return q4();
            else if(!Aux.equals("0") && octal.contains(Aux))
                return q9();
            else if(Aux.equals("x") || Aux.equals("X"))
                return q10();
            else
                return false;
        }
        else
            return false;
    }
    
    //Estado de aceptacion C0
    boolean q3(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(decimal.contains(Aux))
                return q3();
            else if(Aux.equals("."))
                return q4();
            else if(Aux.equals("e") || Aux.equals("E"))
                return q6();
            else if(Aux.equals(";") || Aux.equals(","))//, o ;
                return indice==NumChars-1;
            else
                return false;
        }
        else
            return true;
    }
    
    boolean q4(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(decimal.contains(Aux))
                return q5();
            else
                return false;
        }
        else
            return false;
    }
    
    //Estado de aceptacion C3
    boolean q5(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(decimal.contains(Aux))
                return q5();
            else if(Aux.equals("E") || Aux.equals("e"))
                return q6();
            else if(Aux.equals(";") || Aux.equals(","))//, o ;
                return indice==NumChars-1;
            else
                return false;
        }
        else
            return true;
    }
    
    boolean q6(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(Aux.equals("+") || Aux.equals("-"))
                return q7();
            else
                return false;
        }
        else
            return false;
    }
    
    boolean q7(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(decimal.contains(Aux))
                return q8();
            else
                return false;
        }
        else
            return false;
    }
    
    //Estado de aceptacion C4
    boolean q8(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(decimal.contains(Aux))
                return q8();
            else if(Aux.equals(";") || Aux.equals(","))//, o ;
                return indice==NumChars-1;
            else
                return false;
        }
        else
            return true;
    }
    
    //Estado de aceptacion C2
    boolean q9(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(octal.contains(Aux))
                return q9();
            else if(Aux.equals(";") || Aux.equals(","))//, o ;
                return indice==NumChars-1;
            else
                return false;
        }
        else
            return true;
    }
    
    boolean q10(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(hexadecimal.contains(Aux))
                return q11();
            else
                return false;
        }
        else
            return false;
    }
    
    //Estado de aceptacion C1
    boolean q11(){
        indice++;
        if(indice<NumChars){
            String Aux = Token.substring(indice,indice+1);
            if(hexadecimal.contains(Aux))
                return q11();
            else if(Aux.equals(";") || Aux.equals(","))//, o ;
                return indice==NumChars-1;
            else
                return false;
        }
        else
            return true;
    }
    
    public static void main(String[] args) throws java.io.IOException{
        /*
        Automata XD = new Automata("0xAB");
        boolean aux = XD.q0();
        if(aux)
            System.out.println("Cadena valida");
        else
            System.out.println("Cadena invalida");
        */
        String s1, s2;
        int NumLinea = 0;
        ArrayList<String> numeros = new ArrayList<String>();
        for(int k = 0; k<10 ; k++)
            numeros.add(String.valueOf(k));
        
        BufferedReader br = new BufferedReader (new FileReader("F:/Users/Lalo/Documents/IPN/Semestre_4/TC/Practica2/Practica2_MCTV_SHE/src/main/java/tc_4cm2/practica2_mctv_she/EjemploPracticaAnalizador.java"));
        s1 = br.readLine();
        Automata Auto = new Automata("");
        do{
            NumLinea++;
            
            StringTokenizer st = new StringTokenizer (s1);
            while(st.hasMoreTokens()){
                s2 = st.nextToken();
                //Automata Auto = new Automata(s2);
                Auto.giveToken(s2);
                //Automata de numeros
                if(s2.charAt(0)=='-' || numeros.contains(s2.substring(0,1))){
                    //Automata numero = new Automata(s2);
                    boolean estado = Auto.q0();
                    if(!estado){
                        System.out.println("Error en linea: " + NumLinea);
                        break;
                    }
                }
            }
            s1 = br.readLine();
            
        }while(s1!=null);
        /*
        s1 = br.readLine();
        s1 = br.readLine();
        //s1 = br.readLine();
        
        if(s1!=null)
        System.out.println("La primera linea del archivo es: " + s1);
        System.out.println("La linea tiene " + s1.length()+ " caracteres\n");
        
        System.out.println("Separando la linea en trozos tenemos las siguientes palabras: ");
        int numTokens = 0;
        StringTokenizer st = new StringTokenizer (s1);
        
        while(st.hasMoreTokens()){
            s2 = st.nextToken();
            numTokens++;
            System.out.println("\tPalabra " + numTokens + " es: " + s2);
        }*/
    }
}
