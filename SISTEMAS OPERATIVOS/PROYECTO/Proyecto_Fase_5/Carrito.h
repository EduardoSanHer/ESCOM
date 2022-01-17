typedef struct NodoCarrito{
    int id_cliente;
    int Num_Productos_Carrito;
    int id_productos[64];
    int cant_productos_por_id[64];
    int inuse;
} Carrito;

Carrito Aux_Carrito[64];
Carrito Reset_Carrito[64];
Carrito Set_Carrito[64];

void add_carrito(int id){
    Aux_Carrito[id].id_cliente = id;
    Aux_Carrito[id].inuse = 1;
}

int get_Num_Productos_Carrito(int id){
    return Aux_Carrito[id].Num_Productos_Carrito;
}

void add_producto_carrito(int id_cliente){
    int stock_disponible, id_producto, cantidad;
    printf("-------------------------------------------------\n");
    printf("Ingrese el ID del producto: ");
    id_producto = leer_int();
    printf("-------------------------------------------------\n");
    if(!esta_producto_id(id_producto))
        printf("|%10s***El producto no existe***%10s|\n","","");
    else{
        printf("|Ingrese la cantidad que desea comprar: ");
        cantidad = leer_int();
        stock_disponible = consultar_stock(id_producto);
        if(stock_disponible<cantidad){
            printf("-------------------------------------------------\n");
            printf("|%12s**Stock insuficiente**%13s|\n","","");
        }
        else{
            int id_aux = Aux_Carrito[id_cliente].Num_Productos_Carrito;
            Aux_Carrito[id_cliente].id_productos[id_aux] = id_producto;
            Aux_Carrito[id_cliente].Num_Productos_Carrito++;
            Aux_Carrito[id_cliente].cant_productos_por_id[id_aux] = cantidad;
            //imp_producto(Aux_Carrito[id_cliente].id_productos[id_aux]);
            decrementar_stock(id_producto,cantidad);
            printf("-------------------------------------------------\n");
            printf("|%13s**Producto agregado**%13s|\n","","");
        }
    }
    printf("-------------------------------------------------\n");
}

void imp_productos_en_carrito(int id_cliente){
    printf("-------------------------------------------------\n");
    printf("|%6s**Productos actualmente en carrito**%5s|\n","","");
    int n = Aux_Carrito[id_cliente].Num_Productos_Carrito;
    if(n>0){
        for(int i=0 ; i<n ; i++){
            printf("|-----------------------------------------------|\n");
            printf("|ID de producto: %29d%2s|\n",Aux_Carrito[id_cliente].id_productos[i],"");
            printf("|Nombre del producto: %24s%2s|\n",Aux_Productos[Aux_Carrito[id_cliente].id_productos[i]].producto_nombre,"");
            printf("|Precio: %37d%2s|\n",consultar_precio(Aux_Carrito[id_cliente].id_productos[i]),"");
            printf("|Cantidad: %35d%2s|\n",Aux_Carrito[id_cliente].cant_productos_por_id[i],"");
        }
        printf("|-----------------------------------------------|\n");
    }
    else{
        printf("|-----------------------------------------------|\n");
        printf("|%8sNo hay productos en el carrito%9s|\n","","");
        printf("|-----------------------------------------------|\n");

    }
    printf("-------------------------------------------------\n");
}