#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"Semaforos.h"
#include"Util.h"
#include"Archivos.h"

int imp_menu_cliente();
void imp_productos_carrito(int);
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
    //sem_id_cliente = createsem(0x1234,1);
    sem_id_cliente = atoi(argv[1]);
    sem_id_carrito = atoi(argv[2]);
    sem_id_catalogo = atoi(argv[3]);
    //printf("Sem id: %d\n",sem_id_cliente);
    do{
        menu = imp_menu_cliente();
        seleccion_cliente(menu);
    }while(menu!=3);

    return 0;
}

int imp_menu_cliente(){
    printf("***\tMenu de clientes\t***\n");
    printf("Seleccione una opcion:\n");
    printf("Registrar Cliente: [1]\n");
    printf("Iniciar sesion: [2]\n");
    printf("Salir: [3]\n");
    return leer_int();
}

void imp_productos_carrito(int id_cliente){
    int n = Aux_Carrito[id_cliente].Num_Productos_Carrito;
    if(n>0)
        printf("************************************\n");
    for(int i=0 ; i<n ; i++){
        imp_producto(Aux_Carrito[id_cliente].id_productos[i]);
        printf("************************************\n");
    }
}

int imp_segundo_menu_cliente(){
    printf("***\tMenu de cliente\t***\n");
    printf("Seleccione una opcion:\n");
    printf("Mostrar productos: [1]\n");
    printf("Agregar producto al carrito: [2]\n");
    printf("Mostrar productos en el carrito: [3]\n");
    printf("Salir: [4]\n");
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
            imp_productos_carrito(Cliente_Actual.id_cliente);
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
            imp_productos_carrito(Cliente_Actual.id_cliente);
            break;
        case 64:
            reset_carritos();
            break;
        default:
            puts("***Opcion no valida***");
            break;
    }

}

int seleccion_cliente(int n){
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
            printf("Se ha agregado al cliente con correo: [%s]\n",get_correo(NumClientes-1));
            break;
        case 2:
            leer_clientes();
            iniciar_sesion();
            int sub_menu = 0;
            do{
                sub_menu = imp_segundo_menu_cliente();
                seleccion_accion_cliente(sub_menu);
            }while(sub_menu!=4);
        case 3:
            exit(0);
            break;
        case 59:
        	leer_clientes();
        	escribir_clientes();
        case 60:
            leer_clientes();
            break;
        case 61:
            escribir_clientes();
            break;
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
            puts("***Opcion no valida***");
            break;
    }

    return 1;
}