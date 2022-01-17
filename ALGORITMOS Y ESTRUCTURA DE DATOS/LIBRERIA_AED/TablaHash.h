#include"F:\Users\Lalo\Documents\IPN\Semestre 2\AED\LibAED\Lista.h"

typedef Lista *TablaH;

TablaH consTH(int n){
    TablaH t=(TablaH)malloc(sizeof(Lista)*n);
    for(int i=0;i<n;i++)
        t[i]=vacia();
    return t;
}

int Hash(int n, char *C){
    int i,h=0;
    for(i=0;C[i]!='\0';i++)
        h+=C[i];
    h%=n;
    return h;
}
/* Para int
TablaH insHash(int Key, TablaH H, Elem S){
    H[Key]=cons(S,H[Key]);
    return H;
}*/

//Para ElemDic
TablaH insHash(Elem S,TablaH H, int n){
    int Key=Hash(n,S.nombre);
    H[Key]=cons(S,H[Key]);
    return H;
}

//Para ElemDic
TablaH delHash(Elem S,TablaH H, int n){
    int Key=Hash(n,S.nombre);
    /*//Primera implementacion (Funciona)
    if(EstaEn(S,H[Key])){
        if(!esvacia(H[Key])&&EsIgual(cabeza(H[Key]),S)){//strcmp(cabeza(H[Key]).nombre,S.nombre)
            H[Key]=resto(H[Key]);
        }
        else if(!esvacia(H[Key])){
            Elem K;
            K=cabeza(H[Key]);
            H[Key]=resto(H[Key]);
            delHash(n,H,S);
            H[Key]=cons(K,H[Key]);
        }
    }*/
    if(EstaEn(S,H[Key]))
        H[Key]=ElimElem(S,H[Key]);
    else
        printf("***El elemento no esta en la Tabla***\n");

    return H;
}

void Consulta(Elem e, Lista l){
    if(EsIgual(e,cabeza(l)))
        ImpElem(cabeza(l));
    else
        Consulta(e,resto(l));
}

//Para ElemDic
void Search(Elem S, TablaH H, int n){
    int Key=Hash(n,S.nombre);
    /* Primera implementacion (Funciona)
    if(!esvacia(H[Key])&&EsIgual(cabeza(H[Key]),S))
        return H[Key];
    else if(!esvacia(H[Key])){
        Elem K;
        K=cabeza(H[Key]);
        H[Key]=resto(H[Key]);
        Search(S,H,n);
    }*/
    if(EstaEn(S,H[Key]))
        Consulta(S,H[Key]);
    else
        printf("No se encuentra el elemento\n");
}

void impTHash(TablaH H, int n){
    for(int i=0;i<n;i++){
        printf("T[%d]:\t",i);
        ImpElems(InvierteLista(H[i]));
        puts("---------------------------------\n");
    }
}
