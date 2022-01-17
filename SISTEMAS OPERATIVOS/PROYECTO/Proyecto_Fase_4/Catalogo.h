
typedef struct NodoProducto{
    int id_producto;
    char producto_nombre[64];
    int precio;
    int stock;
} Producto;

Producto Aux_Productos[64];
Producto Reset_Productos[64];

int NumProductos = 0;

int get_NumProductos(){
	int n = 0;
    for(int i=0 ; i<64 ; i++){
        if(i==0 && i!=Aux_Productos[i].precio)
            n++;
        if(i==Aux_Productos[i].id_producto && i!=0)
        	n++;
    }

    return n;
}

void add_producto(int id, char const *nombre, int price, int stock){
    Aux_Productos[id].id_producto = id;
    Aux_Productos[id].precio = price;
    Aux_Productos[id].stock = stock;
    strcpy(Aux_Productos[id].producto_nombre,nombre);
}

void agregar_producto(){
    int id = get_NumProductos();
    printf("Ingrese el nombre del producto: ");
    char nombre[64];
    fgets(nombre,64,stdin);
    nombre[strlen(nombre)-1] = '\0';
    printf("Ingrese el precio: ");
    int price = leer_int();
    printf("Ingrese el stock inicial: ");
    int stock = leer_int();
    add_producto(id,nombre,price,stock);
    NumProductos = get_NumProductos();
}

int consultar_precio(int id){
    return Aux_Productos[id].precio;
}
int consultar_stock(int id){
    return Aux_Productos[id].stock;
}

void modificar_nombre(int id){
    printf("Ingrese el nuevo nombre del producto: ");
    char nombre_nuevo[64];
    fgets(nombre_nuevo,64,stdin);
    nombre_nuevo[strlen(nombre_nuevo)-1] = '\0';
    strcpy(Aux_Productos[id].producto_nombre,nombre_nuevo);
}

void modificar_precio(int id){
    printf("Ingrese el nuevo precio: ");
    int price = leer_int();
    Aux_Productos[id].precio = price;
}

void modificar_stock(int id){
    printf("Ingrese el stock: ");
    int stock = leer_int();
    Aux_Productos[id].stock = stock;
}

void incrementar_stock(int id, int cantidad){
    Aux_Productos[id].stock += cantidad;
}

void decrementar_stock(int id, int cantidad){
    Aux_Productos[id].stock -= cantidad;
}

void imp_producto(int id){
    printf("ID de producto: %d\n",id);
    printf("Nombre del producto: %s\n",Aux_Productos[id].producto_nombre);
    printf("Precio: %d\n",consultar_precio(id));
    printf("En stock: %d\n",consultar_stock(id));
}

void imp_todos_productos(){
    printf("************************************\n");
    for(int i=0 ; i<get_NumProductos() ; i++){
        imp_producto(i);
        printf("************************************\n");
    }
}

void imp_nombres_productos(){
    for(int i=0 ; i<64 ; i++){
        if(i==0 && i!=Aux_Productos[i].precio)
        	printf("[%s] ",Aux_Productos[i].producto_nombre);
    	if(i==Aux_Productos[i].id_producto && i!=0)
        	printf("[%s] ",Aux_Productos[i].producto_nombre);
    }
    printf("\n");
}