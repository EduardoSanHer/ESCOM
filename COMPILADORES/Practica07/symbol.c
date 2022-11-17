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
#include <stdlib.h>
#include <string.h>

static Symbol *symlist = 0;     // Crea la tabla de símbolos

/*|----------------------------------------------------|*/
/*
    Función que comprueba la existencia de un símbolo
    en la tabla de símbolos.
*/
/*|----------------------------------------------------|*/
Symbol *lookup(char *sym){
    Symbol *aux;
    for(aux = symlist; aux != (Symbol*)0; aux = aux -> next)
        if(strcmp(aux->name, sym) == 0)
            return aux;             // Si encuentra el símbolo, lo regresa
    return 0;                       // Si no, retorna nulo
}

/*|----------------------------------------------------|*/
/*
    Función que agrega un símbolo en la tabla de
    símbolos.
*/
/*|----------------------------------------------------|*/
Symbol *install(char *s, int t, double d){
    Symbol *sp;
	char *emalloc();
	sp = (Symbol *) emalloc(sizeof(Symbol));
	sp->name = emalloc(strlen(s)+ 1) ;   // Se suma uno para el caracter '\0'
	strcpy(sp->name, s);
	sp->type = t;
	sp->u.varEscalar = d;
	sp->next  =  symlist;
	symlist =  sp; 
        return sp; 
}

char  *emalloc(unsigned n){
    char *p;
	p = malloc(n); 
	if(p == 0)
		printf("out of memory"); 
	return p; 
}