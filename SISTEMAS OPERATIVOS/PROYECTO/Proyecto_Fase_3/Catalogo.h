typedef struct NodoProducto{
    int id_producto;
    char producto_nombre[64];
    Proveedor proveedor;
    int stock;
} Producto;

Producto buscar_producto_nombre(char *);
Producto buscar_producto_id(int);
Producto nuevo_producto(int,char *, Proveedor, int);
int agregar_producto(Producto);
int consultar_stock_producto(Producto);
Producto asignar_stock_producto(Producto, int);
