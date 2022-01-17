typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
    } *Pila;

Pila empty(){return NULL;}

Pila push(Elem e, Pila l){
    Pila t=(Pila)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=l;
    return t;
}

int isempty(Pila l){return l==NULL;}

Elem top(Pila l){return l ->dato;}

Pila pop(Pila l){return l ->sig;}

Pila InsOrd(Elem e, Pila s){
    if(isempty(s))
        return push(e,s);
    else if (EsMenor(e,top(s)))
        return push(e,s);
    else
        return push(top(s),InsOrd(e,pop(s)));
}

Pila RotarP(Pila s, Elem e){
    if(isempty(s))
        return push(e,s);
    else
        return push(top(s),RotarP(pop(s),(e)));
}

Pila OrdPilaAsc(Pila s){
    if(isempty(s))
        return s;
    else
        return InsOrd(top(s),OrdPilaAsc
    (pop(s)));
}

int NumElems(Pila l){
    if(isempty(l))
        return 0;
    else
        return 1+NumElems(pop(l));
}

/*void ImpElems(Pila l1,Pila l2,Pila l3){
    printf("wwwww\n");
    if(!isempty(l1))
        ImpElem(top(l1));
    else
        printf("\t  ");
    if(!isempty(l2))
        ImpElem(top(l2));
    else
        printf("\t  ");
    if(!isempty(l3))
        ImpElem(top(l3));
    else
        printf("\t  ");
    printf("\n");
    if(!isempty(l1)&&!isempty(l2)&&!isempty(l3))
        ImpElems(pop(l1),pop(l2),pop(l3));
    else if(isempty(l1)&&!isempty(l2)&&!isempty(l3))
        ImpElems(empty(),pop(l2),pop(l3));
    else if(isempty(l1)&&isempty(l2)&&!isempty(l3))
        ImpElems(empty(),empty(),pop(l3));
    else if(!isempty(l1)&&isempty(l2)&&!isempty(l3))
        ImpElems(pop(l1),empty(),pop(l3));
    else if(!isempty(l1)&&!isempty(l2)&&isempty(l3))
        ImpElems(pop(l1),pop(l2),empty());
    else if(!isempty(l1)&&isempty(l2)&&isempty(l3))
        ImpElems(pop(l1),empty(),empty());
    else if(isempty(l1)&&!isempty(l2)&&isempty(l3))
        ImpElems(empty(),pop(l2),empty());
    else if(isempty(l1)&&isempty(l2)&&isempty(l3))
        printf("XD\n");
}*/

void ImpElems(Pila l){
    if(!isempty(l)){
        ImpElem(top(l));
        ImpElems(pop(l));
    }
}

Pila PegaPilas(Pila l1, Pila l2){
    if(isempty(l1))
        return l2;
    else
        return push(top(l1),PegaPilas(pop(l1),l2));
}

Pila InviertePilas(Pila l){
    if(isempty(l))
        return l;
    else
        return PegaPilas(InviertePilas(pop(l)),push(top(l),empty()));
}