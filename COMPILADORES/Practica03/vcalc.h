/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 3                      |
    |   Tema: Tabla de símbolos HOC3            |
    |   Opcion: Calculadora de vectores         |
    |   Fecha de entrega: 29 de abril de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/

/*|----------------------------------------------------|*/
/*|                 Estructura del vector              |*/
/*|----------------------------------------------------|*/
struct vector {                                 // Estructura del vector
    char name;
    int n;
    double *vec;
};
typedef struct vector Vector;

/*|----------------------------------------------------|*/
/*|                Tabla de símbolos                   |*/
/*|----------------------------------------------------|*/
typedef struct Symbol {                         // Tabla de símbolos
	char   *name;
	short   type;                               // VAR, BLTIN, INDEF
	union {
		Vector *val;                            // Si es VAR
		double  (*ptr)();                       // Si es BLTIN
	} u;
	struct Symbol   *next;                      // Ligado al siguiente símbolo
} Symbol;

/*|----------------------------------------------------|*/
/*|        Funciones para la tabla de símbolos         |*/
/*|----------------------------------------------------|*/
Symbol *install(char *s, int t, Vector *d);     // Funcion para ingresar un simbolo a la tabla de simbolos
Symbol *lookup(char *s);                        // Funcion para buscar un simbolo en la tabla de simbolos

/*|----------------------------------------------------|*/
/*|            Funciones para los vectores             |*/
/*|----------------------------------------------------|*/
Vector *creaVector(int n);                      // Crea un vector
void imprimeVector(Vector *a);                  // Imprime en pantalla un vector
Vector *copiaVector(Vector *a);                 // Copia un vector
Vector *uneVector(Vector *a, Vector *b);        // Une dos vectores
Vector *sumaVector(Vector *a, Vector *b);       // Suma dos vectores
Vector *restaVector(Vector *a, Vector *b);      // Resta dos vectores
Vector *escalarVector(double c, Vector *v);     // Multiplica un escar por un vector
Vector *productoCruz(Vector *a, Vector *b);     // Producto cruz entre dos vectores
double productoPunto(Vector *a, Vector *b);     // Producto punto entre dos vectores
double vectorMagnitud(Vector *a);               // Obtiene la magnitud de un vector