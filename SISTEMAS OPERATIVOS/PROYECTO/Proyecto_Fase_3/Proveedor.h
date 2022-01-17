typedef struct NodoProveedor{
    int id_proveedor;
    char correo[64];
    char nombre[64];
} Proveedor;

Proveedor obtener_id(int);
Proveedor nuevoProveedor(int,char *,char *);