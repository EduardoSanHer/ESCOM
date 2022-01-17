#define PIN_Proveedores 741963

int login_proveedor(){
    printf("-------------------------------------------------\n");
    printf("Introduzca el pin unico de proveedores: ");
    int p = 0;
    while(p!=PIN_Proveedores){
        p = leer_int();
        if(p!=PIN_Proveedores){
            printf("|%15s**PIN Incorrecto**%14s|\n","","");
            printf("Introduzca de nuevo el pin: ");
        }
        if(p==3)
            exit(0);
    }
    printf("-------------------------------------------------\n");
    return 1;    
}

int imp_menu_proveedor(){
    printf("-------------------------------------------------\n");
    printf("|%11s***Menu de proveedores***%11s|\n","","");
    printf("|-----------------------------------------------|\n");
    printf("|Seleccione una opcion:%25s|\n","");
    printf("|Buscar producto por id: [1]%20s|\n","");
    printf("|Agregar producto: [2]%26s|\n","");
    printf("|Modificar producto: [3]%24s|\n","");
    printf("|Mostrar productos: [4]%25s|\n","");
    printf("|Salir: [5]%37s|\n","");
    printf("-------------------------------------------------\n");
    printf("Seleccion: ");
    return leer_int();
}

void mostrar_producto(){
    printf("-------------------------------------------------\n");
    printf("|Ingrese el id del producto: ");
    int id = leer_int();
    printf("-------------------------------------------------\n");
    if(esta_producto_id(id)){
        imp_producto(id);
        printf("|-----------------------------------------------|\n");
    }
    else
        printf("|%10s***El producto no existe***%10s|\n","","");
    printf("-------------------------------------------------\n");

}