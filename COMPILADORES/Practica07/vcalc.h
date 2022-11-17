/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 7                      |
    |   Tema: Funciones y procedimientos HOC6   |
    |   Opcion: Calculadora de vectores         |
    |   Fecha de entrega: 11 de junio de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/

#ifndef VECTOR_H
#define VECTOR_H

/*|----------------------------------------------------|*/
/*|                Librerías de C                      |*/
/*|----------------------------------------------------|*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

#endif