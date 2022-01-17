#define PIN_Proveedores 741963

int login_proveedor(){
    printf("Introduzca el pin unico de proveedores: ");
    int p = 0;
    while(p!=PIN_Proveedores){
        p = leer_int();
        if(p!=PIN_Proveedores){
            printf("**PIN Incorrecto**\n");
            printf("Introduzca de nuevo el pin: ");
        }
        if(p==3)
            exit(0);
    }
    return 1;    
}

int imp_menu_proveedor(){
    printf("***\tMenu de proveedores\t***\n");
    printf("Seleccione una opcion:\n");
    printf("Buscar producto por id: [1]\n");
    printf("Agregar producto: [2]\n");
    printf("Modificar producto: [3]\n");
    printf("Salir: [4]\n");
    return leer_int();
}
/*
typedef struct NodoProveedor{
    int id_proveedor;
    char correo[64];
    char nombre[64];
} Proveedor;

Proveedor obtener_id(int);
Proveedor nuevoProveedor(int,char *,char *);¨
*/