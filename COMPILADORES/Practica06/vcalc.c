/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 6                      |
    |   Tema: Ciclo FOR HOC5                    |
    |   Opcion: Calculadora de vectores         |
    |   Fecha de entrega: 10 de junio de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/
// La practica se presento presencialmente el 30 de mayo de 2022

/*|----------------------------------------------------|*/
/*|                Librerías de C                      |*/
/*|----------------------------------------------------|*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "vcalc.h"         // Librería para los prototipos de las funciones
#include "y.tab.h"

static Symbol *symlist = 0;     // Crea la tabla de símbolos
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
    Función que une dos vectores y retorna el nuevo
    vector.
*/
/*|----------------------------------------------------|*/
Vector *uneVector(Vector *a, Vector *b){
    Vector *c;
    int i, j;
    int size = a->n + b->n;
    c = creaVector(size);
    for(i = 0; i < a->n; i++){
        c->vec[i] = a->vec[i];
    }
    for(j = i; j < size; j++){
        c->vec[j] = b->vec[j - i];
    }
    return c;
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
Symbol *installVector(char *sym, int tp, Vector *v){
    Symbol *aux;
    aux = (Symbol*)malloc(sizeof(Symbol));
    aux->name = (char*)malloc(strlen(sym) + 1);   // Se suma uno para el caracter '\0'
    strcpy(aux->name,sym);
    aux->type = tp;
    aux->u.val = v;
    aux->next = symlist;
    symlist = aux;
    return aux;
}

Symbol *installDouble(char *sym, int tp, double d){
    Symbol *aux;
    aux = (Symbol*)malloc(sizeof(Symbol));
    aux->name = (char*)malloc(strlen(sym) + 1);   // Se suma uno para el caracter '\0'
    strcpy(aux->name,sym);
    aux->type = tp;
    aux->u.doublenumber = d;
    aux->next = symlist;
    symlist = aux;
    return aux;
}

/*|----------------------------------------------------|*/
/*|   Funciones para la máquina virtual de pila        |*/
/*|----------------------------------------------------|*/

#define NSTACK 256
#define NPROG 2000
static Datum stack[NSTACK];
static Datum *stackp;
Inst prog[NPROG];
Inst *progp;
Inst *pc;

void initcode(){
    stackp = stack;
    progp = prog;
}

static struct {
    char *name;
    int val;
} keywords[] = {
    "if", IF,
    "else", ELSE,
    "while", WHILE,
    "print", PRINT,
    "for", FOR,
    0, 0,    
};

int init(){
    int i;
    Symbol *s;
    for(i = 0; keywords[i].name; i++)
        installVector(keywords[i].name, keywords[i].val, NULL);
}

void push(Datum d){
    if( stackp >= &stack[NSTACK])
        execerror("stack overflow",(char*)0);
    *stackp++ = d;
}

Datum pop(){
    if(stackp <= stack)
        execerror("stack underflow",(char*)0);
    return *--stackp;
}

void pop1(){
    if(stackp <= stack)
        execerror("stack underflow",(char*)0);
    --stackp;
}

void constpushvector(){
    Datum d;
    d.val = ((Symbol*)*pc++)->u.val;
    push(d);
}

void constpushdouble(){
    Datum d;
    d.doublenumber = ((Symbol*)*pc++)->u.doublenumber;
    push(d);
}

void varpush(){
    Datum d;
    d.sym = (Symbol*)(*pc++);
    push(d);
}

void eval(){
    Datum d;
    d = pop();
    if(d.sym->type == INDEF)
        execerror("undefined variable",d.sym->name);
    d.val = d.sym->u.val;
    push(d);
}

void add(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = sumaVector(d1.val, d2.val); 
    push(d1);
}

void sub(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = restaVector(d1.val, d2.val);
    push(d1);
}

void escalarXvector(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = escalarVector(d1.doublenumber, d2.val);
    push(d1);
}

void vectorXescalar(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d2.val = escalarVector(d2.doublenumber, d1.val);
    push(d2);
}

void mulPunto(){
    Datum d1, d2;
    double d3;
    d2 = pop();
    d1 = pop();
    d3 = productoPunto(d1.val, d2.val);
    push((Datum)d3);
}

void mulCruz(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = productoCruz(d1.val, d2.val);
    push(d1);
}

void get_magnitude(){
    Datum d1;
    d1 = pop();
    d1.doublenumber = vectorMagnitud(d1.val);
    push(d1);
}

void assign(){
    Datum d1, d2;
    d1 = pop();
    d2 = pop();
    if(d1.sym->type != VAR && d1.sym->type != INDEF)
        execerror("assignment to non-variable", d1.sym->name);
    d1.sym->u.val = d2.val;
    d1.sym->type = VAR;
    push(d2);
}

void printVector(){
    Datum d;
    d = pop();
    imprimeVector(d.val);
}

void printDouble(){
    Datum d;
    d = pop();
    printf("\tResultado: %lf\n",d.doublenumber);
}

Inst *code(Inst f){    
    Inst *oprogp = progp;
    if (progp >= &prog [ NPROG ])
		execerror("program too big", (char *) 0);
    *progp++ = f;
    return oprogp;
}

void execute( Inst* p){     
    for( pc = p; *pc != STOP; ) 
        (*(*pc++))();             
}

/*|----------------------------------------------------|*/
/*|        Funciones de comparacion practica 5         |*/
/*|----------------------------------------------------|*/

void MayorQue(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (int)(vectorMagnitud(d1.val) > vectorMagnitud(d2.val));
    push(d1);
}

void MayorIgualQue(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (int)(vectorMagnitud(d1.val) >= vectorMagnitud(d2.val));
    push(d1);
}

void MenorQue(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (int)(vectorMagnitud(d1.val) < vectorMagnitud(d2.val));
    push(d1);
}

void MenorIgualQue(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (int)(vectorMagnitud(d1.val) <= vectorMagnitud(d2.val));
    push(d1);
}

void IgualQue(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (int)(vectorMagnitud(d1.val) == vectorMagnitud(d2.val));
    push(d1);
}

void NoIgualQue(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (int)(vectorMagnitud(d1.val) != vectorMagnitud(d2.val));
    push(d1);
}

void And(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (double)(d1.doublenumber != 0.0 && d2.doublenumber != 0.0);
    push(d1);
}

void Or(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.doublenumber = (double)(d1.doublenumber != 0.0 || d2.doublenumber != 0.0);
    push(d1);
}

void Not(){
    Datum d1;
    d1 = pop();
    d1.doublenumber = (double)(d1.doublenumber != 0.0);
    push(d1);
}

void whilecode(){
    Datum d;
    Inst* savepc = pc;     
    execute(savepc + 2);    
    d = pop();
    while(d.val){
        execute(* ( (Inst **)(savepc) ));   
        execute(savepc + 2);
        d = pop();
    }
    pc = *((Inst **)(savepc + 1)); 
}

void ifcode(){
    Datum d;
    Inst* savepc = pc;     
    execute(savepc + 3);    
    d = pop();
    if(d.val)
        execute(*((Inst **)(savepc)));
    else if(*((Inst **)(savepc + 1)))      
        execute(*((Inst **)(savepc + 1)));
    pc = *((Inst **)(savepc + 2));
}

void bltin(){  
    Datum d;
    d = pop();
    d.val = (*(Vector * (*)() )(*pc++))(d.val);
    push(d);    
}

/*|----------------------------------------------------|*/
/*|               Funcion FOR practica 6               |*/
/*|----------------------------------------------------|*/


void forcode(){
    Datum d;
    Inst* savepc = pc;
    execute(savepc + 4);
    execute(*((Inst **)(savepc)));
    d = pop();
    while(d.val){
        execute(* ( (Inst **)(savepc + 2)));
        execute(* ( (Inst **)(savepc + 1)));
        execute(*((Inst **)(savepc)));
        d = pop();
    }
    pc = *((Inst **)(savepc + 3));
}