typedef struct Nodo{
    char dato;
    struct Nodo *next;
    } *Stack;

Stack empty(){return NULL;}

Stack push(char e, Stack l){
    Stack t=(Stack)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->next=l;
    return t;
}

int isempty(Stack l){return l==NULL;}

char top(Stack l){return l ->dato;}

Stack pop(Stack l){return l ->next;}

int Numchars(Stack l){
    if(isempty(l))
        return 0;
    else
        return 1+Numchars(pop(l));
}

void Impchar(char e){printf("%c ",e);}

void Impchars(Stack l){
    if(!isempty(l)){
        Impchar(top(l));
        Impchars(pop(l));
    }
}

Stack PegaStacks(Stack l1, Stack l2){
    if(isempty(l1))
        return l2;
    else
        return push(top(l1),PegaStacks(pop(l1),l2));
}

Stack InvierteStacks(Stack l){
    if(isempty(l))
        return l;
    else
        return PegaStacks(InvierteStacks(pop(l)),push(top(l),empty()));
}