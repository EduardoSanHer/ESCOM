#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ArBin.h"

int main(){
    ArBin a,b,c;

    b=consB(50,vacioB(),vacioB());

    c=consB(200,vacioB(),vacioB());

    a=consB(100,b,c);

    ImpElem(raiz(a));
    ImpElem(raiz(izquierdoB(a)));
    ImpElem(raiz(derechoB(a)));

    printf("\n\t%d Elementos\n",NumElemsB(a));

    //a=(10,cons(20,cons(1,vacioB(),vacioB()),cons(4,vacioB(),vacioB())),cons(5,vacioB(),cons(6,vacioB(),vacioB())))

    return 0;
}