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
Inst *progbase = prog;
int dimVector;
int returning;

typedef struct Frame {
    Symbol  *sp;
    Inst    *retpc;
    Datum  *argn;
    int    nargs;
} Frame;

#define NFRAME  1000 
Frame  frame[NFRAME] ;
Frame   *fp;

void initcode(){
    progp = progbase;
    stackp = stack;
    fp = frame;
    returning = 0; 
    dimVector=0;
}

void push(Datum d){
    if( stackp >= &stack[NSTACK])
        printf("%s\n","stack overflow");
    *stackp++ = d;
}

Datum pop(){
    if(stackp <= stack)
        printf("%s\n","stack underflow");
    return *--stackp;
}

void pop1(){
    if(stackp <= stack)
        printf("%s\n","stack underflow");
    --stackp;
}

void pushDouble(){
    Datum d;
    d.num = ((Symbol*)*pc++)->u.varEscalar;
    push(d);
}

void pushNum(){
    pushDouble();
    dimVector++;
}

void pushVector(){
    Vector *vec=creaVector(dimVector);
    int i;
    for(i=0 ; i<dimVector ; i++){
        Datum t = pop();
        vec->vec[i] = t.num;
    }
    Datum d;
    d.vect = vec;
    push(d);
    dimVector = 0;
}

void varpush(){
    Datum d;
    d.sym = (Symbol*)(*pc++);
    push(d);
}

void evalEscalar(){
    Datum  d;
    d = pop();
    if(d.sym->type == INDEF)
        printf("Variable sin definir: %s\n",d.sym->name);
    d.num = d.sym->u.varEscalar;
    push(d);
}

void evalVector(){
    Datum  d;
    d = pop();
    if(d.sym->type == INDEF || d.sym->type == VAR){
        printf("Variable sin definir: %s\n",d.sym->name);
        d.vect = NULL;
    }else
        d.vect = d.sym->u.varVector;
    push(d);
}

void assignEscalar(){
    Datum d1, d2;
    d1 = pop();
    d2 = pop();
    d1.sym->u.varEscalar = d2.num;
    d1.sym->type = VARESCALAR;
    push(d2); 
} 

void assignVector(){
    Datum d1, d2;
    d1 = pop();
    d2 = pop();
    d1.sym->u.varVector = d2.vect;
    d1.sym->type = VARVECTOR;
    push(d2); 
}

void add(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.vect = sumaVector(d1.vect, d2.vect); 
    push(d1);
}

void sub(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.vect = restaVector(d1.vect, d2.vect);
    push(d1);
}

void escalarXvector(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.vect = escalarVector(d1.num, d2.vect);
    push(d1);
}

void vectorXescalar(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d2.vect = escalarVector(d2.num, d1.vect);
    push(d2);
}

void get_magnitude(){
    Datum d1;
    d1 = pop();
    d1.num = vectorMagnitud(d1.vect);
    push(d1);
}

void mulPunto(){
    Datum d1, d2;
    double d3;
    d2 = pop();
    d1 = pop();
    d3 = productoPunto(d1.vect, d2.vect);
    push((Datum)d3);
}

void mulCruz(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.vect = productoCruz(d1.vect, d2.vect);
    push(d1);
}

void printVector(){
    Datum d;
    d = pop();
    imprimeVector(d.vect);
}

void printDouble(){
    Datum d;
    d = pop();
    printf("\tResultado: %lf\n",d.num);
}

Inst *code(Inst f){    
    Inst *oprogp = progp;
    if (progp >= &prog [ NPROG ])
		printf("%s\n","program too big");
    *progp++ = f;
    return oprogp;
}

void execute( Inst* p){     
    for( pc = p; *pc != STOP && !returning; ) 
        (*pc++)();             
}

/*|----------------------------------------------------|*/
/*|        Funciones de comparacion practica 5         |*/
/*|----------------------------------------------------|*/

void whilecode(){
    Datum d;
    Inst* savepc = pc;     
    execute(savepc + 2);    
    d = pop();
    while(d.num){
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
    if(d.num)
        execute(*((Inst **)(savepc)));
    else if(*((Inst **)(savepc + 1)))      
        execute(*((Inst **)(savepc + 1)));
    pc = *((Inst **)(savepc + 2));
}

void prexpresc() {      
    printDouble();
}

void prexprvec() {      
    printVector();
}

// Comparacion de escalares
void MayorQueEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num > d2.num);
    push(d1);
}

void MayorIgualQueEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num >= d2.num);
    push(d1);
}

void MenorQueEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num < d2.num);
    push(d1);
}

void MenorIgualQueEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num <= d2.num);
    push(d1);
}

void IgualQueEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num == d2.num);
    push(d1);
}

void NoIgualQueEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num != d2.num);
    push(d1);
}

void AndEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num != 0.0 && d2.num != 0.0);
    push(d1);
}

void OrEE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num != 0.0 || d2.num != 0.0);
    push(d1);
}

void NotEE(){
    Datum d1;
    d1 = pop();
    d1.num = (double)(d1.num != 0.0);
    push(d1);
}

//Comparacion de vectores
void MayorQueVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) > vectorMagnitud(d2.vect));
    push(d1);
}

void MayorIgualQueVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) >= vectorMagnitud(d2.vect));
    push(d1);
}

void MenorQueVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) < vectorMagnitud(d2.vect));
    push(d1);
}

void MenorIgualQueVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) <= vectorMagnitud(d2.vect));
    push(d1);
}

void IgualQueVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) == vectorMagnitud(d2.vect));
    push(d1);
}

void NoIgualQueVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) != vectorMagnitud(d2.vect));
    push(d1);
}

void AndVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) != 0.0 && vectorMagnitud(d2.vect) != 0.0);
    push(d1);
}

void OrVV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) != 0.0 || vectorMagnitud(d2.vect) != 0.0);
    push(d1);
}

void NotVV(){
    Datum d1;
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) != 0.0);
    push(d1);
}

// Comparacion de escalar con vector
void MayorQueEV() {
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num > vectorMagnitud(d2.vect));
    push(d1);
}

void MenorQueEV(){
    Datum d1,d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num < vectorMagnitud(d2.vect));
    push(d1);
}

void MayorIgualQueEV() {
    Datum d1,d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num >= vectorMagnitud(d2.vect));
    push(d1) ;
}

void MenorIgualQueEV() {
    Datum d1,d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num <= vectorMagnitud(d2.vect));
    push(d1);
}

void IgualQueEV() {
    Datum d1,d2;
    d2  = pop();
    d1  = pop();
    d1.num = (double)(d1.num == vectorMagnitud(d2.vect));
    push(d1);
}

void NoIgualQueEV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num != vectorMagnitud(d2.vect));
    push(d1);
}

void AndEV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num != 0.0 && vectorMagnitud(d2.vect) != 0.0);
    push(d1);
}

void OrEV(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(d1.num != 0.0 || vectorMagnitud(d2.vect) != 0.0);
    push(d1);
}

//Comparacion vector escalar
void MayorQueVE() {
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) > d2.num);
    push(d1);
}

void MenorQueVE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) < d2.num);
    push(d1);
}

void MayorIgualQueVE() {
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) >= d2.num);
    push(d1) ;
}

void MenorIgualQueVE() {
    Datum d1, d2;
    d2  =  pop();
    d1  =  pop();
    d1.num = (double)(vectorMagnitud(d1.vect) <= d2.num);
    push(d1);
}

void IgualQueVE() {
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double) (vectorMagnitud(d1.vect) == d2.num);
    push(d1);
}

void NoIgualQueVE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) != d2.num);
    push(d1);
}

void AndVE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) != 0.0 && d2.num != 0.0);
    push(d1);
}

void OrVE(){
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.num = (double)(vectorMagnitud(d1.vect) != 0.0 || d2.num != 0.0);
    push(d1);
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
    while(d.num){
        execute(* ( (Inst **)(savepc + 2)));
        execute(* ( (Inst **)(savepc + 1)));
        execute(*((Inst **)(savepc)));
        d = pop();
    }
    pc = *((Inst **)(savepc + 3));
}

/*|----------------------------------------------------|*/
/*|                Funciones practica 7                |*/
/*|----------------------------------------------------|*/

void define(Symbol *sp){
    sp->u.defn = progbase;
    progbase = progp;
}

void call(){
    Symbol *sp = (Symbol *)pc[0];
    if(fp++ >= &frame[NFRAME-1])
        execerror(sp->name, "call  nested too deeply");
    fp->sp = sp;
    fp->nargs =  (int)pc[1];
    fp->retpc = pc  + 2;
    fp->argn  =  stackp  -   1;     /*   �ltimo argumento   */
    execute(sp->u.defn);
    returning = 0; 
} 

void ret(){
    int i;
    for (i = 0; i < fp->nargs; i++)
        pop();
    pc = (Inst *)fp->retpc;
    --fp;
    returning = 1; 
}

void funcret(){
    Datum d;
    if (fp->sp->type == PROCEDURE)
        execerror(fp->sp->name, "(proc) returns value");
    d = pop();
    ret();
    push(d); 
}

void procret(){
    if(fp->sp->type  ==  FUNCTION)
        execerror(fp->sp->name,"(func) returns no value"); 
    ret(); 
}

Vector **getarg(){
    int nargs = (int) *pc++;
    if (nargs > fp->nargs)
	    execerror(fp-> sp->name, "not enough arguments");
    return &fp->argn[nargs - fp->nargs].vect; 
}

void arg(){
    Datum d;
    d.vect = *getarg();
    push(d); 
}

void argassign(){
    Datum d;
    d =pop();
    push(d);
    *getarg() = d.vect; 
}