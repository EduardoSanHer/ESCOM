typedef struct NodoCarrito{
    int id_cliente;
    Producto Productos[24];
} Carrito;

Carrito nuevo_carrito(int);
Carrito consultar_carrito(int);
Carrito agregar_producto_carrito(Producto, int);
int guardar_carrito(int,Carrito);