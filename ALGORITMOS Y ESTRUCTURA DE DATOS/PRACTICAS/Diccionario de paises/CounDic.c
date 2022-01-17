#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ElemDic.h"
#include"TablaHash.h"

int Menu();
TablaH InicioDic(TablaH,int,FILE*);

int main(){
    int i,m,Num=20;

    FILE *Paises=fopen("Paises.txt","r");
    TablaH P=consTH(Num);
    P=InicioDic(P,Num,Paises);
    do{
        m=Menu();
        switch(m){
            case 1:
                printf("Introduzca el nombre de su consulta:");
                Search(LeeIdent(),P,Num);
                break;
            case 2:
                printf("Introduzca los datos del pais:\n");
                P=insHash(LeeElem(),P,Num);
                puts("**Se ha agregado correctamente**\n");
                break;
            case 3:
                printf("Introduzca el nombre del pais\n");
                P=delHash(LeeIdent(),P,Num);
                puts("**Se ha borrado correctamente**\n");
                break;
            case 4:impTHash(P,Num);
                break;
        }
    }while(m!=5);

    return 0;
}

int Menu(){
    int m;
    puts("------------------------------");
    printf("\t***Seleccione una accion***\n");
    printf("1)Consulta\n2)Agregar Pais\n3)Borrar Pais\n");
    printf("4)Imprimir diccionario\n5)Salir\n");
    scanf("%d",&m);
    puts("------------------------------");
    return m;
}

TablaH InicioDic(TablaH P, int n, FILE *Paises){
    Elem e;
    int i;
    for(i=0;i<n;i++){
        e.nombre=(char*)malloc(20);
        e.capital=(char*)malloc(20);
        e.moneda=(char*)malloc(20);
        e.idioma=(char*)malloc(20);
        e.gent=(char*)malloc(20);
        fscanf(Paises,"%s%s%d%s%s%s",e.nombre,e.capital,&e.numHab,e.moneda,e.idioma,e.gent);
        P=insHash(e,P,n);
    }
    return P;
}
