#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Cola2.h"

int SumaElemsCola(Cola);

int main(){

    //Cola q = formar(formar(formar(formar(formar(formar(nueva(),1),2),3),3),2),1);
    Cola q = nueva();
    for(int i=1 ; i<=100 ; i++)
        q = formar(q,i);
    printf("La suma de los elem de q es: %d\n",SumaElemsCola(q));

    return 0;
}

int SumaElemsCola(Cola q){
    if(esnueva(q))
        return 0;
    else
        return primero(q)+SumaElemsCola(desformar(q));
}
