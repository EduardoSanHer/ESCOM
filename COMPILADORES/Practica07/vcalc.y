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
/*| Se definen las librerías y funciones de apoyo      |*/
/*|----------------------------------------------------|*/
%{
    #include "symbol.h"
    void yyerror(char *s);
    int yylex();
    void warning(char *s, char *t);
    #define code2(c1,c2) code(c1); code(c2);
    #define code3(c1,c2,c3) code(c1); code(c2); code(c3);
    int indef;
    
%}

/*|-----------------------------------------------------|*/
//|     Se define el tipo de dato de la pila de Yacc    |*/
/*|-----------------------------------------------------|*/
%union{
    Symbol *sym;
    Inst *inst;
    int narg;
}

/*|----------------------------------------------------|*/
/*|  Creación de símbolos terminales y no terminales   |*/
/*|----------------------------------------------------|*/
%token<sym> NUMBER PRINT VAR VARVECTOR VARESCALAR INDEF WHILE IF ELSE FOR
%token<sym>   FUNCTION PROCEDURE RETURN FUNC PROC
%token<narg>  ARG
%type<inst> stmt asgnVector asgnEscalar expVectorial expEscalar stmtlist cond while if end for condfor stmtfor
%type<inst> begin
%type<sym>  procname
%type<narg> arglist

/*|----------------------------------------------------|*/
/*|            Jerarquía para los operadores           |*/
/*|----------------------------------------------------|*/
%right '='                  // Asignacion
%left OR AND                // Or & And
%left GT GE LT LE EQ NE     // GreaterThan GreaterEqual LessThan LessEqual Equal NonEqual
%left '+' '-'               // Suma y resta
%left '*'                   // Producto de vector por escalar
%left 'x'               // Producto cruz y producto punto
%left ';'
%left NOT

/*|----------------------------------------------------|*/
/*|                    Gramática                       |*/
/*|----------------------------------------------------|*/
%%
    list:   
        | list '\n'
        | list asgnVector '\n'   { code2(printVector, STOP); return 1; }
        | list asgnEscalar '\n'  { code2(printDouble, STOP); return 1; } 
        | list expVectorial '\n' { code2(printVector, STOP); return 1; }
        | list expEscalar '\n'   { code2(printDouble, STOP); return 1; } 
        | list defn '\n'
        | list stmt '\n'         { code(STOP); return 1; }
        ;

    asgnVector: VAR '=' expVectorial        { $$=$3; code3(varpush, (Inst)$1, assignVector); } //Declaracion
            | VARESCALAR '=' expVectorial   { $$=$3; code3(varpush, (Inst)$1, assignVector); } //Redefiniciones
            | VARVECTOR '=' expVectorial    { $$=$3; code3(varpush, (Inst)$1, assignVector); }
            | ARG '=' expVectorial          { defnonly("$"); code2(argassign,(Inst)$1); $$=$3;}
            ;

    asgnEscalar: '#' VAR '=' expEscalar           { $$=$4; code3(varpush, (Inst)$2, assignEscalar); } //Declaracion
                | '#' VARESCALAR '=' expEscalar   { $$=$4; code3(varpush, (Inst)$2, assignEscalar); }  //Redefeniciones
                | '#' VARVECTOR '='expEscalar     { $$=$4; code3(varpush, (Inst)$2, assignEscalar); } 
                ;   

    expVectorial: vector                   
                | VAR                               { $$=code3(varpush, (Inst)$1, evalVector); }
                | VARVECTOR                         { $$=code3(varpush, (Inst)$1, evalVector); }
                | ARG                               { defnonly("$"); $$ = code2(arg, (Inst)$1); }
                | FUNCTION begin '(' arglist ')'    { $$ = $2; code3(call,(Inst)$1,(Inst)$4); }  
                | expVectorial '+' expVectorial     { code(add); }
                | expVectorial '-' expVectorial     { code(sub); }
                | expVectorial 'x' expVectorial     { code(mulCruz); }
                | expEscalar '*' expVectorial       { code(escalarXvector); }
                | expVectorial '*' expEscalar       { code(vectorXescalar); }
                | '(' expVectorial ')'              {$$ = $2;}
                ;

    expEscalar: NUMBER                              { $$ = code2(pushDouble, (Inst)$1); }
                |  VARESCALAR                       { $$ = code3(varpush, (Inst)$1, evalEscalar); }
                | '|' expVectorial '|'              { $$ = code(get_magnitude); }
                | '|' expEscalar '|'                { $$ = $2; }
                | expVectorial '*' expVectorial     { code(mulPunto); }
                | '(' expEscalar ')'                { $$ = $2; }
                //Comparacion escalar con escalar
                | expEscalar GT expEscalar          { code(MayorQueEE); } 
                | expEscalar GE expEscalar          { code(MayorIgualQueEE); }
                | expEscalar LT expEscalar          { code(MenorQueEE); }
                | expEscalar LE expEscalar          { code(MenorIgualQueEE); }
                | expEscalar EQ expEscalar          { code(IgualQueEE); }
                | expEscalar NE expEscalar          { code(NoIgualQueEE); }
                | expEscalar AND expEscalar         { code(AndEE); }
                | expEscalar OR expEscalar          { code(OrEE); }
                | NOT expEscalar                    { $$ = $2; code(NotEE); } 
                //Comparacion vector con vector
                | expVectorial GT expVectorial      { code(MayorQueVV); }
                | expVectorial GE expVectorial      { code(MayorIgualQueVV); }
                | expVectorial LT expVectorial      { code(MenorQueVV); }
                | expVectorial LE expVectorial      { code(MenorIgualQueVV); }
                | expVectorial EQ expVectorial      { code(IgualQueVV); }
                | expVectorial NE expVectorial      { code(NoIgualQueVV); }
                | expVectorial AND expVectorial     { code(AndVV); }
                | expVectorial OR expVectorial      { code(OrVV); }
                | NOT expVectorial                  { $$ = $2; code(NotVV); }
                //Comparacion escalar con vector
                | expEscalar GT expVectorial      { code(MayorQueEV); }
                | expEscalar GE expVectorial      { code(MayorIgualQueEV); }
                | expEscalar LT expVectorial      { code(MenorQueEV); }
                | expEscalar LE expVectorial      { code(MenorIgualQueEV); }
                | expEscalar EQ expVectorial      { code(IgualQueEV); }
                | expEscalar NE expVectorial      { code(NoIgualQueEV); }
                | expEscalar AND expVectorial     { code(AndEV); }
                | expEscalar OR expVectorial      { code(OrEV); }
                //Comparacion vector con escalar
                | expVectorial GT expEscalar      { code(MayorQueVE); }
                | expVectorial GE expEscalar      { code(MayorIgualQueVE); }
                | expVectorial LT expEscalar      { code(MenorQueVE); }
                | expVectorial LE expEscalar      { code(MenorIgualQueVE); }
                | expVectorial EQ expEscalar      { code(IgualQueVE); }
                | expVectorial NE expEscalar      { code(NoIgualQueVE); }
                | expVectorial AND expEscalar     { code(AndVE); }
                | expVectorial OR expEscalar      { code(OrVE); }
                ;

    vector: '[' listnum ']' { code(pushVector); }
        ;

    listnum: 
            | NUMBER listnum { code2(pushNum, (Inst)$1); }
            ;

    stmt:   asgnEscalar                    { code(pop1); code(STOP); }
        | asgnVector                        { code(pop1); code(STOP); }
	    | PRINT expEscalar                  { code(prexpresc); $$ = $2; code(STOP);}
	    | PRINT expVectorial                { code(prexprvec); $$ = $2; code(STOP);}
	    | while cond stmt end               { ($1)[1] = (Inst)$3;     /* cuerpo de la iteracion */ 
	    	                                   ($1)[2] = (Inst)$4; }   /* terminar si la condicion no se cumple */
	    | if cond stmt end                  {    /* proposicion if que no emplea else */ 
	    	                                   ($1)[1] = (Inst)$3;     /* parte then */ 
	    	                                   ($1)[3] = (Inst)$4;
                                           }   /* terminar si la condicion no se cumple */ 
	    | if cond stmt end ELSE stmt end    {  /* proposicion if con parte else */
                                             ($1)[1]   =   (Inst)$3;	/*  parte then  */
                                             ($1)[2]   =   (Inst)$6;	/* parte else   */
                                             ($1)[3]   =   (Inst)$7;   } /*   terminar si la condicion no se cumple  */
        | for '(' stmtfor ';' condfor ';' stmtfor ')' stmt end   {
                                                                   ($1)[1] = (Inst)$5;  /* condicion del for */  
                                                                   ($1)[2] = (Inst)$7; /* stmtfor que se repite cada ciclo */
                                                                   ($1)[3] = (Inst)$9; /*   cuerpo de la iteracion  */ 
                                                                   ($1)[4] = (Inst)$10; /*   terminar si la condicion no se cumple  */
                                                                }                                  
	    |   '{'   stmtlist   '}'                  { $$  =  $2; }
        | RETURN                                  { defnonly("return"); code(procret); } 
        | RETURN expVectorial                     { defnonly( "return" ); $$ = $2; code(funcret) ; } 
        | PROCEDURE begin '(' arglist ')'         { $$ = $2; code3(call, (Inst)$1, (Inst)$4); } 
        ;

    cond:	'('   expEscalar   ')'  { code(STOP);  $$  =  $2; }
        ;

    condfor: expEscalar { code(STOP);  $$  =  $1; }
        ;

    stmtfor: asgnEscalar            { code(pop1); code(STOP); }
            | asgnVector            { code(pop1); code(STOP); }
            | PRINT expEscalar      { code(prexpresc); $$ = $2; code(STOP);}
            | PRINT expVectorial    { code(prexprvec); $$ = $2; code(STOP);}
            ;
    while:  WHILE   { $$ = code3(whilecode,STOP,STOP); }
        ;

    if: IF          { $$=code(ifcode); code3(STOP, STOP, STOP); }
        ;

    for:    FOR     { $$ = code(forcode); code3(STOP, STOP, STOP); code(STOP);   }
        ; 

    begin:  /* nada */      { $$ = progp; }
        ;

    end:     /* nada */     { code(STOP); $$ = progp; }
	    ;
    stmtlist: /* nada */    { $$ = progp; }
	    | stmtlist '\n' 
	    | stmtlist stmt
	    ;

    defn: FUNC procname { $2->type=FUNCTION; indef=1; }
            '(' ')' stmt { code(procret); define($2); indef=0; } 
        | PROC procname { $2->type=PROCEDURE; indef=1; }
            '(' ')' stmt { code(procret); define($2); indef=0; }
        ;

    procname: VAR
            | FUNCTION 
            | PROCEDURE
            ;

    arglist:  /* nada */                { $$ = 0; }
            | expVectorial              { $$ = 1; }
            | arglist ',' expVectorial  { $$ = $1 + 1; }
            ;

%%

/*|----------------------------------------------------|*/
/*|                    Código en C                     |*/
/*|----------------------------------------------------|*/

#include <stdio.h>
#include <ctype.h>
#include <setjmp.h>
char *progname;
int lineno = 1;
jmp_buf  begin;
int indef;
char *infile;
FILE *fin;
char **gargv;
int gargc;
int c;

int yylex (){
  	int c, aux;                         // Variable que almacena el caracter y auxiliar para numeros negativos
  	while ((c = getchar ()) == ' ' || c == '\t')
  		;
 	if (c == EOF)
    	return 0;
    if (c == '\''){                      // En caso de que se trate de un número negativo
        aux = 1;
        c = getchar();
    }
    else
        aux = 0;
    if( c == '.' || isdigit(c)){
        double d;
        ungetc(c, stdin);
        scanf("%lf", &d);
        if (aux == 1){  //Si es un numero negativo
            d = d * (-1);   // Asigna un numero negativo
        }
        yylval.sym = install("",NUMBER,d);
        return NUMBER;  // Retorna numero
    }
    if(isalpha(c) && c != 'x'){         // Comprueba que las variables sean letras excepto la 'x'
        Symbol *s;
        char sbuf[200], *p=sbuf;
        do{
            if (p >= sbuf + sizeof(sbuf) - 1){ 
                *p = '\0'; 
                printf("\tNombre de variable muy largo\n"); 
            }
            *p++ = c;
        }while((c=getc(stdin)) != EOF && isalnum(c));
        ungetc(c, stdin);
        *p = '\0';
        if((s=lookup(sbuf)) == 0)   // Comprueba si se encuentra la variable en la tabla de simbolos
            s = install(sbuf, INDEF, 0.0);    // Si no se encuentra, la agrega
        yylval.sym=s;
        if(s->type == INDEF)
            return VAR;
        else
            return s->type;
    }
    if(c == '\n')
		lineno++;
	if(c == '$'){   // Para argumentos
		int n = 0;
		while(isdigit(c=getc(fin)))
			n =  10 * n + c - '0';
		ungetc(c,fin);
		if(n == 0)
			execerror("strange $...", (char *)0);
		yylval.narg = n;
		return ARG;
	}

    switch(c){
        case '>': return follow('=',GE,GT);
        case '<': return follow('=',LE,LT);
        case '=': return follow('=',EQ,'=');
        case '!': return follow('=',NE,NOT);
        case '|': return follow('|',OR,'|');
        case '&': return follow('&',AND,'&');
        case '\n': lineno++; return '\n';
        default: return c;
    }
    return c;
}

follow(expect,ifyes,ifno){
    int c = getchar();
    if(c == expect)
        return ifyes;
    ungetc(c,stdin);
    return ifno;
}

void defnonly(char *s){
    if(!indef)
        printf("%s\n", "used outside definition"); 
}

void run(){
    setjmp(begin);
    for(initcode();yyparse();initcode())
        execute(progbase);
}

int moreinput(){
    if(gargc--<=0)
        return 0;
    if(fin && fin !=stdin)
        fclose(fin);
    infile = *gargv++;
    lineno = 1;
    if(strcmp(infile,"-") == 0){
        fin = stdin;
    infile = 0;
    }else if((fin =fopen(infile,"r")) ==NULL){
        fprintf(stderr,"%s: cannot open %s\n",progname,infile);
        return moreinput();
    }
    return 1;
}

int main (int argc, char *argv[]){	
    int i;
    progname = argv[0];
    if(argc == 1){
        static char *stdinonly[] = { "-"};
        gargv = stdinonly;
        gargc = 1;
    }else{
        gargv = argv +1;
        gargc = argc -1;
    }
    init();
    while(moreinput())
        run();
    return 0;
}

void execerror(char *s, char *t){
	printf("%s %s\n", s, t); 
	longjmp(begin, 0);
}

void yyerror(char *s){
    printf("%s\n", s);
    longjmp(begin, 0);
    return ;
}