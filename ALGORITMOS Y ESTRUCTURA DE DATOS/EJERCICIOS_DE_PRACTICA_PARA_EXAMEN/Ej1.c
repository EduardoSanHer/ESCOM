#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

Lista BorraElems(Lista,int);

int main(){

    Lista L=vacia();

    L=cons(1,cons(2,cons(3,cons(3,cons(2,cons(0,L))))));
    printf("Ingrese el elemento a borrar:\t");
    L=BorraElems(L,LeeElem());
    ImpElems(L);

    return 0;
}

Lista BorraElems(Lista l, int n){
    while(EstaEn(n,l))
        l=ElimElem(n,l);
    return l;
}

