#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

Lista Tabla(int,int);
void ImpTabla(int,int);

int main(){
    int m=6,n=5;
    Lista l=vacia();
    l=Tabla(m,n);
    ImpElems(l);
    //ImpTabla(m,n);

    Lista a=vacia();
    Lista b=vacia();
    a=cons(4,cons(5,cons(6,a)));
    b=cons(1,cons(2,cons(3,b)));
    Lista k=PegaListas(a,b);
    puts("\n_____________");
    ImpElems(a);
    puts("\n_____________");
    ImpElems(b);
    puts("\n_____________");
    ImpElems(k);
    Lista c=cons(4,cons(5,cons(6,cons(1,cons(2,cons(3,vacia()))))));
    puts("\n_____________");
    ImpElems(c);


    return 0;
}

Lista Tabla(int m, int n){
    Lista k=vacia();
    if(n!=0){
        k=cons(m*n,k);
        return k=PegaListas(Tabla(m,n-1),k);
    }

}

Lista PegaListas(Lista l1, Lista l2){
    if(esvacia(l1))
        return l2;
    else
        return cons(cabeza(l1),PegaListas(resto(l1),l2));
}
/*
void ImpTabla(int m, int n){
    int k=n;
    if(n!=0)
        printf("%d ",m*n);
    ImpTabla(m,n++);
*/
