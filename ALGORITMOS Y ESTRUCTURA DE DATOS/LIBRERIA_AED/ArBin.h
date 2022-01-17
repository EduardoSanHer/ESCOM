/*
Espec ArBin
//Constructuras
    vacioB: -> ArBin;
    consB: Elem, ArBin, ArBin -> ArBin;
//Observadoras
    esvacioB: ArBin -> Bool;
    raiz: ArBin -> Elem;
//Desdobladoras
    izquierdoB: ArBin -> ArBin;
    derechoB: ArBin -> ArBin;

//Axioma: Elem r, ArBin i, d;
    [Ab1] esvacioB(vacioB()) = Verdadero;
    [Ab2] esvacioB(consB(r,i,d)) = Falso;
    [Ab3] raiz(vacioB()) = ERROR;
    [Ab4] raiz(consb(r,i,d)) = r;
    [Ab5] izquierdoB(vacioB()) = ERROR;
    [Ab6] izquierdoB(consB(r,i,d)) = i;
    [Ab7] derechoB(vacioB()) = ERROR;
    [Ab8] derechoB(consB(r,i,d)) = d;
*/

typedef struct Nodo{
    Elem dato;
    struct Nodo *izq;
    struct Nodo *der;
}*ArBin;

ArBin vacioB(){ return NULL;}

ArBin consB(Elem r, ArBin i, ArBin d){
    ArBin t = (ArBin)malloc(sizeof(struct Nodo));
    t->dato=r;
    t->izq=i;
    t->der=d;
    return t;
}

int esvacioB(ArBin a){return a == NULL;}

Elem raiz(ArBin a){ return a->dato;}

ArBin izquierdoB(ArBin a){ return a->izq;}

ArBin derechoB(ArBin a){ return a->der;}

int EsHoja(ArBin a){
    return (esvacioB(izquierdoB(a))&&esvacioB(derechoB(a)));
}

int EsInterno(ArBin a){return !EsHoja(a);}

int Mayor(int n1, int n2){
    if(n1>=n2)
        return n1;
    else
        return n2;
}

int AlturaAB(ArBin a){
    if(esvacioB(a))
        return 0;
    else
        return 1+Mayor(AlturaAB(izquierdoB(a)),AlturaAB(derechoB(a)));
}

int PesoAB(ArBin a){
    if(esvacioB(a))
        return 0;
     else
        return 1+PesoAB(izquierdoB(a))+PesoAB(derechoB(a));
}

Elem ElemMasDerechoB(ArBin a){
    if(EsHoja(a)||esvacioB(derechoB(a)))
        return raiz(a);
    else
        return ElemMasDerechoB(derechoB(a));
}

Elem ElemMasIzquierdoB(ArBin a){
    if(EsHoja(a)||esvacioB(izquierdoB(a)))
        return raiz(a);
    else
        return ElemMasIzquierdoB(izquierdoB(a));
}

int NumElemsB(ArBin a){
    if(esvacioB(a))
        return 0;
    else
        return 1+NumElemsB(izquierdoB(a))+NumElemsB(derechoB(a));
}

void PreOrder(ArBin a){
    if(!esvacioB(a)){
        ImpElem(raiz(a));
        PreOrder(izquierdoB(a));
        PreOrder(derechoB(a));
    }
}

void InOrder(ArBin a){
    if(!esvacioB(a)){
        InOrder(izquierdoB(a));
        ImpElem(raiz(a));
        InOrder(derechoB(a));
    }
}

void PostOrder(ArBin a){
    if(!esvacioB(a)){
        PostOrder(izquierdoB(a));
        PostOrder(derechoB(a));
        ImpElem(raiz(a));
    }
}

void ImpNivelAB(ArBin a, int nivel){
    if (esvacioB(a))
        return;
    if (nivel == 1)
        ImpElem(raiz(a));
    else if (nivel > 1){
        ImpNivelAB(izquierdoB(a), nivel-1);
        ImpNivelAB(derechoB(a), nivel-1);
    }
}

void ImpNivelPorNivelAB(ArBin a){
    int h = AlturaAB(a), i;
    for(i=1; i<=h; i++){
        ImpNivelAB(a, i);
        printf("\n");
    }
}