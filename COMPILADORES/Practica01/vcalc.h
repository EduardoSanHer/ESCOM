/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 1                      |
    |   Tema: Yacc básico                       |
    |   Opcion: Calculadora de vectores         |
    |   Fecha de entrega: 18 de marzo de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/
struct vector {                                 // Estructura del vector
    char name;
    int n;
    double *vec;
};
typedef struct vector Vector;
Vector *creaVector(int n);                      // Crea un vector
void imprimeVector(Vector *a);                  // Imprime en pantalla un vector
Vector *copiaVector(Vector *a);                 // Copia un vector
Vector *sumaVector(Vector *a, Vector *b);       // Suma dos vectores
Vector *restaVector(Vector *a, Vector *b);      // Resta dos vectores
Vector *escalarVector(double c, Vector *v);     // Multiplica un escar por un vector
Vector *productoCruz(Vector *a, Vector *b);     // Producto cruz entre dos vectores
double productoPunto(Vector *a, Vector *b);     // Producto punto entre dos vectores
double vectorMagnitud(Vector *a);               // Obtiene la magnitud de un vector