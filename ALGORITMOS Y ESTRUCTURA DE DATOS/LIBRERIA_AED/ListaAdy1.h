//Lista1
typedef struct NodoL1{
    Elem1 dato;
    struct NodoL1 *sig;
} *Lista1;

Lista1 vacia1(){return NULL;}

Lista1 cons1(Elem1 e, Lista1 l){
    Lista1 t=(Lista1)malloc(sizeof(struct NodoL1));
    t->dato=e;
    t->sig=l;
    return t;
}

int esvacia1(Lista1 l){return l==NULL;}

Elem1 cabeza1(Lista1 l){return l->dato;}

Lista1 resto1(Lista1 l){return l->sig;}

void ImpElems1(Lista1 l){
    if(!esvacia1(l)){
        ImpElem1(cabeza1(l));
        ImpElems1(resto1(l));
    }
}

void ImpElems3(Lista1 l){
    if(!esvacia1(l)){
        ImpElem1(cabeza1(l));
        printf("->\t");
        if(!esvacia2(cabeza1(l)->ady)){
            ImpElem2(cabeza2(cabeza1(l)->ady));
            ImpElems2(resto2(cabeza1(l)->ady));
        }
        printf("\n");
        ImpElems3(resto1(l));
    }
}
