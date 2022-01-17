//Lista2
typedef struct NodoL2{
    Elem2 dato;
    struct NodoL2 *sig;
} *Lista2;

Lista2 vacia2(){return NULL;}

Lista2 cons2(Elem2 e, Lista2 l){
    Lista2 t=(Lista2)malloc(sizeof(struct NodoL2));
    t->dato=e;
    t->sig=l;
    return t;
}

int esvacia2(Lista2 l){return l==NULL;}

Elem2 cabeza2(Lista2 l){return l->dato;}

Lista2 resto2(Lista2 l){return l->sig;}

void ImpElems2(Lista2 l){
    if(!esvacia2(l)){
        ImpElem2(cabeza2(l));
        ImpElems2(resto2(l));
    }
}
