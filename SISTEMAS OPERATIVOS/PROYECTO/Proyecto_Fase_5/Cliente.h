
typedef struct NodoCliente{
    int id_cliente;
    int edad;
    char correo[64];
    char password[64];
    char nombre_s[64];
    char apellido_paterno[64];
    char apellido_materno[64];
    int inuse;
} Cliente;

Cliente Aux[64];
Cliente Reset[64];
Cliente Cliente_Actual;

int NumClientes = 0;

int get_NumClientes(){
	int n = 0;
    for(int i=0 ; i<64 ; i++)
        if(Aux[i].inuse)
            n++;
    return n;
}

void add(int id, int ed, char const *email, char const *pass, char const *name_s, char const *ap, char const *am){
    Aux[id].id_cliente = id;
    Aux[id].edad = ed;
    strcpy(Aux[id].correo,email);
    strcpy(Aux[id].password,pass);
    strcpy(Aux[id].nombre_s,name_s);
    strcpy(Aux[id].apellido_paterno,ap);
    strcpy(Aux[id].apellido_materno,am);
    Aux[id].inuse = 1;
}

const char* get_correo(int id){return Aux[id].correo;}

const char* get_nombre(int id){return Aux[id].nombre_s;}

const char* get_apellidop(int id){return Aux[id].apellido_paterno;}

const char* get_apellidom(int id){return Aux[id].apellido_materno;}

int coincide_password(int id, char const *pass){return strcmp(pass,Aux[id].password)==0;}

int esta_cliente_correo(char const *correo){
    for(int i=0 ; i<64 ; i++){
        if(strcmp(correo,Aux[i].correo)==0)
            return i;
    }
    return -1;
}

void agregar_cliente(){
    printf("-------------------------------------------------\n");
    if(NumClientes<64){
        int id = get_NumClientes();
        printf("Ingrese su edad: ");
        int edad = leer_int();
        printf("Ingrese su nombre(s): ");
        char nombre_s[64];
        fgets(nombre_s,64,stdin);
        nombre_s[strlen(nombre_s)-1] = '\0';
        printf("Ingrese su apellido paterno: ");
        char a_p[64];
        fgets(a_p,64,stdin);
        a_p[strlen(a_p)-1] = '\0';
        printf("Ingrese su apellido materno: ");
        char a_m[64];
        fgets(a_m,64,stdin);
        a_m[strlen(a_m)-1] = '\0';
        printf("Ingrese su correo: ");
        char email[64];
        fgets(email,64,stdin);
        email[strlen(email)-1] = '\0';
        printf("Ingrese su contrasena: ");
        char password[64];
        fgets(password,64,stdin);
        password[strlen(password)-1] = '\0';
        add(id,edad,email,password,nombre_s,a_p,a_m);
        NumClientes = get_NumClientes();
        printf("-------------------------------------------------\n");
        printf("|%13s**Registro completo**%13s|\n","","");
    }
    else
        printf("|%6sSe ha llegado al limite de clientes%6s|\n","","");
    printf("-------------------------------------------------\n");
}

void imp_all_correos(){
    for(int i=0 ; i<64 ; i++)
        if(Aux[i].inuse)
            printf("[%s] \n",Aux[i].correo);
    printf("\n");
}

int iniciar_sesion(){
    char email[64];
    char password[64];
    printf("-------------------------------------------------\n");
    printf("Ingrese su correo: ");
    fgets(email,64,stdin);
    email[strlen(email)-1] = '\0';
    printf("Ingrese su contrasena: ");
    fgets(password,64,stdin);
    password[strlen(password)-1] = '\0';
    printf("-------------------------------------------------\n");
    if(esta_cliente_correo(email)<0)
        printf("|%12s**Correo no registrado**%11s|\n","","");
    else if(!coincide_password(esta_cliente_correo(email),password))
        printf("|%11s**Contrasena incorrecta**%11s|\n","","");
    else{
        printf("|%10s**Inicio de sesion exitoso**%9s|\n","","");
        Cliente_Actual = Aux[esta_cliente_correo(email)];
        printf("|ID de cliente actual: %25d|\n",Cliente_Actual.id_cliente);
        printf("-------------------------------------------------\n");
        return 1;
    }
    printf("-------------------------------------------------\n");
    return 0;
}