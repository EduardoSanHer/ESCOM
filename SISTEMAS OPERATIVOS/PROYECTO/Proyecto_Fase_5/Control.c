#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"Semaforos.h"
#include"Control.h"

int main(){
	id_sem_cliente = createsem(0x1234,1);
	id_sem_proveedor = createsem(0x0234,1);
	id_sem_carrito = createsem(0x0034,1);
	id_sem_catalogo = createsem(0x0004,1);
    int menu;
    do{
        menu = imp_menu_control();
        seleccion(menu);
    }while(menu!=3);

    return 0;
}