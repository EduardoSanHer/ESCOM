/*
Espec ColaPrior
//Constructoras
    nueva: -> Cola;
    formaP: Cola, Elem, Int -> Cola
//Observadoras
    esnueva: Cola -> Bool;
//Desdobladoras
    primero: Cola -> Elem;
    desformar: Cola -> Cola;

//Axioma: Cola k, Elem e, int p;
    [Cp1] esnueva(nueva()) = Verdadero;
    [Cp2] esnueva(formaP(k,e,p)) = Falso;
    [Cp3] primero(nueva()) = ERROR;
    [Cp4] primero(formaP(k,e,p)) = e;
    [Cp5] desformar(nueva()) = NULL;
    [Cp6] desformar(formarP(k,e,p)) = nueva();

*/
typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
    int prio;
} *ApNodo;

typedef struct{
    ApNodo prim;
    ApNodo ult;
} CNodo;

typedef CNodo *Cola;

//Crea una nueva cola
Cola nueva(){
    Cola t=(Cola)malloc(sizeof(CNodo));
    t->prim=t->ult=NULL;
    return t;
}

//Pregunta si la cola es vacia
int esnueva(Cola q){
    return q->prim == NULL && q->ult == NULL;
}

//Forma elementos en la cola sin prioridad
/*
Cola formar(Cola q, Elem e){
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

//Forma elementos en la cola con prioridad, sin respetar el primero
/*
Cola formarP(Cola q, Elem e, int n){
    ApNodo t=(ApNodo)malloc(sizeof(struct Nodo));
    ApNodo k=(ApNodo)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=NULL;
    t->prio=n;
    if(esnueva(q))
        q->prim=q->ult=t;
    else if(q->prim->prio < n){
        t->sig = q->prim;
        q->prim = t;
    }
    else{
        Cola p = nueva();
        p->prim = q->prim; p->ult = q->ult;
        while((q->prim->sig != NULL) && (q->prim->sig->prio > t->prio)){q->prim = q->prim->sig;}
        t->sig = q->prim->sig;
        q->prim->sig = t;
        q->prim = p->prim;
        k=q->prim;
        while(k->sig!=NULL){k = k->sig;}
        q->ult = k;
    }
    return q;
}*/

//Forma elementos en la cola con prioridad, respetando el primero
Cola formarP(Cola q, Elem e, int n){
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
        Cola p = nueva();
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
Elem primero(Cola q){return q->prim->dato;}

//Desforma elementos de la cola
Cola desformar(Cola q){
    if(q->prim == q->ult)
        return nueva();
    else
        q->prim = q->prim->sig;
    return q;
}

/*Esta función es destructiva
void ImpCola(Cola q){
    while(!esnueva(q)){
        ImpElem(primero(q));
        q=desformar(q);
    }
}*/

//Imprime los elementos de la cola
void ImpCola(Cola q){
    Cola r=nueva();
    if(!esnueva(q)){
        ImpElem(primero(q));
        r->prim=q->prim;
        r->ult=q->ult;
        r=desformar(r);
        ImpCola(r);
    }
}
