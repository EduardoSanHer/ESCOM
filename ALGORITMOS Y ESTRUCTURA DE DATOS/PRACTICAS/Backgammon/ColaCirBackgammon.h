typedef struct NodoCir{
    Elem dato;
    struct NodoCir *sig;
    } *Circular;

Circular nuevaC(){return NULL;}

int esvaciaC(Circular c){return c==NULL;}

Circular formarC(Elem e,Circular c){
    Circular t=(Circular)malloc(sizeof(struct NodoCir));
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

