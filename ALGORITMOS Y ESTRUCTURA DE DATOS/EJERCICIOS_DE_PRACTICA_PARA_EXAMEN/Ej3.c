#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"


int main(){

    Lista l=vacia();
    Lista k=vacia();
    Lista p=vacia();
    l=cons(2,cons(2,cons(5,cons(3,cons(9,cons(6,l))))));
    k=cons(24,cons(99,cons(53,cons(65,cons(44,k)))));
    ImpElems(l);
    puts("\n-------------");
    ImpElems(k);
    puts("\n-------------");
    p=OrdListaAsc(PegaListas(l,k));
    ImpElems(p);
    puts("\n-------------");

    return 0;
}
