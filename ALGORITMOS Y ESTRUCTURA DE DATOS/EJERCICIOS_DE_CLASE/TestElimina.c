#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\AVL.h"

int main(){
   ArBB a=vacioB();

   Elem e;

   while(e)
      a=InsAVL(e=LeeElem(),a);

   puts("-----------");
   ImpElem(ElemMasDerechoB(a));
   printf("\n");
   puts("-----------");
   ImpElem(ElemMasIzquierdoB(a));
   printf("\n");
   puts("-----------");
   ImpNivelPorNivelAB(a);
   puts("-----------");


   while(!esvacioB(a)){
      puts("Elemento a eliminar?");
      a=EliminaAVL(e=LeeElem(),a);
      puts("-----------");
      ImpNivelPorNivelAB(a);
   }

   return 0;
}
