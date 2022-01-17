#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

int main(){

    int i,j;
    TablaH t1=consTH(10);

    for(i=0;i<10;i++)
        for(j=1;j<=10;j++)
            t1[i]=cons((i+1)*j,t1[i]);

    for(i=0;i<10;i++){
        ImpElems(InvierteLista(t1[i]));
        printf("\n");
    }

    return 0;
}