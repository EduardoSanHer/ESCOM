#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ElemAdy2.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ListaAdy2.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ElemAdy1.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ListaAdy1.h"

int main(){
    int i,o;
    Elem1 k=NULL;
    Elem2 f;
    Lista1 l1=vacia1();

    for(i=0;i<5;i++){
        printf("Vertice***\n");
        k=LeeElem1();
        printf("Adyacencias\n");
        for(o=0;o<5;o++){
            f=LeeElem2();
            k->ady=cons2(f,k->ady);
        }
        l1=cons1(k,l1);
    }

    //ImpElems1(l1);
    ImpElems3(l1);

    return 0;
}
