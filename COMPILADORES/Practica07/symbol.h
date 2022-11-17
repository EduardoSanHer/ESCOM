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
typedef void (*Inst)();
#include "vcalc.h"

/*|----------------------------------------------------|*/
/*|                Tabla de símbolos                   |*/
/*|----------------------------------------------------|*/
typedef struct Symbol {         // Tabla de símbolos
	char   *name;
	short   type;               // VAR, BLTIN, INDEF
	union {
		Vector *varVector;      // Si es VARVECTOR
        double varEscalar;      // Si es VARESCALAR
        Inst *defn;
	} u;
	struct Symbol   *next;      // Ligado al siguiente símbolo
} Symbol;

/*|----------------------------------------------------|*/
/*|        Funciones para la tabla de símbolos         |*/
/*|----------------------------------------------------|*/
Symbol *install(char *s, int t, double d);   // Funcion para ingresar un simbolo a la tabla de simbolos
Symbol *lookup(char *s);                     // Funcion para buscar un simbolo en la tabla de simbolos

/*|----------------------------------------------------|*/
/*|   Funciones para la máquina virtual de pila        |*/
/*|----------------------------------------------------|*/
typedef union Datum{
    Vector* vect;
    double num;
    Symbol* sym;
}Datum;

extern Datum pop();
typedef void (*Inst)();

#define STOP (Inst) 0
extern	Inst prog[], *progp, *progbase, *code();
extern void pushNum();
extern void pushVector();
extern void pushDouble();
extern void varpush();
extern void evalEscalar();
extern void evalVector();
extern void assignEscalar();
extern void assignVector();
extern void add();
extern void sub();
extern void mulCruz();
extern void escalarXvector();
extern void vectorXescalar();
extern void get_magnitude();
extern void mulPunto();
extern void printVector();
extern void printDouble();
extern void pop1();

extern void whilecode();
extern void ifcode();
extern void prexpresc();
extern void prexprvec();

extern void MayorQueEE();
extern void MenorQueEE(); 
extern void IgualQueEE(); 
extern void MayorIgualQueEE(); 
extern void MenorIgualQueEE(); 
extern void NoIgualQueEE(); 
extern void AndEE(); 
extern void OrEE();
extern void NotEE();

extern void MayorQueVV();
extern void MenorQueVV(); 
extern void IgualQueVV(); 
extern void MayorIgualQueVV(); 
extern void MenorIgualQueVV(); 
extern void NoIgualQueVV(); 
extern void AndVV(); 
extern void OrVV();
extern void NotVV();

extern void MayorQueEV();
extern void MenorQueEV(); 
extern void IgualQueEV(); 
extern void MayorIgualQueEV(); 
extern void MenorIgualQueEV(); 
extern void NoIgualQueEV(); 
extern void AndEV(); 
extern void OrEV();

extern void MayorQueVE();
extern void MenorQueVE(); 
extern void IgualQueVE(); 
extern void MayorIgualQueVE(); 
extern void MenorIgualQueVE(); 
extern void NoIgualQueVE(); 
extern void AndVE(); 
extern void OrVE();

extern void forcode();

extern void call();
extern void arg();
extern void argassign();
extern void funcret();
extern void procret();