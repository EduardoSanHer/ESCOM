//Elem1
typedef struct NodoE1{
    char n;
    Lista2 ady;
} *Elem1;

char chrElem1(Elem1 e){ return e->n;}

void ImpElem1(Elem1 e){ printf("%c ",chrElem1(e));}

Elem1 LeeElem1(){
    Elem1 e=(Elem1)malloc(sizeof(struct NodoE1));
    fflush(stdin);
    scanf("%c",&e->n);
    e->ady=NULL;
    return e;
}
