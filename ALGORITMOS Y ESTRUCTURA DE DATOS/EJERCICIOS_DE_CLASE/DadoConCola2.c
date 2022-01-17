#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Cola2.h"

Elem dado(Cola);

int main(){

    Cola q=nueva();

    srand(time(NULL)); //seed random
    q=formar(formar(formar(formar(formar(formar(q,1),2),3),4),5),6);
    while(1){
       printf("Tirada: %d.\n",dado(q));
       getchar();
    }
    return 0;
}

Elem dado(Cola q){
     int i;
     for(i=1;i<=(rand()%6)+1;i++) // repetir el ciclo un numero aleatorio de veces
            q=formar(desformar(q),primero(q)); // Rotacion
     return primero(q);
};