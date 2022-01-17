#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Pila.h"

Elem dado(Pila);

int main(){

    Pila q=empty();

    srand(time(NULL)); //seed random
    q=push(1,push(2,push(3,push(4,push(5,push(6,empty()))))));
    ImpElems(q);
    printf("\n---------\n");

    ImpElems(InviertePilas(q));
    printf("\n---------\n");

    ImpElems(PegaPilas(q,InviertePilas(q)));
    printf("\n---------\n");
    
    printf("\n-----DADO-----\n");
    while(1){
       printf("Tirada: %d.\n",dado(q));
       getchar();
    }
    return 0;
}

Elem dado(Pila q){
     int i;
     for(i=1;i<=(rand()%6)+1;i++) //Repetir el ciclo un numero aleatorio de veces
            q=RotarP(pop(q),top(q)); // Rotacion
     return top(q);
};
