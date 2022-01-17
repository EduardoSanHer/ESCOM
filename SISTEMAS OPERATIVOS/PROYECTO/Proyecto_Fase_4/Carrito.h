typedef struct NodoCarrito{
    int id_cliente;
    int Num_Productos_Carrito;
    int id_productos[64];
} Carrito;

Carrito Aux_Carrito[64];
Carrito Reset_Carrito[64];
Carrito Set_Carrito[64];

void add_carrito(int id){
    Aux_Carrito[id].id_cliente = id;
}

int get_Num_Productos_Carrito(int id){
    return Aux_Carrito[id].Num_Productos_Carrito;
}

void add_producto_carrito(int id_cliente){
    int stock_disponible, id_producto, cantidad;
    printf("Ingrese el ID del producto que desea agregar al carrito: ");
    id_producto = leer_int();
    printf("Ingrese la cantidad del producto que desea comprar: ");
    cantidad = leer_int();
    stock_disponible = consultar_stock(id_producto);
    if(stock_disponible<cantidad)
        printf("**Stock insuficiente**\n");
    else if(NumProductos>id_producto)
        printf("**Articulo inexistente**\n");
    else{
        int id_aux = Aux_Carrito[id_cliente].Num_Productos_Carrito;
        Aux_Carrito[id_cliente].id_productos[id_aux] = id_producto;
        Aux_Carrito[id_cliente].Num_Productos_Carrito++;
        imp_producto(Aux_Carrito[id_cliente].id_productos[id_aux]);
        decrementar_stock(id_producto,cantidad);
    }
}
/*
Carrito nuevo_carrito(int);
Carrito consultar_carrito(int);
Carrito agregar_producto_carrito(Producto, int);
int guardar_carrito(int,Carrito);
*/