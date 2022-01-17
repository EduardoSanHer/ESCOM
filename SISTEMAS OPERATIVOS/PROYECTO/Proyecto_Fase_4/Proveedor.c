#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"Semaforos.h"
#include"Util.h"
#include"Proveedor.h"
#include"Archivos.h"

void modificar_producto();
int seleccion_proveedores(int);

int sem_id_proveedor;

int main(int argc, char *argv[]){
    int menu = 0;
    leer_catalogo();
    NumProductos = get_NumProductos();
    //sem_id_proveedor = createsem(0x0234,1);
    sem_id_proveedor = atoi(argv[1]);
    //printf("Sem id: %d\n",sem_id_proveedor);
    login_proveedor();
    do{
        menu = imp_menu_proveedor();
        seleccion_proveedores(menu);
    }while(menu!=4);

    return 0;
}

void modificar_producto(){
    printf("Ingrese el id del producto a modificar: ");
    int pm = leer_int();
    printf("Seleccione una opcion:\n");
    printf("Modificar nombre: [1]\n");
    printf("Modificar precio: [2]\n");
    printf("Modificar stock: [3]\n");
    printf("No modificar nada: [4]\n");
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
            puts("***Opcion no valida***");
            break;
    }

}

int seleccion_proveedores(int n){
    switch(n){
        case 1:
            semwait(sem_id_proveedor);
            leer_catalogo();
            semsignal(sem_id_proveedor);
            printf("Ingrese el id del producto: ");
            int a_id = leer_int();
            imp_producto(a_id);
            break;
        case 2:
            semwait(sem_id_proveedor);
            leer_catalogo();
            agregar_producto();
            escribir_catalogo();
            semsignal(sem_id_proveedor);
            printf("Se ha agregado el producto con ID: %d\n",NumProductos-1);
            break;
        case 3:
            modificar_producto();
            break;
        case 4:
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
            puts("***Opcion no valida***");
            break;
    }
    return 1;
}
