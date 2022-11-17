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

/*|----------------------------------------------------|*/
/*|                Librerías de C                      |*/
/*|----------------------------------------------------|*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "vcalc.h"         // Librería para los prototipos de las funciones

/*|----------------------------------------------------|*/
/*|                     Funciones                      |*/
/*|----------------------------------------------------|*/

/*|----------------------------------------------------|*/
/*  
    Función que crea un vector de n dimensiones,
    recibe como parámetro el número de dimensiones
    y retorna el vector con dichas dimensiones.
*/
/*|----------------------------------------------------|*/
Vector *creaVector(int n){
   Vector *vec;
   int i;
   vec=(Vector *)malloc(sizeof(Vector));
   vec->n = n;
   vec->vec = (double *)malloc(sizeof(double)*n);
   return vec;
}

/*|----------------------------------------------------|*/
/*  
    Función que imprime en pantalla los elementos
    dentro del vector, recibe como parámetro un vector.
*/
/*|----------------------------------------------------|*/
void imprimeVector(Vector *v){
    int i;
    printf("\tResultado: [ ");
    for(i=0; i< v->n; i++)
        printf("%f ", v->vec[i]);
    printf("]\n");
}

/*|----------------------------------------------------|*/
/*
    Función que crea una copia del contenido del
    vector que se le envía como parámetro, 
    retornando la copia.
*/
/*|----------------------------------------------------|*/
Vector *copiaVector(Vector *v){
    int i;
    Vector *copy=creaVector(v->n);
    for(i = 0; i< v->n; i++)
        copy->vec[i]=v->vec[i];
    return copy;
}

/*|----------------------------------------------------|*/
/*
    Función que recibe como parámetros dos vectores
    para sumar sus componentes y retornar un vector
    nuevo con el resultado.
*/
/*|----------------------------------------------------|*/
Vector *sumaVector(Vector *a, Vector *b){
    Vector *c;
    int i;
    c=creaVector(a->n);
    for(i=0; i< a->n;i++)
        c->vec[i]=a->vec[i]+b->vec[i];
    return c;
}

/*|----------------------------------------------------|*/
/*
    Función que recibe como parámetros dos vectores
    para restar sus componentes y retornar un vector
    nuevo con el resultado.
*/
/*|----------------------------------------------------|*/
Vector *restaVector(Vector *a, Vector *b){
    Vector *c;
    int i;
    c=creaVector(a->n);
    for(i=0; i< a->n;i++)
        c->vec[i]=a->vec[i]-b->vec[i];
    return c;
}

/*|----------------------------------------------------|*/
/*
    Función que recibe como parámetros un vector
    y un escalar para multiplicar cada uno de los
    componentes del vector por el escalar, retornando
    un vector nuevo con el resultado.
*/
/*|----------------------------------------------------|*/
Vector  *escalarVector(double c, Vector *v){
    Vector *r_vector = creaVector(v -> n);
    int i;
    for(i = 0; i < v -> n; i++)
        r_vector -> vec[i] = c * v->vec[i];   
    return r_vector;
}

/*|----------------------------------------------------|*/
/*
    Función que recibe como parámetros dos vectores
    para realizar el producto cruz entre ellos,
    retornando un vector nuevo con el resultado.
*/
/*|----------------------------------------------------|*/
Vector *productoCruz(Vector *a, Vector *b){
    Vector *r;
    r = creaVector(a -> n);
  
    //  Para vectores de 2 dimensiones
    if(a-> n == 2){
        r -> vec[0] = a -> vec[0] * b ->vec[1];
        r -> vec[1] -= a -> vec[1] * b -> vec[0]; 
    } 
    //  Para vectores de 3 dimensiones
    else if(a -> n == 3){
        r -> vec[0] = a -> vec[1] * b -> vec[2] 
            - a -> vec[2] * b -> vec[1];
            
        r -> vec[1] = a -> vec[2] * b -> vec[0]
            - a -> vec[0] * b -> vec[2];
        
        r -> vec[2] = a -> vec[0] * b -> vec[1] 
            - a->vec[1] * b -> vec[0];
    }
    /*  
        ¡Al no haber producto cruz con vectores de dimensión mayor,
        el resultado será un vector nulo!.
    */
    return r;
}

/*|----------------------------------------------------|*/
/*
    Función que recibe como parámetros dos vectores
    para realizar el producto punto entre ellos,
    retornando un escalar con el resultado.
*/
/*|----------------------------------------------------|*/
double productoPunto(Vector *a, Vector *b){
    double resultado = 0.0f;
    int i; 
    for(i = 0; i < a->n; i++)
        resultado += ( a -> vec[i] * b->vec[i] );
    return resultado;
}

/*|----------------------------------------------------|*/
/*
    Función que recibe como parámetro un vector
    retornando la magnitud del mismo.
*/
/*|----------------------------------------------------|*/
double vectorMagnitud(Vector *a){
    double resultado = 0.0f;
    int i;
    for(i = 0; i < a->n; i++)
        resultado += ( a -> vec[i] * a -> vec[i] );
    resultado = sqrt(resultado);
    return resultado;
}