#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ColaCir.h"

int NumElemsCola(Circular);

int main(){

    Circular q = nuevaC();
    for(int i=6;i<=40;i++)
        q=formarC(q,i);
    ImpColaC(q);
    puts("XDDD");
    ImpElem(NumElemsCola(q));
    while(NumElemsCola(q)>5){
        for(int k=1;k<=6;k++)
            q=rotacionC(q);
        q=desformarC(q);
    }
    ImpColaC(q);

    return 0;
}

int NumElemsCola(Circular q){
    if(esvaciaC(q))
        return 0;
    else
        return 1+NumElemsCola(desformarC(q));
}
