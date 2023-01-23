typedef struct Nodo{
    unsigned char dato;
    struct Nodo *sig;
} *Pila;

//Pila empty(){return NULL;}

Pila push(unsigned char e, Pila l){
    //Pila t=(Pila)malloc(sizeof(struct Nodo));
    Pila t;
    t->dato=e;
    t->sig=l;
    return t;
}

//int isempty(Pila l){return l==NULL;}

unsigned char top(Pila l){return l ->dato;}

Pila pop(Pila l){return l ->sig;}

/*
int NumElems(Pila l){
    if(isempty(l))
        return 0;
    else
        return 1+NumElems(pop(l));
}*/