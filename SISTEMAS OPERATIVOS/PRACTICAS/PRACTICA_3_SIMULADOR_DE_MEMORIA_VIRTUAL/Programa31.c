#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

void imprimir_direcciones_virtuales(Tabla);
void imprimir_direcciones_fisicas(Tabla);
Tabla agregar_a_ram(int,Tabla);
void mensaje_agregado(int,int);

void main () {

    Tabla T = vacia();

    int menu = 0, id_Pagina_Agregar = -1;

    printf("***Simulador de memoria virtual y fisica***\n");
    //imprimir_direcciones_virtuales(T);
    //imprimir_direcciones_fisicas(T);

    while(menu!=4){
        printf("-------------------------------------------------\n");
        printf("|Seleccione una opcion:%25s|\n"," ");
        printf("-------------------------------------------------\n");
        printf("|1) Agregar Pagina a RAM %24s\n|2) Mostrar tabla de direcciones virtuales %6s\n","|","|");
        printf("|3) Mostrar tabla de direcciones fisicas %8s\n|4) Salir %39s\n","|","|");
        printf("-------------------------------------------------\n");
        printf("Su eleccion: ");

        do{
            scanf("%i",&menu);
        }while(menu<1 || menu>4);
        printf("-------------------------------------------------\n");

        switch(menu){
            case 1:
                printf("Ingrese el ID de la pagina (0,15): ");
                do{
                    scanf("%i",&id_Pagina_Agregar);
                }while(id_Pagina_Agregar<0 || id_Pagina_Agregar>15);
                T = agregar_a_ram(id_Pagina_Agregar,T);
                break;
            case 2:
                imprimir_direcciones_virtuales(T);
                break;
            case 3:
                imprimir_direcciones_fisicas(T);
                break;
            case 4:
                printf("***SALIENDO***\n");
                break;
        }
    }

}

void imprimir_direcciones_virtuales(Tabla T){
    Tabla temp = NULL;
    printf("\t----------------------------------------\n");
    printf("\t|    Espacio de direcciones virtual    |\n");
    printf("\t----------------------------------------\n");
    printf("\t| ID de pagina | ID de marco de pagina |\n");
    for(int i=15; i>=0; i--){
        temp = id_Pagina_EstaEn(i,T);
        
        if(id_Pagina_EstaEn(i,T))
            printf("\t| %12i | %21i |\n",i, temp->id_Marco);
        else
            printf("\t| %12i | %21s |\n",i, "X");
    }
    printf("\t----------------------------------------\n");
}

void imprimir_direcciones_fisicas(Tabla T){
    printf("\t----------------------------------------\n");
    printf("\t|    Espacio de direcciones fisico     |\n");
    printf("\t----------------------------------------\n");
    printf("\t| ID de pagina | ID de marco de pagina |\n");
    while(!esvacia(T)){
        printf("\t| %12i | %21i |\n",T->id_Pagina, T->id_Marco);
        T = pop(T);
    }
    printf("\t----------------------------------------\n");
}

Tabla agregar_a_ram(int id_Pagina, Tabla T){
    int Num_ids_en_Tabla = NumElems(T);

    if(!esvacia(T) && id_Pagina_EstaEn(id_Pagina,T)){
        printf("\t--------------------------------------\n");
        printf("\t|La pagina ya se encuentra en la RAM |\n");
        printf("\t--------------------------------------\n");
        return T;
    }
    else if(Num_ids_en_Tabla == 8){
        Tabla temp = vacia();
        for(int i=1; i<8; i++){
            temp = agregar(obtener_id_Pagina(T),obtener_id_Marco(T),temp);
            T = pop(T);
        }
        temp = InvierteTabla(temp);

        int aux = obtener_id_Marco(temp), id_Marco;
        //printf("El aux es : %i\n",aux);
        if(aux==7)
            id_Marco = 0;
        else
            id_Marco = aux + 1;
        //printf("El id marco es : %i\n",id_Marco);

        temp = agregar(id_Pagina,id_Marco,temp);
        mensaje_agregado(id_Pagina,id_Marco);
        return temp;
    }
    else{
        mensaje_agregado(id_Pagina,Num_ids_en_Tabla);
        return agregar(id_Pagina,Num_ids_en_Tabla,T);
    }
}

void mensaje_agregado(int id_Pagina, int id_Marco){
    printf("\t-------------------------------------------------------------\n");
    printf("\t| La pagina con ID: %i\tSe ha agregado a la RAM con ID: %i  |\n",id_Pagina,id_Marco);
    printf("\t-------------------------------------------------------------\n");
}
