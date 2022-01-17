#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Cola2.h"


int main(){

    Cola q = formar(formar(formar(nueva(),8),10),2);
    Cola p = formar(formar(formar(nueva(),6),3),9);
    Cola l = nueva();
    ImpCola(q);
    puts("\n------");
    ImpCola(p);
    puts("\n------");
    ImpCola(PegaColas(q,p));
    puts("\n------");
    l=OrdColaAsc(PegaColas(q,p));
    ImpCola(l);

    return 0;
}
