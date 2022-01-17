#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"Lista.h"
#include"ArBB.h"

ArBB formaAlArBB(ArBB);
Lista copiaInOrder(ArBin,Lista);
int NumRep(Elem,Lista);
Lista BorraElems(Lista, Elem);
Lista ElimRepetidos(Lista);
ArBB InsDeLista(Lista);

int main(){

    ArBB a = vacioB();
    a=formaAlArBB(a);
    Lista l = vacia();
    l = copiaInOrder(a,l);
    InOrder(a);
    puts("\n_________");
    l=ElimRepetidos(l);
    ImpElems(l);
    puts("\n_________");
    ArBB b = vacioB();
    b=InsDeLista(l);
    InOrder(b);
    puts("\n_________");
    ImpNivelPorNivelAB(b);
    puts("\n_________");

    return 0;
}

ArBB formaAlArBB(ArBB q){
    for(int i=0;i<200;i++)
        q=InsOrdAB((rand()%15)+1,q);
    return q;
}

Lista copiaInOrder(ArBin a, Lista l){
    if(!esvacioB(a)){
        l=copiaInOrder(izquierdoB(a),l);
        l=cons(raiz(a),l);
        l=PegaListas(copiaInOrder(derechoB(a),l),l);
        return l;
    }
    else
        return vacia();
}

int NumRep(Elem e, Lista l){
    int r=0;
    while(EstaEnLista(e,l)){
        r++;
        l=ElimElem(e,l);
    }
    return r;
}

Lista BorraElems(Lista l, Elem e){
    while(EstaEnLista(e,l) && (NumRep(e,l)>1))
        l=ElimElem(e,l);
    return l;
}

Lista ElimRepetidos(Lista l){
    if(!esvacia(l)){
        l=BorraElems(l,cabeza(l));
        return l=PegaListas(cons(cabeza(l),vacia()),ElimRepetidos(resto(l)));
    }
    else
        return vacia();
}

ArBB InsDeLista(Lista l){
    ArBB a=vacioB();
    while(!esvacia(l)){
        a=InsOrdAB(cabeza(l),a);
        l=resto(l);
        l=InvierteLista(l);
    }
    return a;
}
