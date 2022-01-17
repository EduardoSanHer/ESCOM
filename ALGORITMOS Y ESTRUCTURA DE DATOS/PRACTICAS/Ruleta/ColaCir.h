typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
    } *Circular;

Circular nuevaC(){return NULL;}

int esvaciaC(Circular c){return c==NULL;}

Circular formarC(Circular c,Elem e){
    Circular t=(Circular)malloc(sizeof(struct Nodo));
    t->dato=e;
    if(esvaciaC(c)){
        c=t;
        c->sig=t;
    }else{
        t->sig=c->sig;
        c->sig=t;
        c=t;
    }
    return c;
}

Elem primeroC(Circular c){return c->sig->dato;}

Circular rotacionC(Circular c){return c->sig;}

Circular desformarC(Circular c){
    Circular t=c->sig;
    if(c==c->sig){
        free(t);
        return nuevaC();
    }else{
        c->sig = c->sig->sig;
        free(t);
        return c;
    }
}

void ImpColaC(Circular q,int n){
    Circular k = nuevaC();
    k=q;
    if(!esvaciaC(k))
        for(int i=1;i<=n;i++){
            ImpElem(primeroC(k));
            k=rotacionC(k);
        }
}

