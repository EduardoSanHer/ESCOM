#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Elem.h"
#include"ColaCir.h"

Circular formaAlCircular(Circular);
Circular SumaElemsCir(Circular);
void ImpColaC(Circular);

int main(){
    srand(time(NULL));
    Circular q = nuevaC();
    q=formaAlCircular(q);
    ImpColaC(q);
    puts("\n_______");
    Circular k = nuevaC();
    k=SumaElemsCir(q);
    ImpColaC(k);
    puts("\n_______");


    return 0;
}

Circular formaAlCircular(Circular q){
    for(int i=0;i<10;i++)
        q=formarC(q,rand());
    return q;
}

Circular SumaElemsCir(Circular q1){
    Circular q2 = nuevaC();
    int s=0;
    for(int i=10;i!=0;i--){
        s+=primeroC(q1);
        q2 = formarC(q2,s);
        q1 = desformarC(q1);
    }
    return q2;
}

void ImpColaC(Circular q){
    Circular k=q;
    int i=10;
    for(i=10;i!=0;i--){
        ImpElem(primeroC(k));
        k=rotacionC(k);
    }
}