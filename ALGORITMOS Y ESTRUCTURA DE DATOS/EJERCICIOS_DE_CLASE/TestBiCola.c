#include<stdio.h>
#include<stdlib.h>
/*
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\BiCola.h"
*/
#include"/mnt/f/Users/Lalo/Documents/IPN/Semestre 2/AED/LibAED/Elem.h"
#include"/mnt/f/Users/Lalo/Documents/IPN/Semestre 2/AED/LibAED/BiCola.h"

int main(){
    printf("\t***Prueba BiCola***\n");

    BiCola a=nuevaB();
    if(esnuevaB(a))
        printf("*La cola a es nueva*\n");

    a=formarI(2,a);
    printf("La cola tiene:\n");
    ImpBiCola(a);
    printf("\n");

    a=formarI(1,a);
    printf("La cola tiene:\n");
    ImpBiCola(a);
    printf("\n");

    a=formarD(a,3);
    printf("La cola tiene:\n");
    ImpBiCola(a);
    printf("\n");

    a=formarD(a,4);
    printf("La cola tiene:\n");
    ImpBiCola(a);
    printf("\n");

    printf("Primer elemento de izq a der :%d\n",izquierdo(a));
    printf("Primer elemento de der a izq :%d\n",derecho(a));
    a=desformarI(a);
    ImpBiCola(a);
    printf("\n");
    printf("Primer elemento de izq a der :%d\n",izquierdo(a));

    a=desformarD(a);
    ImpBiCola(a);
    printf("\n");
    printf("Primer elemento de der a izq :%d\n",derecho(a));

    return 0;
}
