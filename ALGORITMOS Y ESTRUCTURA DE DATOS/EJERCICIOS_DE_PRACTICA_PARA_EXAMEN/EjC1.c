#include<stdio.h>
#include<stdlib.h>
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Elem.h"
#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Cola2.h"

Cola BorraElems(Elem,Cola);

int main(){

    Cola q=nueva();
    q=formar(formar(formar(formar(formar(formar(q,1),2),3),3),2),1);
    ImpCola(q);
    printf("\nIndique el elemento a borrar: ");
    q=BorraElems(LeeElem(),q);
    if(!esnueva(q))
        ImpCola(q);
    else
        puts("\nPTMDRE");

    return 0;
}

Cola BorraElems(Elem e,Cola q){
    if(!esnueva(q))
        if(EsIgual(primero(q),e))
            return BorraElems(e,desformar(q));
        else
            return formar(BorraElems(e,desformar(q)),primero(q));
    else
        return nueva();
}
