#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

Lista ElimOcurr(Lista,Elem);

int main(){

    Lista a=cons(1,cons(3,cons(2,cons(3,cons(2,cons(1,vacia()))))));
    ImpElems(a);
    puts("\n-----------");
    a=ElimOcurr(a,LeeElem());
    ImpElems(a);
    puts("\n-----------");

    return 0;
}

Lista ElimOcurr(Lista l,Elem e){
    while(EstaEn(e,l)){
        l=ElimElem(e,l);
    }
    return l;
}
