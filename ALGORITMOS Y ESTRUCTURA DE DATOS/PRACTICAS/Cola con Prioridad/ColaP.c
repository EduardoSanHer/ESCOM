//Sandoval Hernández Eduardo - 2020630632
#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"ColaPrior.h"

int Menu();

int main(){
    ColaPrior a=nueva();
    int n,m,p;
    do{
        m=Menu();
        switch (m){
        case 1:
            printf("Ingrese un numero como elemento: ");
            n=LeeElem();
            printf("Ingrese la prioridad del elemento: ");
            p=LeeElem();
            a=formarP(a,n,p);
            break;
        case 2:
            if(!esnueva(a)){
                printf("***Se desformara el primero***\n");
                a=desformar(a);
            }
            break;
        case 3:
            printf("||| Adios |||\n");
            break;
        default:
            printf("\t***Opcion no valida***\n");
            break;
        }

        if(!esnueva(a)){
            printf("------------\nCola:\t");
            ImpColaPrior(a);
            puts("\n------------");
        }
        else
            printf("***Cola vacia***\n");

    }while(m!=3);

    return 0;
}

int Menu(){
    int s;
    printf("Seleccione una accion:\n\t1) Formar elemento\n");
    printf("\t2) Desformar el primero\n\t3) Salir\n");
    scanf("%d",&s);
    return s;
}
