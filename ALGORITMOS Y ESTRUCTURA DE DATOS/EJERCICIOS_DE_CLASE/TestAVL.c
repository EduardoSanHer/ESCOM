#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\AVL.h"
//#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\Codigos del profe\Elem.h"
//#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\Codigos del profe\AVL.h"

int main(){

    AVL a = vacioB();
    Elem e;

    while(e=LeeElem()){
        printf("Dato a insertar: %d\n",e);
        puts("-----");
        a=InsAVL(e,a);
        ImpNivelPorNivelAB(a);
        puts("-----");
        printf("Altura izq = %d\t Altura der = %d\t FactBal = %d\n",AlturaAB(izquierdoB(a)), AlturaAB(derechoB(a)), FactBal(a));
        puts("-----");
        EsAVL(a)?printf("Es AVL.\n"):printf("No es AVL.\n");
    }
    while(e=LeeElem()){
        printf("Dato a borrar: %d\n",e);
        puts("-----");
        a=HazAVL(EliminaAVL(e,a));
        ImpNivelPorNivelAB(a);
        puts("-----");
        printf("Altura izq = %d\t Altura der = %d\t FactBal = %d\n",AlturaAB(izquierdoB(a)), AlturaAB(derechoB(a)), FactBal(a));
        puts("-----");
        EsAVL(a)?printf("Es AVL.\n"):printf("No es AVL.\n");
    }
    return 0;
}
