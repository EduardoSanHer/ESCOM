
typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
    int prio;
} *ApNodo;

typedef struct{
    ApNodo prim;
    ApNodo ult;
} CNodo;

typedef CNodo *ColaPrior;

//Crea una nueva ColaPrior
ColaPrior nueva(){
    ColaPrior t=(ColaPrior)malloc(sizeof(CNodo));
    t->prim=t->ult=NULL;
    return t;
}

//Pregunta si la ColaPrior es vacia
int esnueva(ColaPrior q){
    return q->prim == NULL && q->ult == NULL;
}

//Forma elementos en la ColaPrior sin prioridad
/*
ColaPrior formar(ColaPrior q, Elem e){
    ApNodo t =(ApNodo)malloc(sizeof(struct Nodo));
    t->dato=e; t->sig=NULL;
    if(esnueva(q))
        q->prim=q->ult=t;
    else{
        q->ult->sig = t;
        q->ult = t;
    }
    return q;
}*/

//Forma elementos en la ColaPrior con prioridad, sin respetar el primero
/*
ColaPrior formarP(ColaPrior q, Elem e, int n){
    ApNodo t=(ApNodo)malloc(sizeof(struct Nodo));
    ApNodo k=(ApNodo)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=NULL;
    t->prio=n;
    if(esnueva(q))
        q->prim=q->ult=t;
    /*else if(q->prim->prio < n){
        t->sig = q->prim;
        q->prim = t;
    }* /
    else{
        ColaPrior p = nueva();
        p->prim = q->prim; p->ult = q->ult;
        while((q->prim->sig != NULL) && (q->prim->sig->prio => t->prio)){q->prim = q->prim->sig;}
        t->sig = q->prim->sig;
        q->prim->sig = t;
        q->prim = p->prim;
        k=q->prim;
        while(k->sig!=NULL){k = k->sig;}
        q->ult = k;
    }
    return q;
}*/

//Forma elementos en la ColaPrior con prioridad, respetando el primero
ColaPrior formarP(ColaPrior q, Elem e, int n){
    ApNodo t=(ApNodo)malloc(sizeof(struct Nodo));
    ApNodo k=(ApNodo)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=NULL;
    t->prio=n;
    if(esnueva(q))
        q->prim=q->ult=t;
    /*else if(q->ult->prio >= t->prio){
        q->ult->sig = t;
        q->ult = t;
    }*/
    else if((q->prim->sig == NULL) || (q->prim->sig->prio < t->prio)){
        t->sig = q->prim->sig;
        q->prim->sig = t;
        k=q->prim;
        while(k->sig!=NULL) {k = k->sig;}
        q->ult = k;
    }
    else if((q->prim->sig != NULL)){
        ColaPrior p = nueva();
        p->prim = q->prim; p->ult = q->ult;
        while((q->prim->sig->sig != NULL) && (q->prim->sig->sig->prio >= t->prio)) {q->prim = q->prim->sig;}
        t->sig = q->prim->sig->sig;
        q->prim->sig->sig = t;
        q->prim = p->prim;
        k=q->prim;
        while(k->sig!=NULL) {k = k->sig;}
        q->ult = k;
    }
    return q;
}

//Obtiene el primer elemento (cabeza)
Elem primero(ColaPrior q){return q->prim->dato;}

//Desforma elementos de la ColaPrior
ColaPrior desformar(ColaPrior q){
    if(q->prim == q->ult)
        return nueva();
    else
        q->prim = q->prim->sig;
    return q;
}

/*Esta función es destructiva
void ImpColaPrior(ColaPrior q){
    while(!esnueva(q)){
        ImpElem(primero(q));
        q=desformar(q);
    }
}*/

//Imprime los elementos de la ColaPrior
void ImpColaPrior(ColaPrior q){
    ColaPrior r=nueva();
    if(!esnueva(q)){
        ImpElem(primero(q));
        r->prim=q->prim;
        r->ult=q->ult;
        r=desformar(r);
        ImpColaPrior(r);
    }
}
