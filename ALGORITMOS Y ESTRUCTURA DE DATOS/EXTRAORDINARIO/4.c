#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

Lista Diferencia(Lista,Lista);

int main(){

    Lista l1 = cons(2,cons(4,cons(6,cons(8,vacia()))));
    ImpElems(l1);
    puts("\n-----------");
    Lista l2 = cons(1,cons(2,cons(6,cons(9,cons(10,vacia())))));
    ImpElems(l2);
    puts("\n-----------");
    ImpElems(Diferencia(l1,l2));
    puts("\n-----------");

    return 0;
}

Lista Diferencia(Lista l1, Lista l2){
    while(!esvacia(l1)){
        while(EstaEn(cabeza(l1),l2))
            l2=ElimElem(cabeza(l1),l2);
        l1=resto(l1);
    }
    return l2;
}