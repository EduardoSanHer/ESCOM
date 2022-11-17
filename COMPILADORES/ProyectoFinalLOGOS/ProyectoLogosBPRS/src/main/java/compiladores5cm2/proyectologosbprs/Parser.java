/*
    |---------------------------------------------------|
    |              Proyecto Final: LOGO                 |
    |                 Datos del equipo                  |
    |   Integrantes: Bernal Trani Marco Antonio         |
    |                Patlani Mauricio Adriana           |
    |                Ruvalcaba Flores Martha Catalina   |
    |                Sandoval Hernández Eduardo         |
    |   Opcion: LOGO                                    |
    |   Fecha de entrega: 13 de junio de 2022           |
    |   Grupo: 5CM2                                     |
    |   Materia: Compiladores                           |
    |----------------------------------------------------|
*/
package compiladores5cm2.proyectologosbprs;


//### This file created by BYACC 1.8(/Java extension  1.15)
//### Java capabilities added 7 Jan 97, Bob Jamison
//### Updated : 27 Nov 97  -- Bob Jamison, Joe Nieten
//###           01 Jan 98  -- Bob Jamison -- fixed generic semantic constructor
//###           01 Jun 99  -- Bob Jamison -- added Runnable support
//###           06 Aug 00  -- Bob Jamison -- made state variables class-global
//###           03 Jan 01  -- Bob Jamison -- improved flags, tracing
//###           16 May 01  -- Bob Jamison -- added custom stack sizing
//###           04 Mar 02  -- Yuval Oren  -- improved java performance, added options
//###           14 Mar 02  -- Tomas Hurka -- -d support, static initializer workaround
//### Please send bug reports to tom@hukatronic.cz
//### static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";






//#line 2 "logoyacc.y"
	import java.lang.Math;
	import java.io.*;
	import java.util.StringTokenizer;
//#line 21 "Parser.java"




public class Parser
{

boolean yydebug;        //do I want debug output?
int yynerrs;            //number of errors so far
int yyerrflag;          //was there an error?
int yychar;             //the current working character

//########## MESSAGES ##########
//###############################################################
// method: debug
//###############################################################
void debug(String msg)
{
  if (yydebug)
    System.out.println(msg);
}

//########## STATE STACK ##########
final static int YYSTACKSIZE = 500;  //maximum stack size
int statestk[] = new int[YYSTACKSIZE]; //state stack
int stateptr;
int stateptrmax;                     //highest index of stackptr
int statemax;                        //state when highest index reached
//###############################################################
// methods: state stack push,pop,drop,peek
//###############################################################
final void state_push(int state)
{
  try {
		stateptr++;
		statestk[stateptr]=state;
	 }
	 catch (ArrayIndexOutOfBoundsException e) {
     int oldsize = statestk.length;
     int newsize = oldsize * 2;
     int[] newstack = new int[newsize];
     System.arraycopy(statestk,0,newstack,0,oldsize);
     statestk = newstack;
     statestk[stateptr]=state;
  }
}
final int state_pop()
{
  return statestk[stateptr--];
}
final void state_drop(int cnt)
{
  stateptr -= cnt; 
}
final int state_peek(int relative)
{
  return statestk[stateptr-relative];
}
//###############################################################
// method: init_stacks : allocate and prepare stacks
//###############################################################
final boolean init_stacks()
{
  stateptr = -1;
  val_init();
  return true;
}
//###############################################################
// method: dump_stacks : show n levels of the stacks
//###############################################################
void dump_stacks(int count)
{
int i;
  System.out.println("=index==state====value=     s:"+stateptr+"  v:"+valptr);
  for (i=0;i<count;i++)
    System.out.println(" "+i+"    "+statestk[i]+"      "+valstk[i]);
  System.out.println("======================");
}


//########## SEMANTIC VALUES ##########
//public class ParserVal is defined in ParserVal.java


String   yytext;//user variable to return contextual strings
ParserVal yyval; //used to return semantic vals from action routines
ParserVal yylval;//the 'lval' (result) I got from yylex()
ParserVal valstk[];
int valptr;
//###############################################################
// methods: value stack push,pop,drop,peek.
//###############################################################
void val_init()
{
  valstk=new ParserVal[YYSTACKSIZE];
  yyval=new ParserVal();
  yylval=new ParserVal();
  valptr=-1;
}
void val_push(ParserVal val)
{
  if (valptr>=YYSTACKSIZE)
    return;
  valstk[++valptr]=val;
}
ParserVal val_pop()
{
  if (valptr<0)
    return new ParserVal();
  return valstk[valptr--];
}
void val_drop(int cnt)
{
int ptr;
  ptr=valptr-cnt;
  if (ptr<0)
    return;
  valptr = ptr;
}
ParserVal val_peek(int relative)
{
int ptr;
  ptr=valptr-relative;
  if (ptr<0)
    return new ParserVal();
  return valstk[ptr];
}
final ParserVal dup_yyval(ParserVal val)
{
  ParserVal dup = new ParserVal();
  dup.ival = val.ival;
  dup.dval = val.dval;
  dup.sval = val.sval;
  dup.obj = val.obj;
  return dup;
}
//#### end semantic value section ####
public final static short IF=257;
public final static short ELSE=258;
public final static short WHILE=259;
public final static short FOR=260;
public final static short FUNC=261;
public final static short RETURN=262;
public final static short PARAMETRO=263;
public final static short PROC=264;
public final static short FNCT=265;
public final static short NUMBER=266;
public final static short VAR=267;
public final static short AND=268;
public final static short OR=269;
public final static short COMP=270;
public final static short DIFERENTES=271;
public final static short MAY=272;
public final static short MEN=273;
public final static short MAYI=274;
public final static short MENI=275;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    5,    5,    5,
    6,    3,    3,    3,    3,    3,    3,    3,   15,   14,
   12,    4,   13,    8,    7,    9,   10,   11,   11,   11,
};
final static short yylen[] = {                            2,
    0,    2,    3,    2,    1,    3,    2,    1,    2,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    2,    1,    4,    0,    1,    3,
    0,   14,   11,   10,   16,    8,    8,    5,    1,    1,
    1,    1,    0,    0,    1,    1,    1,    0,    1,    3,
};
final static short yydefred[] = {                         1,
    0,   45,   46,   47,   41,    0,   26,   40,   39,   10,
    0,    0,    0,    2,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,   25,    0,    0,    0,    0,
    3,    0,    7,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    4,    0,    0,    0,    0,   42,
    0,    0,    0,    0,   15,    6,    0,   23,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   27,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   38,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,   37,    0,   44,
    0,    0,   44,   34,    0,    0,   33,    0,    0,    0,
    0,    0,   32,    0,   44,   35,
};
final static short yydgoto[] = {                          1,
   16,   17,   18,   19,   69,  113,   20,   79,   21,   22,
   73,   23,  102,   24,   25,
};
final static short yysindex[] = {                         0,
    1,    0,    0,    0,    0,   63,    0,    0,    0,    0,
  -51,   63,   63,    0,   63,   12,   69,    0,   -8,   -2,
   13,   24, -231, -231,  -12,    0,   63,  108, -260,  -29,
    0,   77,    0,   63,   63,   63,   63,   63,   63,   63,
   63,   63,   63,   63,    0,   63,   63,   63,   63,    0,
   31,   55,   63,   95,    0,    0, -197,    0,  -63,   59,
  130, -200, -171, -260,  108,  108,  -49,   95,   65,   95,
   95,   95,   44,   64,   76,  -37,    0,   63,   80,   84,
   63,   41,   -5,   11,   90,   95,   16,   30,   95,   63,
   37,   37,    0,   37,   37,   95,   37,   37,   37,   37,
  112,   47,   49,   57,   58,   63,    0,    0,  -78,    0,
   44,   67,    0,    0,  145,   37,    0,   68,   37,   37,
   70,   37,    0,   71,    0,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -39,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -26,   42,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   72,    0,    0,  -17,    0,
    0,    0,  -19,  -20,    0,    0,   17,    0,  125,  120,
  114,   88,  101,   48,  144,  397,    6,  -15,    0,  151,
  151,   -4,  134,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -13,    0,    0,   22,    0,
    0,    0,    0,    0,    0,  134,   73,   73,   74,   74,
    0,    0,    0,    0,    0,  110,    0,    0,  -10,    0,
  151,    0,    0,    0,    0,    0,    0,    0,   74,    0,
    0,   74,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
   32,  381,   78,   20,  148,    0,    0,  336,    0,    0,
   96,    0,  106,    0,    0,
};
final static int YYTABLESIZE=503;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                         31,
   42,    8,    8,    8,    8,    8,   78,   34,   35,   27,
   14,   55,   44,   42,    9,   43,    9,    9,    9,    8,
   11,   31,   31,   11,   28,   29,   48,   30,   29,   31,
   30,   46,    9,   13,   31,   50,   49,   47,   11,   49,
   15,   48,   51,   52,   13,   12,   12,   12,   12,   12,
   12,   15,   48,    8,   49,   85,   12,   22,   22,   22,
   22,   22,   50,   49,   12,   50,    9,   34,   35,   13,
   74,   35,   11,   28,   41,   22,   15,   29,   53,   30,
   50,   12,   24,   24,   24,   24,   24,   81,   19,   19,
   19,   19,   19,   33,   75,   13,   34,   35,   12,   90,
   24,   39,   15,   41,   83,   77,   19,   12,   78,   22,
   44,   42,   28,   43,   31,   28,   84,   91,   44,   42,
   87,   43,   97,   98,   88,   99,  100,   45,   18,   18,
   18,   18,   18,   92,   24,   56,   44,   42,   94,   43,
   19,   21,   21,   21,   21,   21,   18,  119,   93,   44,
   48,  122,   95,   48,   20,   20,   20,   20,   20,   21,
   17,   17,   17,   17,   17,   16,   16,   16,   16,   16,
  106,  107,   20,  108,   33,   33,   33,   33,   17,  112,
   18,  109,  110,   16,   13,  118,   13,   13,   13,  116,
  120,   44,   44,   21,  123,  125,   33,   43,   44,   33,
   76,  111,   13,  103,   34,   35,   20,   37,   38,   39,
   40,   41,   17,    0,    0,    0,    0,   16,   34,   35,
   36,   37,   38,   39,   40,   41,    0,    0,    8,    8,
    8,    8,    8,    8,    8,    8,   13,    0,   34,   35,
   36,   37,   38,   39,   40,   41,   31,    0,   31,   31,
   31,   31,   31,   31,   31,   31,   31,    2,    0,    3,
    4,    5,    6,    7,    8,    9,   10,   11,    2,    0,
    3,    4,    5,    6,    7,    8,    9,   10,   11,    0,
    0,    0,    0,    0,   22,    0,   22,   22,   22,   22,
   22,   22,    0,    2,    0,    3,    4,    5,    6,    7,
    8,    9,   10,   11,    0,    0,    0,    0,    0,    0,
    0,   24,   24,   24,   24,   24,   24,   19,   19,   19,
   19,   19,   19,    0,    6,    7,   34,   35,   10,   11,
   38,   39,   40,   41,    0,    0,   34,   35,   36,   37,
   38,   39,   40,   41,   34,   35,   36,   37,   38,   39,
   40,   41,    0,    0,    0,    0,    0,   18,   18,   18,
   18,   18,   34,   35,   36,   37,   38,   39,   40,   41,
   21,   21,   21,    0,   21,   34,   35,   36,   37,   38,
   39,   40,   41,   20,   20,   20,   26,    0,    0,   17,
   17,    0,   28,   29,   16,   30,   32,   34,   35,    0,
    0,    0,   39,   40,   41,    0,   80,   54,   82,    0,
    0,    0,    0,    0,   57,   58,   59,   60,   61,   62,
   63,   64,   65,   66,   67,    0,   68,   70,   71,   72,
    0,  101,    0,   68,  104,  105,    0,   14,    0,   14,
   14,   14,    0,    0,    0,  114,  115,    0,  117,    0,
    0,    0,    0,    0,  121,   14,    0,  124,   86,    0,
  126,   89,    0,    0,    0,    0,    0,    0,    0,    0,
   96,    0,    0,    0,    0,    0,    0,   32,   32,   32,
   32,    0,    0,    0,    0,    0,   72,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   32,
    0,    0,   32,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         10,
   40,   41,   42,   43,   44,   45,   44,  268,  269,   61,
   10,   41,   42,   43,   41,   45,   43,   44,   45,   59,
   41,   10,   33,   44,   44,   41,   44,   41,   44,   40,
   44,   40,   59,   33,   45,  267,   41,   40,   59,   44,
   40,   59,   23,   24,   33,   45,   41,   42,   43,   44,
   45,   40,   40,   93,   59,   93,   45,   41,   42,   43,
   44,   45,   41,   40,   59,   44,   93,  268,  269,   33,
   40,  269,   93,   93,  275,   59,   40,   93,   91,   93,
   59,   45,   41,   42,   43,   44,   45,   44,   41,   42,
   43,   44,   45,   16,   40,   33,  268,  269,   93,   59,
   59,  273,   40,  275,   41,   41,   59,   45,   44,   93,
   42,   43,   41,   45,  125,   44,   41,  123,   42,   43,
   41,   45,   91,   92,   41,   94,   95,   59,   41,   42,
   43,   44,   45,  123,   93,   59,   42,   43,  123,   45,
   93,   41,   42,   43,   44,   45,   59,  116,   59,   42,
   41,  120,  123,   44,   41,   42,   43,   44,   45,   59,
   41,   42,   43,   44,   45,   41,   42,   43,   44,   45,
   59,  125,   59,  125,   97,   98,   99,  100,   59,  258,
   93,  125,  125,   59,   41,   41,   43,   44,   45,  123,
  123,   41,   59,   93,  125,  125,  119,  125,  125,  122,
   53,  106,   59,   98,  268,  269,   93,  271,  272,  273,
  274,  275,   93,   -1,   -1,   -1,   -1,   93,  268,  269,
  270,  271,  272,  273,  274,  275,   -1,   -1,  268,  269,
  270,  271,  272,  273,  274,  275,   93,   -1,  268,  269,
  270,  271,  272,  273,  274,  275,  257,   -1,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  257,   -1,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  257,   -1,
  259,  260,  261,  262,  263,  264,  265,  266,  267,   -1,
   -1,   -1,   -1,   -1,  268,   -1,  270,  271,  272,  273,
  274,  275,   -1,  257,   -1,  259,  260,  261,  262,  263,
  264,  265,  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,  270,  271,  272,
  273,  274,  275,   -1,  262,  263,  268,  269,  266,  267,
  272,  273,  274,  275,   -1,   -1,  268,  269,  270,  271,
  272,  273,  274,  275,  268,  269,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,  274,  268,  269,  270,  271,  272,  273,  274,  275,
  270,  271,  272,   -1,  274,  268,  269,  270,  271,  272,
  273,  274,  275,  270,  271,  272,    6,   -1,   -1,  270,
  271,   -1,   12,   13,  270,   15,   16,  268,  269,   -1,
   -1,   -1,  273,  274,  275,   -1,   71,   27,   73,   -1,
   -1,   -1,   -1,   -1,   34,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   -1,   46,   47,   48,   49,
   -1,   96,   -1,   53,   99,  100,   -1,   41,   -1,   43,
   44,   45,   -1,   -1,   -1,  110,  111,   -1,  113,   -1,
   -1,   -1,   -1,   -1,  119,   59,   -1,  122,   78,   -1,
  125,   81,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   90,   -1,   -1,   -1,   -1,   -1,   -1,   97,   98,   99,
  100,   -1,   -1,   -1,   -1,   -1,  106,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  119,
   -1,   -1,  122,
};
}
final static short YYFINAL=1;
final static short YYMAXTOKEN=275;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,"'\\n'",null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,"'!'",null,null,null,null,null,null,"'('","')'","'*'","'+'",
"','","'-'",null,null,null,null,null,null,null,null,null,null,null,null,null,
"';'",null,"'='",null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,"'['",null,"']'",null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,"'{'",null,"'}'",null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,"IF","ELSE","WHILE","FOR","FUNC",
"RETURN","PARAMETRO","PROC","FNCT","NUMBER","VAR","AND","OR","COMP",
"DIFERENTES","MAY","MEN","MAYI","MENI",
};
final static String yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list linea '\\n'",
"linea : exp ';'",
"linea : stmt",
"linea : linea exp ';'",
"linea : linea stmt",
"exp : VAR",
"exp : '-' exp",
"exp : NUMBER",
"exp : VAR '=' exp",
"exp : exp '*' exp",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : '(' exp ')'",
"exp : exp COMP exp",
"exp : exp DIFERENTES exp",
"exp : exp MEN exp",
"exp : exp MENI exp",
"exp : exp MAY exp",
"exp : exp MAYI exp",
"exp : exp AND exp",
"exp : exp OR exp",
"exp : '!' exp",
"exp : RETURN exp",
"exp : PARAMETRO",
"exp : nombreProc '(' arglist ')'",
"arglist :",
"arglist : exp",
"arglist : arglist ',' exp",
"nop :",
"stmt : if '(' exp stop ')' '{' linea stop '}' ELSE '{' linea stop '}'",
"stmt : if '(' exp stop ')' '{' linea stop '}' nop stop",
"stmt : while '(' exp stop ')' '{' linea stop '}' stop",
"stmt : for '(' instrucciones stop ';' exp stop ';' instrucciones stop ')' '{' linea stop '}' stop",
"stmt : funcion nombreProc '(' ')' '{' linea null '}'",
"stmt : procedimiento nombreProc '(' ')' '{' linea null '}'",
"stmt : instruccion '[' arglist ']' ';'",
"instruccion : FNCT",
"procedimiento : PROC",
"funcion : FUNC",
"nombreProc : VAR",
"null :",
"stop :",
"if : IF",
"while : WHILE",
"for : FOR",
"instrucciones :",
"instrucciones : exp",
"instrucciones : instrucciones ',' exp",
};

//#line 200 "logoyacc.y"
Symbol sym = new Symbol();
Code machine = new Code(sym);
int i = 0;
int j = 0;
double[][] auxiliar;
Funcion funcionAux;
boolean huboError;

String ins;
StringTokenizer st;


boolean newline;
int yylex(){
	String s;
	int tok = 0;
	Double d;
	if (!st.hasMoreTokens()){
		if (!newline){
			newline=true;
			return '\n'; //So we look like classic YACC example
		}
		else
			return 0;
	}
	s = st.nextToken();
	try{
		d = Double.valueOf(s);/*this may fail*/
		yylval = new ParserVal(d.doubleValue()); //SEE BELOW
		return NUMBER;
	}
	catch (Exception e){}
	if(esVariable(s)){
		if(s.equals("procedure")){
			return PROC;
		}
		if(s.charAt(0) == '$'){
			yylval = new ParserVal((int)Integer.parseInt(s.substring(1)));
			return PARAMETRO;
		}
		if(s.equals("return")){
			return RETURN;
		}
		if(s.equals("function")){
			return FUNC;
		}
		if(s.equals("if")){
			return IF;
		}
		if(s.equals("else")){
			return ELSE;
		}
		if(s.equals("while")){
			return WHILE;
		}
		if(s.equals("for")){
			return FOR;
		}
		boolean esFuncion = false;
		Object objeto = sym.lookup(s);
		if(objeto instanceof Funcion){
			funcionAux = (Funcion)objeto;
			yylval = new ParserVal(objeto);
			esFuncion = true;
			return FNCT;
		}
		if(!esFuncion){
			yylval = new ParserVal(s);
			return VAR;
		}
	}
	else{
            if(s.equals("==")){
                return COMP;
            }
            if(s.equals("!=")){
                    return DIFERENTES;
            }
            if(s.equals("<")){
                    return MEN;
            }
            if(s.equals("<=")){
                    return MENI;
            }
            if(s.equals(">")){
                    return MAY;
            }
            if(s.equals(">=")){
                    return MAYI;
            }
            if(s.equals("&&")){
                    return AND;
            }
            if(s.equals("||")){
                    return OR;
            }
            tok = s.charAt(0);
	}
	return tok;
}

boolean esVariable(String s){
	boolean cumple = true;
	for(int i = 0; i < reservados.length; i++)
		if(s.equals(reservados[i]))
			cumple = false;
	return cumple;
}
public void symbolInst(){
	sym.insert("GIRAR", new Code.Girar());
	sym.insert("AVANZAR", new Code.Avanzar());
	sym.insert("COLOR", new Code.CambiarColor());
        sym.insert("SUBIR", new Code.SubirPincel());
        sym.insert("BAJAR", new Code.BajarPincel());
}


public CurrentState ejecutarCodigo(String codigo){
    st = new StringTokenizer(ajustarCadena(codigo));
    newline=false;
    yyparse();
    if(!huboError)
            machine.ejecutar();
    return machine.getCurrentState();
} 

public boolean compilar(String codigo){
    st = new StringTokenizer(ajustarCadena(codigo));
    newline=false;
    yyparse();
    return !huboError;
}

public boolean ejecutarSiguiente(){
    return machine.ejecutarSiguiente();
}

public CurrentState getCurrentState(){
    return machine.getCurrentState();
}

public void limpiar(){
    sym = new Symbol();
    symbolInst();
    machine = new Code(sym);
}

public CurrentState ejecutar(){
    machine.ejecutar();
    return machine.getCurrentState();
}

void dotest() throws Exception{
	symbolInst();
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	while (true){
		huboError = false;
		try{
			ins = ajustarCadena(in.readLine());
		}
		catch (Exception e){}
		st = new StringTokenizer(ins);
		newline=false;
		//machine = new Code(sym);
		yyparse();
		if(!huboError)
			machine.ejecutar();
	}
}

String reservados[] = {">=", "&&", "||", "<=","==", "!=", "=", "{", "}", ",", "*", "+", "-", "(", ")", "|", "[", "]", ";", "!", "<", ">"};
public String ajustarCadena(String cadena){
    String nueva = "";
    boolean encontrado = false;
    for(int i = 0; i < cadena.length() - 1; i++){
        encontrado = false;
        for(int j = 0; j < reservados.length; j++){
            if(cadena.substring(i, i + reservados[j].length()).equals(reservados[j])){
                i += reservados[j].length()-1;
                nueva += " " + reservados[j] + " ";
                encontrado = true;
                break;
            }
        }
        if(!encontrado)
            nueva += cadena.charAt(i);
    }
    nueva += cadena.charAt(cadena.length()-1);
    return nueva;
}

void yyerror(String s){
	huboError = true;
	System.out.println("error:"+s);
        System.exit(0);
}

public static void main(String args[]) throws Exception{
	Parser par = new Parser(false);
	par.dotest();
}

//#line 570 "Parser.java"
//###############################################################
// method: yylexdebug : check lexer state
//###############################################################
void yylexdebug(int state,int ch)
{
String s=null;
  if (ch < 0) ch=0;
  if (ch <= YYMAXTOKEN) //check index bounds
     s = yyname[ch];    //now get it
  if (s==null)
    s = "illegal-symbol";
  debug("state "+state+", reading "+ch+" ("+s+")");
}





//The following are now global, to aid in error reporting
int yyn;       //next next thing to do
int yym;       //
int yystate;   //current parsing state from state table
String yys;    //current token string


//###############################################################
// method: yyparse : parse input and execute indicated items
//###############################################################
int yyparse()
{
boolean doaction;
  init_stacks();
  yynerrs = 0;
  yyerrflag = 0;
  yychar = -1;          //impossible char forces a read
  yystate=0;            //initial state
  state_push(yystate);  //save it
  val_push(yylval);     //save empty value
  while (true) //until parsing is done, either correctly, or w/error
    {
    doaction=true;
    if (yydebug) debug("loop"); 
    //#### NEXT ACTION (from reduction table)
    for (yyn=yydefred[yystate];yyn==0;yyn=yydefred[yystate])
      {
      if (yydebug) debug("yyn:"+yyn+"  state:"+yystate+"  yychar:"+yychar);
      if (yychar < 0)      //we want a char?
        {
        yychar = yylex();  //get next token
        if (yydebug) debug(" next yychar:"+yychar);
        //#### ERROR CHECK ####
        if (yychar < 0)    //it it didn't work/error
          {
          yychar = 0;      //change it to default string (no -1!)
          if (yydebug)
            yylexdebug(yystate,yychar);
          }
        }//yychar<0
      yyn = yysindex[yystate];  //get amount to shift by (shift index)
      if ((yyn != 0) && (yyn += yychar) >= 0 &&
          yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
        {
        if (yydebug)
          debug("state "+yystate+", shifting to state "+yytable[yyn]);
        //#### NEXT STATE ####
        yystate = yytable[yyn];//we are in a new state
        state_push(yystate);   //save it
        val_push(yylval);      //push our lval as the input for next rule
        yychar = -1;           //since we have 'eaten' a token, say we need another
        if (yyerrflag > 0)     //have we recovered an error?
           --yyerrflag;        //give ourselves credit
        doaction=false;        //but don't process yet
        break;   //quit the yyn=0 loop
        }

    yyn = yyrindex[yystate];  //reduce
    if ((yyn !=0 ) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
      {   //we reduced!
      if (yydebug) debug("reduce");
      yyn = yytable[yyn];
      doaction=true; //get ready to execute
      break;         //drop down to actions
      }
    else //ERROR RECOVERY
      {
      if (yyerrflag==0)
        {
        yyerror("syntax error");
        yynerrs++;
        }
      if (yyerrflag < 3) //low error count?
        {
        yyerrflag = 3;
        while (true)   //do until break
          {
          if (stateptr<0)   //check for under & overflow here
            {
            yyerror("stack underflow. aborting...");  //note lower case 's'
            return 1;
            }
          yyn = yysindex[state_peek(0)];
          if ((yyn != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
            if (yydebug)
              debug("state "+state_peek(0)+", error recovery shifting to state "+yytable[yyn]+" ");
            yystate = yytable[yyn];
            state_push(yystate);
            val_push(yylval);
            doaction=false;
            break;
            }
          else
            {
            if (yydebug)
              debug("error recovery discarding state "+state_peek(0)+" ");
            if (stateptr<0)   //check for under & overflow here
              {
              yyerror("Stack underflow. aborting...");  //capital 'S'
              return 1;
              }
            state_pop();
            val_pop();
            }
          }
        }
      else            //discard this token
        {
        if (yychar == 0)
          return 1; //yyabort
        if (yydebug)
          {
          yys = null;
          if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
          if (yys == null) yys = "illegal-symbol";
          debug("state "+yystate+", error recovery discards token "+yychar+" ("+yys+")");
          }
        yychar = -1;  //read another
        }
      }//end error recovery
    }//yyn=0 loop
    if (!doaction)   //any reason not to proceed?
      continue;      //skip action
    yym = yylen[yyn];          //get count of terminals on rhs
    if (yydebug)
      debug("state "+yystate+", reducing "+yym+" by rule "+yyn+" ("+yyrule[yyn]+")");
    if (yym>0)                 //if count of rhs not 'nil'
      yyval = val_peek(yym-1); //get current semantic value
    yyval = dup_yyval(yyval); //duplicate yyval if ParserVal is used as semantic value
    switch(yyn)
      {
//########## USER-SUPPLIED ACTIONS ##########
case 4:
//#line 29 "logoyacc.y"
{yyval = val_peek(1);}
break;
case 5:
//#line 30 "logoyacc.y"
{yyval = val_peek(0);}
break;
case 6:
//#line 31 "logoyacc.y"
{yyval = val_peek(2);}
break;
case 7:
//#line 32 "logoyacc.y"
{yyval = val_peek(1);}
break;
case 8:
//#line 35 "logoyacc.y"
{		yyval = new ParserVal(machine.agregarOperacion("varPush_Eval")); 
				machine.agregar(val_peek(0).sval);
		}
break;
case 9:
//#line 38 "logoyacc.y"
{
				yyval = new ParserVal(machine.agregarOperacion("negativo"));
			}
break;
case 10:
//#line 41 "logoyacc.y"
{
				yyval = new ParserVal(machine.agregarOperacion("constPush"));
				machine.agregar(val_peek(0).dval);
			}
break;
case 11:
//#line 45 "logoyacc.y"
{
				yyval = new ParserVal(val_peek(0).ival);
				machine.agregarOperacion("varPush");
                                machine.agregar(val_peek(2).sval);
                                machine.agregarOperacion("asignar");
                                machine.agregarOperacion("varPush_Eval"); 
				machine.agregar(val_peek(2).sval);
			}
break;
case 12:
//#line 53 "logoyacc.y"
{
				yyval = new ParserVal(val_peek(2).ival);
				machine.agregarOperacion("MUL");
			}
break;
case 13:
//#line 57 "logoyacc.y"
{
				yyval = new ParserVal(val_peek(2).ival);
				machine.agregarOperacion("SUM");
			}
break;
case 14:
//#line 61 "logoyacc.y"
{
				yyval = new ParserVal(val_peek(2).ival);
				machine.agregarOperacion("RES");
			}
break;
case 15:
//#line 65 "logoyacc.y"
{
				yyval = new ParserVal(val_peek(1).ival);
			}
break;
case 16:
//#line 68 "logoyacc.y"
{
				machine.agregarOperacion("EQ");
				yyval = val_peek(2);
			}
break;
case 17:
//#line 72 "logoyacc.y"
{
				machine.agregarOperacion("NE");
				yyval = val_peek(2);
			}
break;
case 18:
//#line 76 "logoyacc.y"
{
				machine.agregarOperacion("LE");
				yyval = val_peek(2);
			}
break;
case 19:
//#line 80 "logoyacc.y"
{
				machine.agregarOperacion("LQ");
				yyval = val_peek(2);
			}
break;
case 20:
//#line 84 "logoyacc.y"
{
				machine.agregarOperacion("GR");
				yyval = val_peek(2);
			}
break;
case 21:
//#line 88 "logoyacc.y"
{
				machine.agregarOperacion("GE");
				yyval = val_peek(2);
			}
break;
case 22:
//#line 92 "logoyacc.y"
{
				machine.agregarOperacion("AND");
				yyval = val_peek(2);
			}
break;
case 23:
//#line 96 "logoyacc.y"
{
				machine.agregarOperacion("OR");
				yyval = val_peek(2);
			}
break;
case 24:
//#line 100 "logoyacc.y"
{
				machine.agregarOperacion("NOT");
				yyval = val_peek(0);
			}
break;
case 25:
//#line 104 "logoyacc.y"
{ yyval = val_peek(0); machine.agregarOperacion("_return"); }
break;
case 26:
//#line 106 "logoyacc.y"
{ yyval = new ParserVal(machine.agregarOperacion("push_parametro")); machine.agregar((int)val_peek(0).ival); }
break;
case 27:
//#line 108 "logoyacc.y"
{ yyval = new ParserVal(machine.agregarOperacionEn("invocar",(val_peek(3).ival))); machine.agregar(null); }
break;
case 29:
//#line 112 "logoyacc.y"
{yyval = val_peek(0); machine.agregar("Limite");}
break;
case 30:
//#line 113 "logoyacc.y"
{yyval = val_peek(2); machine.agregar("Limite");}
break;
case 31:
//#line 116 "logoyacc.y"
{yyval = new ParserVal(machine.agregarOperacion("nop"));}
break;
case 32:
//#line 119 "logoyacc.y"
{
				yyval = val_peek(13);
				machine.agregar(val_peek(7).ival, val_peek(13).ival + 1);
				machine.agregar(val_peek(2).ival, val_peek(13).ival + 2);
				machine.agregar(machine.numeroDeElementos() - 1, val_peek(13).ival + 3);
		}
break;
case 33:
//#line 125 "logoyacc.y"
{
				yyval = val_peek(10);
				machine.agregar(val_peek(4).ival, val_peek(10).ival + 1);
				machine.agregar(val_peek(1).ival, val_peek(10).ival + 2);
				machine.agregar(machine.numeroDeElementos() - 1, val_peek(10).ival + 3);
			}
break;
case 34:
//#line 131 "logoyacc.y"
{
				yyval = val_peek(9);
				machine.agregar(val_peek(3).ival, val_peek(9).ival + 1);
				machine.agregar(val_peek(0).ival, val_peek(9).ival + 2);
			}
break;
case 35:
//#line 136 "logoyacc.y"
{
				yyval = val_peek(15);
				machine.agregar(val_peek(10).ival, val_peek(15).ival + 1);
				machine.agregar(val_peek(7).ival, val_peek(15).ival + 2);
				machine.agregar(val_peek(3).ival, val_peek(15).ival + 3);
				machine.agregar(val_peek(0).ival, val_peek(15).ival + 4);
		}
break;
case 38:
//#line 145 "logoyacc.y"
{ 
				yyval = new ParserVal(val_peek(4).ival);
				machine.agregar(null);
		}
break;
case 39:
//#line 150 "logoyacc.y"
{
			yyval = new ParserVal(machine.agregar((Funcion)(val_peek(0).obj)));/*Llamada a funcion */
		}
break;
case 40:
//#line 155 "logoyacc.y"
{ machine.agregarOperacion("declaracion"); }
break;
case 41:
//#line 157 "logoyacc.y"
{ machine.agregarOperacion("declaracion"); }
break;
case 42:
//#line 160 "logoyacc.y"
{yyval = new ParserVal(machine.agregar(val_peek(0).sval));}
break;
case 43:
//#line 163 "logoyacc.y"
{machine.agregar(null);}
break;
case 44:
//#line 166 "logoyacc.y"
{yyval = new ParserVal(machine.agregarOperacion("stop"));}
break;
case 45:
//#line 169 "logoyacc.y"
{
		yyval = new ParserVal(machine.agregarOperacion("IF_ELSE"));
	        machine.agregarOperacion("stop");/*then*/
	        machine.agregarOperacion("stop");/*else*/
	        machine.agregarOperacion("stop");/*siguiente comando*/
		}
break;
case 46:
//#line 177 "logoyacc.y"
{
			yyval = new ParserVal(machine.agregarOperacion("WHILE"));
	        machine.agregarOperacion("stop");/*cuerpo*/
	        machine.agregarOperacion("stop");/*final*/
		}
break;
case 47:
//#line 184 "logoyacc.y"
{
			yyval = new ParserVal(machine.agregarOperacion("FOR"));
	        machine.agregarOperacion("stop");/*condicion*/
	        machine.agregarOperacion("stop");/*instrucción final*/
	        machine.agregarOperacion("stop");/*cuerpo*/
	        machine.agregarOperacion("stop");/*final*/
		}
break;
case 48:
//#line 192 "logoyacc.y"
{ yyval = new ParserVal(machine.agregarOperacion("nop"));}
break;
case 49:
//#line 193 "logoyacc.y"
{yyval = val_peek(0);}
break;
case 50:
//#line 194 "logoyacc.y"
{yyval = val_peek(2);}
break;
//#line 987 "Parser.java"
//########## END OF USER-SUPPLIED ACTIONS ##########
    }//switch
    //#### Now let's reduce... ####
    if (yydebug) debug("reduce");
    state_drop(yym);             //we just reduced yylen states
    yystate = state_peek(0);     //get new state
    val_drop(yym);               //corresponding value drop
    yym = yylhs[yyn];            //select next TERMINAL(on lhs)
    if (yystate == 0 && yym == 0)//done? 'rest' state and at first TERMINAL
      {
      if (yydebug) debug("After reduction, shifting from state 0 to state "+YYFINAL+"");
      yystate = YYFINAL;         //explicitly say we're done
      state_push(YYFINAL);       //and save it
      val_push(yyval);           //also save the semantic value of parsing
      if (yychar < 0)            //we want another character?
        {
        yychar = yylex();        //get next character
        if (yychar<0) yychar=0;  //clean, if necessary
        if (yydebug)
          yylexdebug(yystate,yychar);
        }
      if (yychar == 0)          //Good exit (if lex returns 0 ;-)
         break;                 //quit the loop--all DONE
      }//if yystate
    else                        //else not done yet
      {                         //get next state and push, for next yydefred[]
      yyn = yygindex[yym];      //find out where to go
      if ((yyn != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn]; //get new state
      else
        yystate = yydgoto[yym]; //else go to new defred
      if (yydebug) debug("after reduction, shifting from state "+state_peek(0)+" to state "+yystate+"");
      state_push(yystate);     //going again, so push state & val...
      val_push(yyval);         //for next action
      }
    }//main loop
  return 0;//yyaccept!!
}
//## end of method parse() ######################################



//## run() --- for Thread #######################################
/**
 * A default run method, used for operating this parser
 * object in the background.  It is intended for extending Thread
 * or implementing Runnable.  Turn off with -Jnorun .
 */
public void run()
{
  yyparse();
}
//## end of method run() ########################################



//## Constructors ###############################################
/**
 * Default constructor.  Turn off with -Jnoconstruct .

 */
public Parser()
{
  //nothing to do
}


/**
 * Create a parser, setting the debug to true or false.
 * @param debugMe true for debugging, false for no debug.
 */
public Parser(boolean debugMe)
{
  yydebug=debugMe;
}
//###############################################################



}
//################### END OF CLASS ##############################
