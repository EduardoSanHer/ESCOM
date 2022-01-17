
package tc_4cm2.practica2_mctv_she;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;

public class TestLectorArchivo {
    public static void main(String[] args) throws java.io.IOException {
        String s1, s2;
        
        BufferedReader br = new BufferedReader (new FileReader("F:/Users/Lalo/Documents/IPN/Semestre_4/TC/Practica2/Practica2_MCTV_SHE/src/main/java/tc_4cm2/practica2_mctv_she/Archivo.txt"));
        
        s1 = br.readLine();
        s1 = br.readLine();
        s1 = br.readLine();
        
        System.out.println("La primera linea del archivo es: " + s1);
        System.out.println("La linea tiene " + s1.length()+ " caracteres\n");
        
        System.out.println("Separando la linea en trozos tenemos las siguientes palabras: ");
        int numTokens = 0;
        StringTokenizer st = new StringTokenizer (s1);
        
        while(st.hasMoreTokens()){
            s2 = st.nextToken();
            numTokens++;
            System.out.println("\tPalabra " + numTokens + " es: " + s2);
        }
    }
}
