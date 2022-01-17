//Para enteros
typedef int Elem;

void ImpElem(Elem e){printf("%d ",e);}

//void ImpElem(Elem e){printf("\t%d\n",e);}

Elem LeeElem(){
    Elem e;
    scanf("%d",&e);
    return e;
}

int Absoluto(Elem e){
    if(e<0)
        return -e;
    else
        return e;
}

int EsMenor(Elem e1, Elem e2){return e1<e2;}
int EsMenorIgual(Elem e1, Elem e2){ return e1<=e2; }
int EsMayor(Elem e1, Elem e2){ return e1>e2; }
int EsMayorIgual(Elem e1, Elem e2){ return e1>=e2; }
int EsIgual(Elem e1, Elem e2){return e1==e2;}

//TestArchivos
/*
typedef char* Elem;
void ImpElem(Elem e){printf("%s\n")}
int EsMenor(Elem e1, Elem e2){return strcmp(e1,e2)<0;}*/