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

/*|----------------------------------------------------|*/
/*|                Librerías de C                      |*/
/*|----------------------------------------------------|*/
#include "symbol.h"
#include "y.tab.h"

static struct {// Para constantes
    char *name; 
    double cval;
} consts[] = {
    "PI", 3.14159265358979323846,
    "E", 2.71828182845904523536,
    "GAMMA", 0.57721566490153286060,
    "DEG", 57.29577951308232087680,
    "PHI", 1.6180339887498948*820,
    0, 0
};

static struct {
    char *name;
    int kval;
} keywords[] = {
    "if", IF,
    "else", ELSE,
    "while", WHILE,
    "print", PRINT,
    "for", FOR,
    "proc", PROC,
    "func", FUNC,
    "return", RETURN,
    0, 0,    
};
init(){
    int i;
    Symbol *s;
    for(i = 0; keywords[i].name; i++)
        install(keywords[i].name, keywords[i].kval, 0.0);
    for(i = 0; consts[i].name; i++)
        s = install(consts[i].name, VARESCALAR, consts[i].cval);
    s->u.varVector = NULL;
}
