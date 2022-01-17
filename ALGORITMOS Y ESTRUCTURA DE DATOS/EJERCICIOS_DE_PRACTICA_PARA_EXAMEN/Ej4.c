#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

int SumaElems(Lista);

int main(){

    Lista l=vacia();
    l=cons(232,cons(33,cons(99,cons(55,cons(44,cons(3,cons(0,l)))))));
    ImpElems(l);
    puts("\n------------");
    printf("La suma de sus elementos es: %d\n",SumaElems(l));


    return 0;
}

/*
int SumaElems(Lista l){
    int s=0;
    s+=cabeza(l);
    if(!esvacia(resto(l)))
        s+=SumaElems(resto(l));
    return s;
}
*/

int SumaElems(Lista l){
    if(!esvacia(l))
        return cabeza(l)+SumaElems(resto(l));
    else
        return 0;
}
