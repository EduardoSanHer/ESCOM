#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"Semaforos.h"
#include"Util.h"
#include"Archivos.h"

int imp_menu_cliente();
int imp_segundo_menu_cliente();
void seleccion_accion_cliente(int s);
int seleccion_cliente(int);

int sem_id_cliente;
int sem_id_carrito;
int sem_id_catalogo;

int main(int argc, char *argv[]){
    int menu = 0;
    leer_clientes();
    leer_carritos();
    leer_catalogo();
    NumClientes = get_NumClientes();
    sem_id_cliente = atoi(argv[1]);
    sem_id_carrito = atoi(argv[2]);
    sem_id_catalogo = atoi(argv[3]);
    do{
        menu = imp_menu_cliente();
        seleccion_cliente(menu);
    }while(menu!=3);

    return 0;
}

int imp_menu_cliente(){
    printf("-------------------------------------------------\n");
    printf("|%13s***Menu de clientes***%12s|\n","","");
    printf("|-----------------------------------------------|\n");
    printf("|Seleccione una opcion:%25s|\n","");
    printf("|Registrar Cliente: [1]%25s|\n","");
    printf("|Iniciar sesion: [2]%28s|\n","");
    printf("|Salir: [3]%37s|\n","");
    printf("-------------------------------------------------\n");
    printf("Seleccion: ");
    return leer_int();
}

int imp_segundo_menu_cliente(){
    printf("-------------------------------------------------\n");
    printf("|%13s***Menu de cliente***%13s|\n","","");
    printf("|-----------------------------------------------|\n");
    printf("|Seleccione una opcion:%25s|\n","");
    printf("|Mostrar productos: [1]%25s|\n","");
    printf("|Agregar producto al carrito: [2]%15s|\n","");
    printf("|Mostrar productos en el carrito: [3]%11s|\n","");
    printf("|Salir: [4]%37s|\n","");
    printf("-------------------------------------------------\n");
    printf("Seleccion: ");
    return leer_int();
}

void seleccion_accion_cliente(int s){
    switch(s){
        case 1:
            semwait(sem_id_catalogo);
            leer_catalogo();
            imp_todos_productos();
            semsignal(sem_id_catalogo);
            break;
        case 2:
            semwait(sem_id_carrito);
            leer_carritos();
            semwait(sem_id_catalogo);
            leer_catalogo();
            add_producto_carrito(Cliente_Actual.id_cliente);
            escribir_catalogo();
            semsignal(sem_id_catalogo);
            escribir_carritos();
            semsignal(sem_id_carrito);
            break;
        case 3:
            semwait(sem_id_carrito);
            leer_carritos();
            imp_productos_en_carrito(Cliente_Actual.id_cliente);
            semsignal(sem_id_carrito);
            break;
        case 4:
            exit(0);
            break;
        case 59:
        	leer_carritos();
        	escribir_carritos();
        case 60:
            leer_carritos();
            break;
        case 61:
            escribir_carritos();
            break;
        case 62:
            set_carritos();
            break;
        case 63:
        	leer_carritos();
            imp_productos_en_carrito(Cliente_Actual.id_cliente);
            break;
        case 64:
            reset_carritos();
            break;
        default:
            printf("-------------------------------------------------\n");
            printf("|%13s***Opcion no valida***%12s|\n","","");
            break;
    }

}

int seleccion_cliente(int n){
    int r = 0;
    switch(n){
        case 1:
            semwait(sem_id_cliente);
            leer_clientes();
            agregar_cliente();
            escribir_clientes();
            semsignal(sem_id_cliente);
            semwait(sem_id_carrito);
            leer_carritos();
            add_carrito(NumClientes-1);
            escribir_carritos();
            semsignal(sem_id_carrito);
            break;
        case 2:
            leer_clientes();
            do{
                r = iniciar_sesion();
            }while(!r);
            int sub_menu = 0;
            do{
                sub_menu = imp_segundo_menu_cliente();
                seleccion_accion_cliente(sub_menu);
            }while(sub_menu!=4);
        case 3:
            exit(0);
            break;
        case 61:
        	leer_clientes();
        	escribir_clientes();
        case 62:
            printf("Numero de clientes: %d\n",NumClientes);
            break;
        case 63:
        	leer_clientes();
            imp_all_correos();
            break;
        case 64:
            reset_clientes();
            break;
        case 100:
            reset_all();
            break;
        default:
            printf("-------------------------------------------------\n");
            printf("|%13s***Opcion no valida***%12s|\n","","");
            break;
    }

    return 1;
}