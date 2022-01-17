typedef struct Nodo{
    int id_Pagina;
    int id_Marco;
    struct Nodo *sig;
    } *Tabla;

Tabla vacia(){return NULL;}

Tabla agregar(int id_Pagina, int id_Marco, Tabla l){
    Tabla t=(Tabla)malloc(sizeof(struct Nodo));
    t->id_Pagina=id_Pagina;
    t->id_Marco=id_Marco;
    t->sig=l;
    return t;
}

int esvacia(Tabla l){return l==NULL;}

int obtener_id_Pagina(Tabla l){return l ->id_Pagina;}

int obtener_id_Marco(Tabla l){return l ->id_Marco;}

Tabla pop(Tabla l){return l ->sig;}

int NumElems(Tabla l){
    if(esvacia(l))
        return 0;
    else
        return 1+NumElems(pop(l));
}


Tabla PegaTablas(Tabla l1, Tabla l2){
    if(esvacia(l1))
        return l2;
    else
        return agregar(obtener_id_Pagina(l1),obtener_id_Marco(l1),PegaTablas(pop(l1),l2));
}

Tabla InvierteTabla(Tabla l){
    if(esvacia(l))
        return l;
    else
        return PegaTablas(InvierteTabla(pop(l)),agregar(obtener_id_Pagina(l),obtener_id_Marco(l),vacia()));
}

Tabla id_Pagina_EstaEn(int id_Pagina, Tabla l){
    if(esvacia(l))
        return 0;
    else if (id_Pagina == obtener_id_Pagina(l))
        return l;
    else
        return id_Pagina_EstaEn(id_Pagina,pop(l));
}
/*
Tabla ElimElem(int id_Pagina, Tabla l){
    if(id_Pagina == obtener_id_Pagina(l))
        return pop(l);
    else
        return agregar(obtener_id_Pagina(l),obtener_id_Marco(l),ElimElem(id_Pagina,pop(l)));
}*/
