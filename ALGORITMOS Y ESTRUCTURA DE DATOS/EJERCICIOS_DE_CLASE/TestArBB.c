#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
//#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ArBin.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\ArBB.h"

int main(){
    ArBB a = vacioB();

    a=InsOrdAB(24,InsOrdAB(20,InsOrdAB(30,InsOrdAB(34,a))));

    InOrder(a);
    puts("__________");
    ImpNivelPorNivelAB(a);
    puts("__________");
    ImpNivelAB(a,3);

    return 0;
}
