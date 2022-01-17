#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ElemDic.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\TablaHash.h"


int main(){

    //int i;
    //char *a= "AAAA";
    TablaH t1=consTH(10);

    t1=insHash(LeeElem(),t1,10);
    impTHash(t1,10);
    t1=insHash(LeeElem(),t1,10);
    impTHash(t1,10);
    t1=insHash(LeeElem(),t1,10);
    impTHash(t1,10);
    t1=delHash(LeeIdent(),t1,10);
    impTHash(t1,10);

    //printf("*******%d\n",a[0]+a[1]+a[2]+a[3]+a[4]);
    //printf("____%d\n",Hash(10,a));
/*
    t1=insHash(4,t1,44);
    t1=insHash(4,t1,55);
    t1=insHash(5,t1,66);
    t1=insHash(4,t1,66);
    t1=insHash(2,t1,66);
    for(i=0;i<10;i++){
        printf("T1[%d]:\t",i);
        ImpElems(InvierteLista(t1[i]));
        printf("\n");
    }
    puts("---------\n");
    t1=delHash(2,t1,66);
    t1=delHash(4,t1,55);
    for(i=0;i<10;i++){
        printf("T1[%d]:\t",i);
        ImpElems(InvierteLista(t1[i]));
        printf("\n");
    }
    puts("---------\n");
    if(Search(44,t1,4))
        printf("El elemento se encuentra en la tabla\n");
    else
        printf("El elemento no esta en la tabla\n");
*/
    return 0;
}
