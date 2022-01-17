
package tc_4cm2.practica3_mctv_she;

import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Automata_Pila {
    public int NumChars, indice;
    public String Token;
    public Pila Stack;
    public ArrayList<String> decimal = new ArrayList<String>();
    public ArrayList<String> letra = new ArrayList<String>();
    
    Automata_Pila(String Token){
        this.Token = Token;
        NumChars = Token.length();
        indice = 0;
        Stack = new Pila();
        for(int i = 'A' ; i <= 'Z' ; i++)
            letra.add(Character.toString(i));
        for(int i = 'a' ; i <= 'z' ; i++)
            letra.add(Character.toString(i));
        letra.add("_");
        //letra.add("$");
        for(int i = 0 ; i <= 9 ; i++)
            decimal.add(String.valueOf(i));
    }
    
    public void darToken(String Token){
        this.Token = Token.replaceAll("\\s+","");
        this.Token = this.Token.replaceAll("_","C");
        //this.Token = this.Token.replaceAll("$","C");
        for(int i = 'A' ; i <= 'Z' ; i++)
            this.Token = this.Token.replaceAll(Character.toString(i),"C");
        for(int i = 'a' ; i <= 'z' ; i++)
            this.Token = this.Token.replaceAll(Character.toString(i),"C");
        for(int i = 0 ; i <= 9 ; i++)
            this.Token = this.Token.replaceAll(String.valueOf(i),"0");
        NumChars = this.Token.length();
        System.out.println("El token es: " + Token);
        indice = 0;
    }
    
    //Guarda las derivaciones en un arreglo para al final obtener la derivacion correcta
    ArrayList agregarDerivacion(ArrayList prev, Pila aux){
        ArrayList<Pila> actual = new ArrayList<Pila>();
        actual.addAll(prev);
        actual.add(aux);
        return actual;
    }
    
    boolean q0(){
        Pila PilaAux = new Pila();
        PilaAux.apilar(";");
        PilaAux.apilar("E");
        PilaAux.apilar("=");
        PilaAux.apilar("ID");
        ArrayList<Pila> derivacion = new ArrayList<Pila>();
        derivacion.add(PilaAux);
        return q1(PilaAux,indice,derivacion);
    }
    
    boolean q1(Pila Stack, int indiceNew, ArrayList derPrev){
        Pila PilaAux = new Pila();
        PilaAux = Stack.copiarPila();
        boolean res = false;
        int newIndice = indiceNew;
        Pila Temp;
        
        if(newIndice<NumChars && Stack.getTamano()<=NumChars-newIndice){
            String Aux = Token.substring(newIndice,newIndice+1);
            ArrayList<Pila> PilasAux = new ArrayList<Pila>();
            for(int i=0 ; i<15 ; i++){
                PilasAux.add(PilaAux.copiarPila());
                Temp = PilasAux.get(i).copiarPila();
                Temp.desapilar();
                PilasAux.set(i,Temp);
            }
            if(Aux.equals(";") && Stack.getTop().equals(";")){
                //;=>lambda
                PilaAux.desapilar();
                ArrayList<Pila> derivacion = new ArrayList<Pila>();
                derivacion.addAll(derPrev);
                for (int i = 0; i < derPrev.size(); i++) {
                    derivacion.get(i).imprimirPila();
                    System.out.println("________________________________________________");
                }
                return q3() || PilaAux.esVacia();
            }
            if(Stack.getTop().equals("E")){
                //E=>ID
                Temp = PilasAux.get(0).copiarPila();
                Temp.apilar("ID");
                PilasAux.set(0,Temp);
                //E=>(E)
                Temp = PilasAux.get(1).copiarPila();
                Temp.apilar(")");
                Temp.apilar("E");
                Temp.apilar("(");
                PilasAux.set(1,Temp);
                //E=>E+E
                Temp = PilasAux.get(2).copiarPila();
                Temp.apilar("E");
                Temp.apilar("+");
                Temp.apilar("E");
                PilasAux.set(2,Temp);
                //E=>E-E
                Temp = PilasAux.get(3).copiarPila();
                Temp.apilar("E");
                Temp.apilar("-");
                Temp.apilar("E");
                PilasAux.set(3,Temp);
                //E=>E*E
                Temp = PilasAux.get(4).copiarPila();
                Temp.apilar("E");
                Temp.apilar("*");
                Temp.apilar("E");
                PilasAux.set(4,Temp);
                //E=>E/E
                Temp = PilasAux.get(5).copiarPila();
                Temp.apilar("E");
                Temp.apilar("/");
                Temp.apilar("E");
                PilasAux.set(5,Temp);
                //E=>E%E
                Temp = PilasAux.get(6).copiarPila();
                Temp.apilar("E");
                Temp.apilar("%");
                Temp.apilar("E");
                PilasAux.set(6,Temp);
                //E=>N
                Temp = PilasAux.get(7).copiarPila();
                Temp.apilar("N");
                PilasAux.set(7,Temp);
                
                res = res || q1(PilasAux.get(0),newIndice,agregarDerivacion(derPrev,PilasAux.get(0)))
                        || q1(PilasAux.get(1),newIndice,agregarDerivacion(derPrev,PilasAux.get(1)))
                         || q1(PilasAux.get(2),newIndice,agregarDerivacion(derPrev,PilasAux.get(2)))
                        || q1(PilasAux.get(3),newIndice,agregarDerivacion(derPrev,PilasAux.get(3)))
                         || q1(PilasAux.get(4),newIndice,agregarDerivacion(derPrev,PilasAux.get(4)))
                        || q1(PilasAux.get(5),newIndice,agregarDerivacion(derPrev,PilasAux.get(5)))
                         || q1(PilasAux.get(6),newIndice,agregarDerivacion(derPrev,PilasAux.get(6)))
                        || q1(PilasAux.get(7),newIndice,agregarDerivacion(derPrev,PilasAux.get(7)));
            }
            if(Stack.getTop().equals("ID")){
                //ID=>C
                Temp = PilasAux.get(8).copiarPila();
                Temp.apilar("C");
                PilasAux.set(8,Temp);
                //ID=>IDC
                Temp = PilasAux.get(9).copiarPila();
                Temp.apilar("C");
                Temp.apilar("ID");
                PilasAux.set(9,Temp);
                //ID=>IDN
                Temp = PilasAux.get(10).copiarPila();
                Temp.apilar("N");
                Temp.apilar("ID");
                PilasAux.set(10,Temp);
                
                res = res || q1(PilasAux.get(8),newIndice,agregarDerivacion(derPrev,PilasAux.get(8)))
                        || q1(PilasAux.get(9),newIndice,agregarDerivacion(derPrev,PilasAux.get(9)))
                        || q1(PilasAux.get(10),newIndice,agregarDerivacion(derPrev,PilasAux.get(10)));
                
            }
            if(Stack.getTop().equals("N")){
                //N=>0
                Temp = PilasAux.get(11).copiarPila();
                Temp.apilar("0");
                PilasAux.set(11,Temp);
                //N=>N0
                Temp = PilasAux.get(12).copiarPila();
                Temp.apilar("0");
                Temp.apilar("N");
                PilasAux.set(12,Temp);
                
                res = res || q1(PilasAux.get(11),newIndice,agregarDerivacion(derPrev,PilasAux.get(11)))
                        || q1(PilasAux.get(12),newIndice,agregarDerivacion(derPrev,PilasAux.get(12)));
            }
            if(Stack.getTop().equals(Aux)){
                //Aux=>Aux
                newIndice++;
                Temp = Stack.copiarPila();
                Temp.desapilar();
                res = q1(Temp,newIndice,agregarDerivacion(derPrev,Temp));
            }
            return res;
        }
        else
            return false;
    }
    
    boolean q3(){
        return true;
    }
    
    public static void main(String[] args) throws java.io.IOException{
        String Token=JOptionPane.showInputDialog(null," INTRODUZCA LA CADENA ");
        Automata_Pila A = new Automata_Pila(Token);
        A.darToken(Token);
        if(A.q0()){
            System.out.println("La cadena es correcta");
            JOptionPane.showMessageDialog(null," LA CADENA PERTENECE A LA GRAMATICA ","GIC",JOptionPane.PLAIN_MESSAGE);
        }
        else{
            System.out.println("La cadena es incorrecta");
            JOptionPane.showMessageDialog(null," LA CADENA NO PERTENECE A LA GRAMATICA ", "GIC",JOptionPane.ERROR_MESSAGE);
        }
            
    }
}
