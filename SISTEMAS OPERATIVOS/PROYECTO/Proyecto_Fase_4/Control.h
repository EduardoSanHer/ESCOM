int NumClientesAtendidos;
int NumProveedoresAtendidos;
int id_sem_cliente;
char string_sem_cliente[20];
int id_sem_carrito;
char string_sem_carrito[20];
int id_sem_catalogo;
char string_sem_catalogo[20];
int id_sem_proveedor;
char string_sem_proveedor[20];

int imp_menu_control(){
    printf("**Bienvenido al sistema**\n");
    printf("***\tMenu de control\t***\n");
    printf("Seleccione una opcion:\n");
    printf("Clientes: [1]\n");
    printf("Proveedores: [2]\n");
    printf("Salir: [3]\n");
    int s;
    scanf("%d",&s);
    return s;
}

int atender_cliente(){
	NumClientesAtendidos++;
    printf("Clientes atendidos: %d\n",NumClientesAtendidos);
    if(fork() == 0){ 
        // Child process will return 0 from fork()
        //printf("I'm the child process.\n");
        sprintf(string_sem_cliente,"%d",id_sem_cliente);
        sprintf(string_sem_carrito,"%d",id_sem_carrito);
        sprintf(string_sem_catalogo,"%d",id_sem_catalogo);
    	//printf("Sem ID cliente: %d\n",id_sem_cliente);
        int err = execlp("gnome-terminal","gnome-terminal","--","./Cliente",string_sem_cliente,string_sem_carrito,string_sem_catalogo,(char*)NULL);
    }
}

int atender_proveedor(){
	NumProveedoresAtendidos++;
    printf("Proveedores atendidos: %d\n",NumProveedoresAtendidos);
    if(fork() == 0){
        // Child process will return 0 from fork()
        //printf("I'm the child process.\n");
        sprintf(string_sem_proveedor,"%d",id_sem_proveedor);
    	//printf("Sem ID proveedor: %d\n",id_sem_proveedor);
        int err = execlp("gnome-terminal","gnome-terminal","--","./Proveedor",string_sem_proveedor,(char*)NULL);
    }
}

int seleccion(int n){
    switch(n){
        case 1:
            atender_cliente();
            break;
        case 2:
            atender_proveedor();
            break;
        case 3:
            ereasesem(id_sem_proveedor);
            ereasesem(id_sem_cliente);
            exit(0);
            break;
        default:
            puts("***Opcion no valida***");
            break;
    }
    return 1;
}
