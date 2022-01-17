#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ArBin.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ArBB.h"

int main(){
    ArBB a=vacioB();

    Elem e;
    int i;
    srand(time(NULL));

    printf("Dame el dato a buscar:");
    scanf("%d",&e);
    EstaEn(e,a)?puts("Si."):puts("No.");

    a=InsOrdB(24,InsOrdB(20,InsOrdB(30,InsOrdB(34,InsOrdB(10,InsOrdB(4,a))))));

    for(i=0 ; i<=500 ; i++)
       a=InsOrdB(((rand()%500)+1),a);

    printf("Dame el dato a buscar:");
    scanf("%d",&e);

    EstaEn(e,a)?puts("Si."):puts("No.");

    InOrder(a);


    return 0;
}
