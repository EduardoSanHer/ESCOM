typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
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

//Forma elementos en la cola
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

int EstaEnCola(Elem e, Cola q){
    if(esnueva(q))
        return 0;
    else if(EsIgual(primero(q),e))
        return 1;
    else
        return EstaEnCola(e,desformar(q));
}

Cola PegaColas(Cola q1, Cola q2){
    if(esnueva(q2))
        return q1;
    else
        return formar(PegaColas(q1,desformar(q2)),primero(q2));
}

Cola formarOrdAsc(Cola q, Elem e){
    ApNodo t =(ApNodo)malloc(sizeof(struct Nodo));
    t->dato=e; t->sig=NULL;
    if(esnueva(q))
        return formar(q,e);
    else if(EsMenor(e,primero(q))){
        t->sig = q->prim;
        q->prim = t;
        return q;
    }
    else
        return formarOrdAsc(desformar(q),e);
}

Cola OrdColaAsc(Cola q){
    if(esnueva(q))
        return q;
    else
        return formarOrdAsc(OrdColaAsc(desformar(q)),primero(q));
}