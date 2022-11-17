/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 5                      |
    |   Tema: Decisiones y ciclos HOC5          |
    |   Opcion: Calculadora de vectores         |
    |   Fecha de entrega: 10 de junio de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/
// La practica se presento presencialmente el 30 de mayo de 2022

/*|----------------------------------------------------|*/
/*|                 Librerias                          |*/
/*|----------------------------------------------------|*/

#include<string.h>

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
        double doublenumber;                             
	} u;
	struct Symbol   *next;                      // Ligado al siguiente símbolo
} Symbol;


/*|----------------------------------------------------|*/
/*|        Funciones para la tabla de símbolos         |*/
/*|----------------------------------------------------|*/
Symbol *installVector(char *s, int t, Vector *d);   // Funcion para ingresar un simbolo a la tabla de simbolos
Symbol *installDouble(char *s, int t, double d);   // Funcion para ingresar un simbolo a la tabla de simbolos
Symbol *lookup(char *s);                            // Funcion para buscar un simbolo en la tabla de simbolos
int init();

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

/*|----------------------------------------------------|*/
/*|   Funciones para la máquina virtual de pila        |*/
/*|----------------------------------------------------|*/
typedef union Datum{
    Vector* val;
    double doublenumber;
    Symbol* sym;
    int eval;
}Datum;

Datum pop();
typedef void (*Inst)();

#define STOP (Inst) 0
Inst prog[];
void assign();
void varpush();
void constpushvector();
void constpushdouble();
void printVector();
void printDouble();
void eval();
void add();
void sub();
void mulCruz();
void mulPunto();
void get_magnitude();
void escalarXvector();
void vectorXescalar();

/*|----------------------------------------------------|*/
/*|        Funciones de comparacion practica 5         |*/
/*|----------------------------------------------------|*/

void MayorQue();
void MayorIgualQue();
void MenorQue();
void MenorIgualQue();
void IgualQue();
void NoIgualQue();
void And();
void Or();
void Not();
void whilecode();
void ifcode();
void bltin();
