#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

Lista Reemplazar(Lista,int,int);

int main(){

    Lista L=vacia();
    Elem n,v;
    L=cons(1,cons(2,cons(3,cons(3,cons(2,cons(1,L))))));
    printf("Ingrese el nuevo elemento:\t");
    n=LeeElem();
    printf("Ingrese el viejo elemento:\t");
    v=LeeElem();
    L=Reemplazar(L,n,v);
    ImpElems(L);

    return 0;
}

Lista Reemplazar(Lista l, int n, int v){
    Lista p=vacia();
    while(!esvacia(l)){
        if(EsIgual(cabeza(l),v))
            p=cons(n,p);
        else
            p=cons(cabeza(l),p);
        l=resto(l);
    }
    return p;
}
