/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 4                      |
    |   Tema: Maquina Virtual de Pila HOC4      |
    |   Opcion: Calculadora de vectores         |
    |   Fecha de entrega: 10 de junio de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/
// La practica se presento presencialmente el 23 de mayo de 2022

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

    #define MSDOS
    #define code2(c1,c2) code(c1); code(c2);
    #define code3(c1,c2,c3) code(c1); code(c2); code(c3);

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
    double doublenumber;
    Vector *vector;
    Symbol *sym;
    Inst *inst;
}

/*|----------------------------------------------------|*/
/*|  Creación de símbolos terminales y no terminales   |*/
/*|----------------------------------------------------|*/
%token<doublenumber>    NUMBER      //  Terminal para números positivos
%token<doublenumber>    nNUMBER     //  Terminal para números negativos
%token<sym>         VAR INDEF       //  Terminal para variables
%type<vector>       exp                         //  No Terminal para expresiones
%type<sym>          vector                      //  No Terminal para vectores
%type<vector>       asigna                      //  No Terminal para asignaciones
%type<doublenumber> NTnumber                    //  No Terminal auxiliar para números
%type<sym>          auxNumber                   //  Segundo No Terminal auxiliar para números
%type<doublenumber> auxNumberNoAction           //  Segundo No Terminal auxiliar para números
%token<sym>         VT
%token<sym>         NO

/*|----------------------------------------------------|*/
/*|            Jerarquía para los operadores           |*/
/*|----------------------------------------------------|*/
%right '='                  // Asignacion
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
        | exp '\n'          {code2(printVector, STOP); return 1;}
        | asigna '\n'       {code2(pop, STOP); return 1;}
        | NTnumber '\n'     {code2(printDouble, STOP); return 1;}
        ;

/*
    asigna => VAR '=' exp
*/
    asigna  : VAR '=' exp     {code3(varpush, (Inst)$1, assign);}
            ;

/* 
    exp => vector
    exp => exp '+' exp
    exp => exp '-' exp
    exp => exp '*' auxNumber
    exp => auxNumber * exp
    exp => exp 'x' exp
*/
    exp : vector                {code2(constpushvector, (Inst)$1);}
        | VAR                   {code3(varpush, (Inst)$1, eval);}
        | asigna
        | exp '+' exp           {code(add);}            //  Suma de vectores
        | exp '-' exp           {code(sub);}            //  Resta de vectores
        | exp '*' NTnumber     {code(vectorXescalar);}  //  Producto escalar por la derecha
        | NTnumber '*' exp     {code(escalarXvector);}  //  Producto escalar por la izquierda
        | exp 'x' exp           {code(mulCruz);}        //  Producto cruz de vectores
        ;

/*
    NTnumber => auxNumber
    NTnumber => vector '.' vector
    NTnumber => '|' vector '|'
*/
    NTnumber: auxNumber         {code2(constpushdouble, (Inst)$1);} //  Numero negativo o positivo
            | exp '.' exp       {code(mulPunto);}                   //  Resultado del producto punto
            | '|' exp '|'       {code(get_magnitude);}              //  Resultado de la magnitud
            ;
    
/*
    auxNumber => NUMBER
    auxNumber => nNUMBER
*/
    auxNumber   : NUMBER        {$$ = installDouble("", NO, $1);} //  Número positivo
                | nNUMBER       {$$ = installDouble("", NO, $1);} //  Número negativo
                ;

/*
    auxNumberNoAction => NUMBER
    auxNumberNoAction => nNUMBER
*/
    auxNumberNoAction   : NUMBER        //  Número positivo
                        | nNUMBER       //  Número negativo
                        ;

/*
    vector => auxNumberNoAction auxNumberNoAction 
    vector => auxNumberNoAction auxNumberNoAction auxNumberNoAction
    vector => auxNumberNoAction auxNumberNoAction auxNumberNoAction auxNumberNoAction
    vector => auxNumberNoAction auxNumberNoAction auxNumberNoAction auxNumberNoAction auxNumberNoAction

*/
    vector  : '[' auxNumberNoAction auxNumberNoAction ']'   {   //  Crea vector de 2 dimensiones
                                                Vector *v = creaVector(2);
                                                v -> vec[0] = $2;
                                                v -> vec[1] = $3;
                                                $$ = installVector("", VT, v);
                                            }
            | '[' auxNumberNoAction auxNumberNoAction auxNumberNoAction ']' {   //  Crea vector de 3 dimensiones
                                                        Vector *v = creaVector(3);
                                                        v -> vec[0] = $2;
                                                        v -> vec[1] = $3;
                                                        v -> vec[2] = $4;
                                                        $$ = installVector("", VT, v);
                                                    }
            |  '[' auxNumberNoAction auxNumberNoAction auxNumberNoAction auxNumberNoAction ']'  {   //  Crea vector de 4 dimensiones
                                                                    Vector *v = creaVector(4);
                                                                    v -> vec[0] = $2;
                                                                    v -> vec[1] = $3;
                                                                    v -> vec[2] = $4;
                                                                    v -> vec[3] = $5;
                                                                    $$ = installVector("", VT, v);
                                                                }
            |  '[' auxNumberNoAction auxNumberNoAction auxNumberNoAction auxNumberNoAction auxNumberNoAction ']'    {   //  Crea vector de 5 dimensiones
                                                                                Vector *v = creaVector(5);
                                                                                v -> vec[0] = $2;
                                                                                v -> vec[1] = $3;
                                                                                v -> vec[2] = $4;
                                                                                v -> vec[3] = $5;
                                                                                v -> vec[4] = $6;
                                                                                $$ = installVector("", VT, v);
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
    for(initcode(); yyparse(); initcode())
        execute(prog);
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
        scanf("%lf", &yylval.doublenumber);
        if (aux == 1){
            yylval.doublenumber = yylval.doublenumber * (-1);
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
            s = installVector(sbuf, INDEF, (Vector*)NULL);    // Si no se encuentra, la agrega
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