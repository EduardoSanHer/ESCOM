#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ColaCir.h"

typedef Circular Dado;

int tirada(Dado);
Dado DadoNuevo(int);

int main(){
    srand(time(NULL));
    Circular a=nuevaC();
    Dado d=DadoNuevo(6);

    /*
    while(1){
        printf("Tirada: %d\n",tirada(d));
        getchar();
    }
    */

    a=formarC(formarC(formarC(a,1),2),3);

    ImpElem(primeroC(a));

    a=rotacionC(a);

    ImpElem(primeroC(a));

    a=desformarC(a);

    ImpElem(primeroC(a));

    return 0;
}

Dado DadoNuevo(int n){
    int i;
    Dado d=nuevaC();
    for(i=1;i<=n;i++)
        d=formarC(d,i);
    return d;
}

int tirada(Dado d){
    int i,n=rand();

    for(i=1;i<=n;i++)
        d=rotacionC(d);
    return primeroC(d);
}
