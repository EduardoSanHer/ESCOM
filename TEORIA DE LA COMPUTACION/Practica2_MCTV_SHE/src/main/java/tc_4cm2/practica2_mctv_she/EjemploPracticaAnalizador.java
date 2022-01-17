
package tc_4cm2.practica2_mctv_she;





public class EjemploPracticaAnalizador {
    public static void main(String[] args) {
        int octall = -0123, octal2 = 0381;
        short dato = 12A12;
        double PI = 3.1416, CteGrav = -6.674E-19;
        float prom = (float) 0.0;
        double val;
        /* Calculos generales */
        for ( int i = 1; i < 100 ; i ++ ){
            prom += i;
        }
        double pot = 7.34E+1.4;
        val = CteGrav * dato * pot;
        System.out.println ( "Prom = " + ( prom / PI ) + "Result = " + (val * 0xAxB));
    }
}
