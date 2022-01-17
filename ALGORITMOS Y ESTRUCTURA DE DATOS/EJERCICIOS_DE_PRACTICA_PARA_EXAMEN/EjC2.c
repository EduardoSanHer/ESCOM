#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Cola2.h"

Cola Reemplazar(Cola,int,int);

int main(){
    int v,n;
    Cola q = formar(formar(formar(formar(formar(formar(nueva(),1),2),3),3),2),1);
    ImpCola(q);
    printf("\nIngresa el primer numero viejo: ");
    v=LeeElem();
    printf("\nIngresa el primer numero nuevo: ");
    n=LeeElem();
    q = Reemplazar(q,v,n);
    if(!esnueva(q))
        ImpCola(q);
    else
        printf("PTMDRE\n");

    return 0;
}

Cola Reemplazar(Cola q, int v, int n){
    if(!esnueva(q))
        if(EsIgual(primero(q),v))
            return formar(Reemplazar(desformar(q),v,n),n);
        else
            return formar(Reemplazar(desformar(q),v,n),primero(q));
    else
        return nueva();
}