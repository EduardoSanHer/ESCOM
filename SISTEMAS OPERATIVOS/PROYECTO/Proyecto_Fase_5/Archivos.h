#include"Catalogo.h"
#include"Carrito.h"
#include"Cliente.h"

// Archivo de clientes
int escribir_clientes(){
    FILE *archivo;
    archivo = fopen("Archivo_Clientes","wb");
    if(archivo){
        fwrite(Aux,sizeof(struct NodoCliente),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int leer_clientes(){
    FILE *archivo;
    archivo = fopen("Archivo_Clientes","rb");
    if(archivo){
        fread(Aux,sizeof(struct NodoCliente),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int reset_archivo_clientes(){
    FILE *archivo;
    archivo = fopen("Archivo_Clientes","wb");
    if(archivo){
        fwrite(Reset,sizeof(struct NodoCliente),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int reset_clientes(){
    reset_archivo_clientes();
    leer_clientes();
    return 1;    
}
//***********************************************************

//Archivo de catalogo (productos)
int escribir_catalogo(){
    FILE *archivo;
    archivo = fopen("Archivo_Catalogo","wb");
    if(archivo){
        fwrite(Aux_Productos,sizeof(struct NodoProducto),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int leer_catalogo(){
    FILE *archivo;
    archivo = fopen("Archivo_Catalogo","rb");
    if(archivo){
        fread(Aux_Productos,sizeof(struct NodoProducto),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int reset_archivo_catalogo(){
    FILE *archivo;
    archivo = fopen("Archivo_Catalogo","wb");
    if(archivo){
        fwrite(Reset_Productos,sizeof(struct NodoProducto),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int reset_catalogo(){
    reset_archivo_catalogo();
    leer_catalogo();
    return 1;    
}
//***********************************************************

//Archivo de carritos

int escribir_carritos(){
    FILE *archivo;
    archivo = fopen("Archivo_Carritos","wb");
    if(archivo){
        fwrite(Aux_Carrito,sizeof(struct NodoCarrito),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int leer_carritos(){
    FILE *archivo;
    archivo = fopen("Archivo_Carritos","rb");
    if(archivo){
        fread(Aux_Carrito,sizeof(struct NodoCarrito),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int reset_archivo_carritos(){
    FILE *archivo;
    archivo = fopen("Archivo_Carritos","wb");
    if(archivo){
        fwrite(Reset_Carrito,sizeof(struct NodoCarrito),64,archivo);
        fclose(archivo);
    }
    return 1;
}

int reset_carritos(){
    reset_archivo_carritos();
    leer_carritos();
    return 1;    
}

int set_archivo_carritos(){
    for(int i=0 ; i<get_NumClientes() ; i++)
        Set_Carrito[i].id_cliente = i;
    FILE *archivo;
    archivo = fopen("Archivo_Carritos","wb");
    if(archivo){
        fwrite(Set_Carrito,sizeof(struct NodoCarrito),64,archivo);
        fclose(archivo);
    }
    return 1;

}

int set_carritos(){
    set_archivo_carritos();
    leer_carritos();
    return 1;    
}
//***********************************************************

int reset_all(){
    reset_archivo_clientes();
    leer_clientes();
    reset_archivo_catalogo();
    leer_catalogo();
    reset_archivo_carritos();
    leer_carritos();
    return 1;
}