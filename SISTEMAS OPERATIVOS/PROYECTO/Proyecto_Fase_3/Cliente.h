typedef struct NodoCliente{
    int id_cliente;
    int edad;
    char correo[64];
    char password[64];
    char nombre_nombres[64];
    char apellido_paterno[64];
    char apellido_materno[64];
} Cliente;

Cliente buscar_cliente_id(int);
Cliente buscar_cliente_correo(char *)
Cliente nuevo_cliente(int, int, char *, char *, char *, char *, char *);
int agregar_cliente(Cliente);
Cliente iniciar_sesion(char *, char *);