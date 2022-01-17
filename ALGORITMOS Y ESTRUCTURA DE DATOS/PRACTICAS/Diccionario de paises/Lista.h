typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
    } *Lista;

Lista vacia(){return NULL;}

Lista cons(Elem e, Lista l){
    Lista t=(Lista)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=l;
    return t;
}

int esvacia(Lista l){return l==NULL;}

Elem cabeza(Lista l){return l ->dato;}

Lista resto(Lista l){return l ->sig;}

Lista InsOrd(Elem e, Lista s){
    if(esvacia(s))
        return cons(e,s);
    else if (EsMenor(e,cabeza(s)))
        return cons(e,s);
    else
        return cons(cabeza(s),InsOrd(e,resto(s)));
}

Lista OrdListaAsc(Lista s){
    if(esvacia(s))
        return s;
    else
        return InsOrd(cabeza(s),OrdListaAsc(resto(s)));
}

int NumElems(Lista l){
    if(esvacia(l))
        return 0;
    else
        return 1+NumElems(resto(l));
}

void ImpElems(Lista l){
    if(!esvacia(l)){
        ImpElem(cabeza(l));
        ImpElems(resto(l));
    }
}

Lista PegaListas(Lista l1, Lista l2){
    if(esvacia(l1))
        return l2;
    else
        return cons(cabeza(l1),PegaListas(resto(l1),l2));
}

Lista InvierteLista(Lista l){
    if(esvacia(l))
        return l;
    else
        return PegaListas(InvierteLista(resto(l)),cons(cabeza(l),vacia()));
}

Lista EstaEn(Elem e, Lista l){
    if(esvacia(l))
        return 0;
    else if (EsIgual(e,cabeza(l)))
        return l;
    else
        return EstaEn(e,resto(l));
}

Lista ElimElem(Elem e, Lista l){
    if(EsIgual(e,cabeza(l)))
        return resto(l);
    else
        return cons(cabeza(l),ElimElem(e,resto(l)));
}