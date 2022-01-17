//#include<stdio.h>
//#include<stdlib.h>
//#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Lista.h"
//#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
typedef Lista Cola;

Cola nueva(){vacia();}

int esnueva(Cola q){return esvacia(q);}

Cola formar(Cola q, Elem e){
    if(esnueva(q))
        return cons(e,q);
    else
        return cons(cabeza(q),formar(resto(q),e));
}

Elem primero(Cola q){return cabeza(q);}

Cola desformar(Cola q){return resto(q);}