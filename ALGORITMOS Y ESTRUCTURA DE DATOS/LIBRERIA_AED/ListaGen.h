typedef struct NodoListaGen{
        int EsAtomo;
        union {
            Elem Atomo;
            struct NodoListaGen *ListaGenElem ;
        } dato;
        struct NodoListaGen *sig;
}*ListaGen;

ListaGen vaciag(){return NULL;}


ListaGen consElem(Elem e, ListaGen lg){
    ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
    temp->EsAtomo = 1;
    temp->dato.Atomo = e;
    temp->sig = lg;
    return temp;
 }


ListaGen consLista(ListaGen e, ListaGen lg){
    ListaGen temp = (ListaGen)malloc(sizeof(struct NodoListaGen));
    temp->EsAtomo = 0;
    temp->dato.ListaGenElem = e;
    temp->sig = lg;
    return temp;
 }

int esvaciag(ListaGen lg){ return lg == NULL ;}

Elem cabezaElem(ListaGen lg){ return lg->dato.Atomo;}

ListaGen cabezaLista(ListaGen lg){ return lg->dato.ListaGenElem;}

ListaGen restog(ListaGen lg){ return lg->sig;}

int EsAtomo(ListaGen lg){ return lg->EsAtomo;}

int NumElemListaGen(ListaGen lg){
     if(esvaciag(lg))
        return 0;
     else
        return 1+NumElemListaGen(restog(lg));
}

void ImpListaGen(ListaGen lg){
	if(!esvaciag(lg)){
	    if(EsAtomo(lg))
	        ImpElem(cabezaElem(lg));
	    else{
	        printf("(");
	        ImpListaGen(cabezaLista(lg));
	        printf(")");}
        ImpListaGen(restog(lg));
    }
};

ListaGen PegaListasG(ListaGen lg1, ListaGen lg2){
	if(esvaciag(lg1))
	    return lg2;
	else if(EsAtomo(lg1))
	    return consElem(cabezaElem(lg1),PegaListasG(restog(lg1),lg2));
        else
            return consLista(cabezaLista(lg1),PegaListasG(restog(lg1),lg2));
}

ListaGen InvierteG(ListaGen lg){
    if(esvaciag(lg))
        return lg;
    else if(EsAtomo(lg))
            return PegaListasG(InvierteG(restog(lg)),consElem(cabezaElem(lg),vaciag()));
        else
            return PegaListasG(InvierteG(restog(lg)),consLista(InvierteG(cabezaLista(lg)),vaciag()));
}
