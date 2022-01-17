#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"Semaforos.h"
#include"Util.h"
#include"Archivos.h"
#include"Proveedor.h"

void modificar_producto();
int seleccion_proveedores(int);

int sem_id_proveedor;

int main(int argc, char *argv[]){
    int menu = 0;
    leer_catalogo();
    NumProductos = get_NumProductos();
    sem_id_proveedor = atoi(argv[1]);
    login_proveedor();
    do{
        menu = imp_menu_proveedor();
        seleccion_proveedores(menu);
    }while(menu!=5);

    return 0;
}

void modificar_producto(){
    printf("-------------------------------------------------\n");
    printf("Ingrese el id del producto a modificar: ");
    int pm = leer_int();
    printf("-------------------------------------------------\n");
    if(esta_producto_id(pm)){
        printf("|Seleccione una opcion:%25s|\n","");
        printf("|Modificar nombre: [1]%26s|\n","");
        printf("|Modificar precio: [2]%26s|\n","");
        printf("|Modificar stock: [3]%27s|\n","");
        printf("|No modificar nada: [4]%25s|\n","");
        printf("|-----------------------------------------------|\n");
        printf("Seleccion: ");
        int opcion = leer_int();
        switch(opcion){
            case 1:
                semwait(sem_id_proveedor);
                leer_catalogo();
                modificar_nombre(pm);
                escribir_catalogo();
                semsignal(sem_id_proveedor);
                break;
            case 2:
                semwait(sem_id_proveedor);
                leer_catalogo();
                modificar_precio(pm);
                escribir_catalogo();
                semsignal(sem_id_proveedor);
                break;
            case 3:
                semwait(sem_id_proveedor);
                leer_catalogo();
                modificar_stock(pm);
                escribir_catalogo();
                semsignal(sem_id_proveedor);
                break;
            case 4:
                break;
            default:
                printf("-------------------------------------------------\n");
                printf("|%13s***Opcion no valida***%12s|\n","","");
                break;
        }
    }
    else
        printf("|%10s***El producto no existe***%10s|\n","","");
    printf("-------------------------------------------------\n");

}

int seleccion_proveedores(int n){
    switch(n){
        case 1:
            semwait(sem_id_proveedor);
            leer_catalogo();
            semsignal(sem_id_proveedor);
            mostrar_producto();
            break;
        case 2:
            semwait(sem_id_proveedor);
            leer_catalogo();
            agregar_producto();
            escribir_catalogo();
            semsignal(sem_id_proveedor);
            break;
        case 3:
            modificar_producto();
            break;
        case 4:
            semwait(sem_id_proveedor);
            leer_catalogo();
            imp_todos_productos();
            semsignal(sem_id_proveedor);
            break;
        case 5:
            exit(0);
            break;
        case 59:
        	leer_catalogo();
        	escribir_catalogo();
        case 60:
            leer_catalogo();
            break;
        case 61:
            escribir_catalogo();
            break;
        case 62:
            printf("Numero de productos: %d\n",NumProductos);
            break;
        case 63:
        	leer_catalogo();
            imp_nombres_productos();
            break;
        case 64:
            reset_catalogo();
            break;
        default:
            printf("-------------------------------------------------\n");
            printf("|%13s***Opcion no valida***%12s|\n","","");
            break;
    }
    return 1;
}
