typedef struct{
    char *nombre;
    char *capital;
    int numHab;
    char *moneda;
    char *idioma;
    char *gent;
} Elem;

Elem LeeElem(){
    Elem e;
    e.nombre=(char*)malloc(20);
    e.capital=(char*)malloc(20);
    e.moneda=(char*)malloc(20);
    e.idioma=(char*)malloc(20);
    e.gent=(char*)malloc(20);
    printf("Nombre:");
    fflush(stdin);
    scanf("%[^\n]",e.nombre);//s
    printf("Capital:");
    fflush(stdin);
    scanf("%[^\n]",e.capital);//s
    printf("Numero de habitantes:");
    scanf("%d",&e.numHab);
    printf("Moneda:");
    scanf("%s",e.moneda);
    printf("Idioma:");
    scanf("%s",e.idioma);
    printf("Gentilicio:");
    scanf("%s",e.gent);

    return e;
}

Elem LeeIdent(){
    Elem e;
    e.nombre=(char*)malloc(20);
    e.capital=(char*)malloc(20);
    e.moneda=(char*)malloc(20);
    e.idioma=(char*)malloc(20);
    e.gent=(char*)malloc(20);
    fflush(stdin);
    scanf("%[^\n]",e.nombre);//s
    e.capital=NULL;
    e.moneda=NULL;
    e.idioma=NULL;
    e.gent=NULL;
    e.numHab=0;
    return e;
}

Elem LeeElemF(FILE *ent){
    Elem e;
    e.nombre=(char*)malloc(20);
    e.capital=(char*)malloc(20);
    e.moneda=(char*)malloc(20);
    e.idioma=(char*)malloc(20);
    e.gent=(char*)malloc(20);
    //fscanf(ent,"%s%s%d%s%s%s",e.nombre,e.capital,&e.numHab,e.moneda,e.idioma,e.gent);
    fscanf(ent,"%s%s%d%s%s%s",e.nombre,e.capital,&e.numHab,e.moneda,e.idioma,e.gent);

    return e;
}

void ImpElem(Elem e){
    printf("%s\t%s\t%d\t%s\t%s\t%s\n",e.nombre,e.capital,e.numHab,e.moneda,e.idioma,e.gent);
}

int EsIgual(Elem e1, Elem e2){return !strcmp(e1.nombre,e2.nombre);}
int EsMenor(Elem e1, Elem e2){
    if(strcmp(e1.nombre,e2.nombre)<0)
    return 1;
}
int EsMenorIgual(Elem e1, Elem e2){ return EsMenor(e1,e2)||EsIgual(e1,e2); }
int EsMayor(Elem e1, Elem e2){
    if(strcmp(e1.nombre,e2.nombre)>0)
        return 1;
}
