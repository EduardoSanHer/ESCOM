#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Pila.h"

void Hanoi(Pila,Pila,Pila);
void ImpTowers(Pila,Pila,Pila);
void Move(Pila*,Pila*);

int main(){
    printf("*****Torre de Hanoi*****\n");
    Pila S,A,D;
    S=A=D=empty();
    S=push(1,push(2,push(3,empty())));
    printf("*****Inicio*****\n");
    ImpTowers(S,A,D);
    Hanoi(S,A,D);
    printf("*****Fin*****\n");

    return 0;
}

void Hanoi(Pila Source, Pila Aux, Pila Dest){
    if(!isempty(Source)&&isempty(Aux)&&isempty(Dest)){
        printf("\n**********1**********\n");
        Move(&Source,&Dest);
        ImpTowers(Source,Aux,Dest);
        Hanoi(Source,Aux,Dest);
    }
    else if(isempty(Aux)&&(top(Dest)<top(Source))){
        printf("\n**********2**********\n");
        Move(&Source,&Aux);
        ImpTowers(Source,Aux,Dest);
        Hanoi(Source,Aux,Dest);
    }
    else if(!isempty(Source)&&!isempty(Aux)&&!isempty(Dest)&&(top(Dest)<top(Aux))){
        printf("\n**********3**********\n");
        Move(&Dest,&Aux);
        ImpTowers(Source,Aux,Dest);
        Hanoi(Source,Aux,Dest);
    }
    else if(!isempty(Source)&&!isempty(Aux)&&isempty(Dest)){
        printf("\n**********4**********\n");
        Move(&Source,&Dest);
        ImpTowers(Source,Aux,Dest);
        Hanoi(Source,Aux,Dest);
    }
    else if(isempty(Source)&&!isempty(Aux)&&!isempty(Dest)){
        printf("\n**********5**********\n");
        Move(&Aux,&Source);
        ImpTowers(Source,Aux,Dest);
        Hanoi(Source,Aux,Dest);
    }
    else if(!isempty(Source)&&!isempty(Aux)&&!isempty(Dest)&&(top(Aux)<top(Dest))){
        printf("\n**********6**********\n");
        Move(&Aux,&Dest);
        ImpTowers(Source,Aux,Dest);
        Hanoi(Source,Aux,Dest);
    }
    else if(!isempty(Source)&&isempty(Aux)&&!isempty(Dest)&&(top(Source)<top(Dest))){
        printf("\n**********7**********\n");
        Move(&Source,&Dest);
        ImpTowers(Source,Aux,Dest);
    }
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

void Move(Pila *TowerF, Pila *TowerT){
    Elem temp=top(*TowerF);
    *TowerT=push(temp,*TowerT);
    *TowerF=pop(*TowerF);
}