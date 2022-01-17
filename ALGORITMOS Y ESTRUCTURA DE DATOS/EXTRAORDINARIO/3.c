#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

Lista Particion(Lista,Elem);

int main(){

    Lista a=cons(1,cons(2,cons(2,cons(6,cons(5,cons(3,vacia()))))));
    //a=OrdListaAsc(a);
    puts("Ingresa el dato n");
    a=Particion(a,LeeElem());
    ImpElems(a);
    puts("\n-----------");

    return 0;
}

Lista Particion(Lista l1,Elem n){
    Lista l2=vacia();
    l1=OrdListaAsc(l1);
    while(!esvacia(l1) && cabeza(l1)<n){
        l2=InsOrd(cabeza(l1),l2);
        l1=resto(l1);
    }
    return l2;
}
