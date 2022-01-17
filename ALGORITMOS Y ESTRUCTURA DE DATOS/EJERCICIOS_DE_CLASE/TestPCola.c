#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ColaPrior.h"

int main(){
    Cola a=nueva();

    a=formarP(a,1,1);
    printf("\nCola\n");
    ImpCola(a);

    a=formarP(a,2,3);
    printf("\nCola\n");
    ImpCola(a);

    a=formarP(a,3,2);
    printf("\nCola\n");
    ImpCola(a);
    a=formarP(a,5,4);
    printf("\nCola\n");
    ImpCola(a);

    a=formarP(a,6,5);
    printf("\nCola\n");
    ImpCola(a);

    a=formarP(a,9,5);
    printf("\nCola\n");
    ImpCola(a);

    a=formarP(a,0,9);
    printf("\nCola\n");
    ImpCola(a);

    a=formarP(a,10,0);
    printf("\nCola\n");
    ImpCola(a);

    a=desformar(a);
    printf("\nCola\n");
    ImpCola(a);
    printf("Prioridad del ultimo:%d\n",a->ult->prio);

    a=formarP(a,20,0);
    printf("\nCola\n");
    ImpCola(a);
    printf("Prioridad del ultimo:%d\n",a->ult->prio);

    a=formarP(a,90,0);
    printf("\nCola\n");
    ImpCola(a);
    printf("Prioridad del ultimo:%d\n",a->ult->prio);


    return 0;
}
