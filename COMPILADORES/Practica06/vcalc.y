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
    int eval;
}

/*|----------------------------------------------------|*/
/*|  Creación de símbolos terminales y no terminales   |*/
/*|----------------------------------------------------|*/
%token<doublenumber>    NUMBER      //  Terminal para números positivos
%token<doublenumber>    nNUMBER     //  Terminal para números negativos
%token<sym>         VAR INDEF       //  Terminal para variables
%type<inst>         exp                         //  No Terminal para expresiones
%type<sym>          vector                      //  No Terminal para vectores
%type<inst>         asigna                      //  No Terminal para asignaciones
%type<doublenumber> NTnumber                    //  No Terminal auxiliar para números
%type<sym>          auxNumber                   //  Segundo No Terminal auxiliar para números
%type<doublenumber> auxNumberNoAction           //  Segundo No Terminal auxiliar para números
%token<sym>         VT
%token<sym>         NO
%token<sym>         PRINT WHILE IF ELSE BLTIN
%type<inst>         stmt stmtlist cond while if end
%token<sym>         FOR
%type<inst>         for exprn

/*|----------------------------------------------------|*/
/*|            Jerarquía para los operadores           |*/
/*|----------------------------------------------------|*/
%right '='                  // Asignacion
%left OR AND                // Or & And
%left GT GE LT LE EQ NE     // GreaterThan GreaterEqual LessThan LessEqual Equal NonEqual
%left '+' '-'               // Suma y resta
%left '*'                   // Producto de vector por escalar
%left 'x' '.'               // Producto cruz y producto punto
%left NOT

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
    list => stmt '\n'       // Statement
    list => error '\n'      // ERROR
*/
    list: '\n'
        | exp '\n'          {code2(printVector, STOP); return 1;}
        | asigna '\n'       {code2((Inst)pop, STOP); return 1;}
        | NTnumber '\n'     {code2(printDouble, STOP); return 1;}
        | stmt '\n'         {code(STOP); return 1;}
        | error '\n'        {yyerror;}
        ;

/*
    asigna => VAR '=' exp
*/
    asigna  : VAR '=' exp     {$$ = $3; code3(varpush, (Inst)$1, assign);}
            ;

/* 
    exp => vector               // Vector
    exp => VAR                  // Variable
    exp => exp '+' exp          // Suma
    exp => exp '-' exp          // Resta
    exp => exp '*' auxNumber    // Producto escalar por la derecha
    exp => auxNumber '*' exp    // Producto escalar por la izquierda
    exp => exp 'x' exp          // Producto cruz
    exp => exp GT exp           // Mayor
    exp => exp GE exp           // Mayor igual
    exp => exp LT exp           // Menor
    exp => exp LE exp           // Menor igual
    exp => exp EQ exp           // Igual
    exp => exp NE exp           // No igual
    exp => exp OR exp           // O
    exp => exp AND exp          // Y
    exp => NOT exp              // NO
*/
    exp : vector                {$$ = code2(constpushvector, (Inst)$1);}
        | VAR                   {$$ = code3(varpush, (Inst)$1, eval);}
        | asigna
        | exp '+' exp           {code(add);}            //  Suma de vectores
        | exp '-' exp           {code(sub);}            //  Resta de vectores
        | exp '*' NTnumber     {code(vectorXescalar);}  //  Producto escalar por la derecha
        | NTnumber '*' exp     {code(escalarXvector);}  //  Producto escalar por la izquierda
        | exp 'x' exp           {code(mulCruz);}        //  Producto cruz de vectores
        | exp GT exp            {code(MayorQue);}
        | exp GE exp            {code(MayorIgualQue);}
        | exp LT exp            {code(MenorQue);}
        | exp LE exp            {code(MenorIgualQue);}
        | exp EQ exp            {code(IgualQue);}
        | exp NE exp            {code(NoIgualQue);}
        | exp OR exp            {code(Or);}
        | exp AND exp           {code(And);}
        | NOT exp               {$$ = $2; code(Not);}
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
/*
    stmtlist => 
    stmtlist => stmtlist '\n'
    stmtlist => stmtlist stmt '\n'
*/
    stmtlist:                   {$$ = progp;}
            | stmtlist '\n'
            | stmtlist stmt
            ;

/*
    stmt =>
*/
    stmt: exp                   {code((Inst)pop);}
        | PRINT exp             {code(printVector); $$ = $2;}
        | while cond stmt end   {
                                ($1)[1] = (Inst)$3;
                                ($1)[2] = (Inst)$4;
                                }
        | if cond stmt end      {
                                ($1)[1] = (Inst)$3;
                                ($1)[3] = (Inst)$4;
                                }
        | if cond stmt end ELSE stmt end   {
                                ($1)[1] = (Inst)$3;
                                ($1)[2] = (Inst)$6;
                                ($1)[3] = (Inst)$7;
                                }
        | for '(' exprn ';' exprn ';' exprn ')' stmt end {
                                ($1)[1] = (Inst)$5;
                                ($1)[2] = (Inst)$7;
                                ($1)[3] = (Inst)$9;
                                ($1)[4] = (Inst)$10;
                                }
        | '{' stmtlist '}'      {$$ = $2;}
        ;

/*
    cond => '(' exp ')' 
*/
    cond: '(' exp ')'   {code(STOP); $$ = $2;}
        ;
/*
    while => WHILE
*/
    while: WHILE    {$$ = code3(whilecode,STOP,STOP);}
        ;
/*
    if => IF
*/
    if: IF  {$$ = code(ifcode); code3(STOP,STOP,STOP);}
        ;
/*
    end => //NADA
*/
    end:    {code(STOP); $$ = progp;}
        ;
/*
    for => FOR
*/
    for: FOR    {$$ = code(forcode); code3(STOP,STOP,STOP); code(STOP);}
        ;
/*
    exprn => exp
    exprn => '{' stmtlist '}'
*/
    exprn: exp               {$$ = $1; code(STOP);}
        | '{' stmtlist '}'  {$$ = $2;}
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
    init();
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

    switch(c){
        case '>': return follow('=',GE,GT);
        case '<': return follow('=',LE,LT);
        case '=': return follow('=',EQ,'=');
        case '!': return follow('=',NE,NOT);
        case '|': return follow('|',OR,'|');
        case '&': return follow('&',AND,'&');
        case '\n': lineno++; return c;
        default: return c;
    }
    lineno++;
    return c;
}

int follow(int expect, int ifyes, int ifno){
    int c = getchar();
    if(c == expect)
        return ifyes;
    ungetc(c,stdin);
    return ifno;
}

int yyerror(char *s){
    warning(s,(char*)0);
    return 0;
}