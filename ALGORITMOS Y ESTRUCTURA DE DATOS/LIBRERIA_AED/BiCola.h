typedef struct Nodo{
    Elem dato;
    struct Nodo *izq;
    struct Nodo *der;
} *ApNodo;

typedef struct{
    ApNodo izq;
    ApNodo der;
} BNodo;

typedef BNodo *BiCola;

//Crea una nueva BiCola
BiCola nuevaB(){
    BiCola t=(BiCola)malloc(sizeof(BNodo));
    t->izq=t->der=NULL;
    return t;
}

//Pregunta si la BiCola es vacia
int esnuevaB(BiCola q){
    return q->izq == NULL && q->der == NULL;
}

//Forma elementos en la BiCola de izq a der
BiCola formarI(Elem e, BiCola q){
    ApNodo t =(ApNodo)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->izq=NULL;
    t->der=NULL;
    if(esnuevaB(q))
        q->izq=q->der=t;
    else{
        t->der=q->izq;
        q->izq->izq = t;
        q->izq = t;
    }
    return q;
}

//Forma elementos en la BiCola de der a izq
BiCola formarD(BiCola q, Elem e){
    ApNodo t =(ApNodo)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->izq=NULL;
    t->der=NULL;
    if(esnuevaB(q))
        q->izq=q->der=t;
    else{
        t->izq=q->der;
        q->der->der = t;
        q->der = t;
    }
    return q;
}

//Obtiene el izqer elemento de izq a der
Elem izquierdo(BiCola q){return q->izq->dato;}

//Obtiene el izqer elemento de der a izq
Elem derecho(BiCola q){return q->der->dato;}

//Desforma elementos de la BiCola de izq a der
BiCola desformarI(BiCola q){
    if(q->izq == q->der)
        return nuevaB();
    else{
        q->izq = q->izq->der;
        q->izq->izq=NULL;
    }
    return q;
}

//Desforma elementos de la BiCola de der a izq
BiCola desformarD(BiCola q){
    if(q->izq == q->der)
        return nuevaB();
    else{
        q->der = q->der->izq;
        q->der->der=NULL;
    }
    return q;
}

//Imprime los elementos de la BiCola, de izq a der
/*//Esta funcion causa errores
void ImpBiCola(BiCola q){
    BiCola r=nuevaB();
    if(!esnuevaB(q)){
        ImpElem(izquierdo(q));
        r->izq=q->izq;
        r->der=q->der;
        r=desformarI(r);
        ImpBiCola(r);
    }
}
*/
//Esta funcion funciona correctamente
void ImpBiCola(BiCola q){
	ApNodo c=q->izq;
	while(c){
		ImpElem(c->dato);
		c=c->der;
	}
}

//Esta función causa el mismo error que la anterior
/*
int NumElems(BiCola q){
    BiCola r=nuevaB();
    int n=0;
    if(!esnuevaB(q)){
        n+=1;
        r->izq=q->izq;
        r->der=q->der;
        r=desformarI(r);
        n+=NumElems(r);
    }
    return n;
}
*/

int NumElems(BiCola q){
    ApNodo k=q->izq;
    int n=0;
    while(k){
        n+=1;
        k=k->der;
    }
    return n;
}