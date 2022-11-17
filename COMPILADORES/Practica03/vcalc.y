/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 3                      |
    |   Tema: Tabla de símbolos HOC3            |
    |   Opcion: Calculadora de vectores         |
    |   Fecha de entrega: 29 de abril de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/

/*|----------------------------------------------------|*/
/*| Se definen las librerías y funciones de apoyo      |*/
/*|----------------------------------------------------|*/
%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<ctype.h>
    #include<signal.h>
    #include<setjmp.h>
    #include<string.h>
    #include"vcalc.c"

    int yyerror(char *s);
    int yylex();
    void warning(char *s, char *t);
    void execerror(char *s, char *t);
    void fpecatch();
%}

/*|-----------------------------------------------------|*/
//|     Se define el tipo de dato de la pila de Yacc    |*/
/*|-----------------------------------------------------|*/
%union{
    double val;
    Vector *vector;
    Symbol *sym;
}

/*|----------------------------------------------------|*/
/*|  Creación de símbolos terminales y no terminales   |*/
/*|----------------------------------------------------|*/
%token<val>     NUMBER      //  Terminal para números positivos
%token<val>     nNUMBER     //  Terminal para números negativos
%token<sym>     VAR INDEF   //  Terminal para variables

%type<vector>   exp         //  No Terminal para expresiones
%type<vector>   vector      //  No Terminal para vectores
%type<vector>   asigna      //  No Terminal para asignaciones
%type<val>      NTnumber    //  No Terminal auxiliar para números
%type<val>      auxNumber   //  Segundo No Terminal auxiliar para números

/*|----------------------------------------------------|*/
/*|            Jerarquía para los operadores           |*/
/*|----------------------------------------------------|*/
%right '='
%left '+' '-'               // Suma y resta
%left '*'                   // Producto de vector por escalar
%left 'x' '.'               // Producto cruz y producto punto

/*|----------------------------------------------------|*/
/*|                    Gramática                       |*/
/*|----------------------------------------------------|*/
%%
/*
    entrada => *vacio*
    entrada => entrada list
*/
    entrada :
            | entrada list;     // Esto funciona para que pueda realizar operación tras operación
            ;
                
/*
    list => '\n'            // Salto de linea
    list => exp '\n'        // Expresión
    list => asigna '\n'     // Asignación
    list => NTnumber '\n'   // Número
*/
    list: '\n'
        | exp '\n'          {imprimeVector($1);}
        | asigna '\n'       {imprimeVector($1);}
        | NTnumber '\n'     {printf("\tResultado: %lf\n",$1);}
        ;

/*
    asigna => VAR '=' exp
*/
    asigna  : VAR '=' exp     {
                                $$ = $1->u.val = $3;
                                $1->type=VAR;
                            }
            ;

/* 
    exp => vector
    exp => exp '+' exp
    exp => exp '-' exp
    exp => exp '*' auxNumber
    exp => auxNumber * exp
    exp => exp 'x' exp
*/
    exp : vector
        | VAR                   {
                                    if($1->type == INDEF)execerror("No se encuentra la variable: ",$1->name);
                                    $$ = $1->u.val;
                                }
        | asigna                {$$ = $1;}
        | exp '+' exp           {$$ = sumaVector($1, $3);}      //  Suma de vectores
        | exp '-' exp           {$$ = restaVector($1, $3);}     //  Resta de vectores
        | exp '*' auxNumber     {$$ = escalarVector($3, $1);}   //  Producto escalar por la derecha
        | auxNumber '*' exp     {$$ = escalarVector($1, $3);}   //  Producto escalar por la izquierda
        | exp 'x' exp           {$$ = productoCruz($1, $3);}    //  Producto cruz de vectores
        ;

/*
    NTnumber => auxNumber
    NTnumber => vector '.' vector
    NTnumber => '|' vector '|'
*/
    NTnumber: auxNumber                                         //  Numero negativo o positivo
            | exp '.' exp     {$$ = productoPunto($1, $3);}     //  Resultado del producto punto
            | '|' exp '|'        {$$ = vectorMagnitud($2);}     //  Resultado de la magnitud
            ;
    
/*
    auxNumber => NUMBER
    auxNumber => nNUMBER
*/
    auxNumber   : NUMBER            //  Número positivo
                | nNUMBER           //  Número negativo
                ;

/*
    vector => auxNumber auxNumber 
    vector => auxNumber auxNumber auxNumber
    vector => auxNumber auxNumber auxNumber auxNumber auxNumber

*/
    vector  : '[' auxNumber auxNumber ']'   {   //  Crea vector de 2 dimensiones
                                                Vector *v = creaVector(2);
                                                v -> vec[0] = $2;
                                                v -> vec[1] = $3;
                                                $$ = v;
                                            }
            | '[' auxNumber auxNumber auxNumber ']' {   //  Crea vector de 3 dimensiones
                                                        Vector *v = creaVector(3);
                                                        v -> vec[0] = $2;
                                                        v -> vec[1] = $3;
                                                        v -> vec[2] = $4;
                                                        $$ = v;
                                                    }
            |  '[' auxNumber auxNumber auxNumber auxNumber ']'  {   //  Crea vector de 4 dimensiones
                                                                    Vector *v = creaVector(4);
                                                                    v -> vec[0] = $2;
                                                                    v -> vec[1] = $3;
                                                                    v -> vec[2] = $4;
                                                                    v -> vec[3] = $5;
                                                                    $$ = v;
                                                                }
            |  '[' auxNumber auxNumber auxNumber auxNumber auxNumber ']'    {   //  Crea vector de 5 dimensiones
                                                                                Vector *v = creaVector(5);
                                                                                v -> vec[0] = $2;
                                                                                v -> vec[1] = $3;
                                                                                v -> vec[2] = $4;
                                                                                v -> vec[3] = $5;
                                                                                v -> vec[4] = $6;
                                                                                $$ = v;
                                                                            }
            ;
%%

/*|----------------------------------------------------|*/
/*|                    Código en C                     |*/
/*|----------------------------------------------------|*/
jmp_buf begin;
char *progname;
int lineno = 1;

void main(int argc, char *argv[]){
    progname=argv[0];
    setjmp(begin);
    signal(SIGFPE,fpecatch);
    yyparse();
}

void warning(char *s, char *t){
    fprintf(stderr,"%s: %s",progname,s);
    if(t)
        fprintf(stderr," %s",t);
	fprintf(stderr,"Cerca de la linea %d\n",lineno);
}

void execerror(char *s, char *t){
    warning(s, t);
    longjmp(begin, 0);
}

void fpecatch(){
    execerror("Excepcion de punto flotante", (char *)0);
}

int yylex (){
  	int c, aux;                         // Variable que almacena el caracter y auxiliar para numeros negativos
  	while ((c = getchar ()) == ' ' || c == '\t')
  		;
 	if (c == EOF)
    	return 0;
    if (c == 'n'){                      // En caso de que se trate de un número negativo
        aux = 1;
        c = getchar();
    }
    else
        aux = 0;
    if(isdigit(c)){
        ungetc(c, stdin);
        scanf("%lf", &yylval.val);
        if (aux == 1){
            yylval.val = yylval.val * (-1);
            return nNUMBER;             // Retorna numero negativo
        }
        return NUMBER;                  // Retorna numero positivo
    }
    if(isalpha(c) && c != 'x'){         // Comprueba que las variables sean letras excepto la 'x'
        Symbol *s;
        char sbuf[200], *p=sbuf;
        do{
            *p++ = c;
        }while((c=getchar()) != EOF && isalnum(c) && c != 'x');
        ungetc(c, stdin);
        *p = '\0';
        if((s=lookup(sbuf)) == (Symbol*)NULL)   // Comprueba si se encuentra la variable en la tabla de simbolos
            s = install(sbuf, INDEF, (Vector*)NULL);    // Si no se encuentra, la agrega
        yylval.sym=s;
        if(s->type == INDEF)
            return VAR;
        else
            return s->type;
    }
    if(c == '\n')
        lineno++;
    return c;
}

int yyerror(char *s){
    warning(s,(char*)0);
    return 0;
}