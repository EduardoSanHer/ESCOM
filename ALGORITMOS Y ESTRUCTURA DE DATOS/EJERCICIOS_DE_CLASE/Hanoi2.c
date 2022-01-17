#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Pila.h"

void Hanoi(Pila,Pila,Pila,int);
void ImpTowers(Pila,Pila,Pila);
void Move(Pila*,Pila*,int);

int main(){
    printf("*****Torre de Hanoi*****\n");
    Pila S,A,D;
    S=A=D=empty();
    int n=3;
    S=push(1,push(2,push(3,empty())));
    printf("*****Inicio*****\n");
    ImpTowers(S,A,D);
    Hanoi(S,A,D,n);
    ImpTowers(S,D,A);
    printf("*****Fin*****\n");

    return 0;
}

void Hanoi(Pila O,Pila A,Pila D,int n){
    if(n==1){
        Move(&O,&D,n);
    }
    else{
        Hanoi(O,D,A,n-1);
        Move(&O,&D,n);
        Hanoi(A,O,D,n-1);
    }   
}

void Move(Pila *TowerF, Pila *TowerT,int n){
    *TowerT=push(top(*TowerF),*TowerT);
    *TowerF=pop(*TowerF);
}

void ImpTowers(Pila Source, Pila Aux, Pila Dest){
    /*printf("\n\tTorre 1\tTorre 2\tTorre 3\n");
    ImpElems(Source,Aux,Dest);*/
    printf("\n\tTorre 1\n");
    ImpElems(Source);
    printf("\n\tTorre 2\n");
    ImpElems(Aux);
    printf("\n\tTorre 3\n");
    ImpElems(Dest);
    getchar();
}