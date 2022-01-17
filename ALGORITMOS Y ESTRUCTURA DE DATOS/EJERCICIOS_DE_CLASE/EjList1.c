#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Lista.h"
//int NumElems(Lista);
//void ImpElems(Lista);
//Lista InvierteLista(Lista);
//Lista PegaListas(Lista,Lista);

int main(){
     Elem e;
     Lista a,b;

     a=cons('c',cons('a',cons('r',cons('t',vacia())))); // a=[a,b,c,d]
     b=cons('x',cons('y',cons('z',cons('w',vacia()))));

     printf("La lista a tiene %d elementos.\n", NumElems(PegaListas(a,b)));
     printf("El resto de la lista a tiene %d elementos.\n", NumElems(resto(a)));
     puts("La lista a tiene los siguientes elementos:");
     ImpElems(a);

     puts("La lista que resulta de pegar a con b es:");
     ImpElems(PegaListas(a,b));

     puts("La lista que resulta de invertir a la lista a es:");
     ImpElems(InvierteLista(a));

     puts("La lista que resulta de invertit la lista que resulta de pegar a con b es:");
     ImpElems(InvierteLista(PegaListas(a,b)));

     puts("La lista que resulta de ordenar la lista que resulta de pegar a con b es:");
     ImpElems(OrdListaAsc(PegaListas(a,b)));

     puts("La lista que resulta de ordenar la lista que resulta de pegar b con a es:");
     ImpElems(OrdListaAsc(PegaListas(b,a)));

     //puts("La lista que resulta de ordenar descendentemente la lista que resulta de pegar b con a es:");
     //ImpElems(OrdListaDesc(PegaListas(b,a)));

     return 0;
}




