#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Lista.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Cola.h"

int main(){
    int i=1;
    Cola q=nueva();
    srand(time(NULL));//seed random
    q=formar(formar(formar(formar(formar(formar(q,1),2),3),4),5),6);
    //ImpElem(primero(desformar(q)));

    while(1){
        for(i=1;i<=(rand()%6)+1;i++){
            //ImpElem(primero(q)); Para el carrusel
            q=formar(desformar(q),primero(q));
        }
        ImpElem(primero(q));//Para el dado
        puts("\n--------");
        q=formar(desformar(q),primero(q));
        getchar();
    }
    return 0;
}
