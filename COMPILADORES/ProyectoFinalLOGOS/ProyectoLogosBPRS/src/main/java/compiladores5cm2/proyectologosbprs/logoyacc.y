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
%{
        package compiladores5cm2.proyectologosbprs;

	import java.lang.Math;
	import java.io.*;
	import java.util.StringTokenizer;
%}

%token IF ELSE WHILE FOR FUNC RETURN PARAMETRO PROC FNCT NUMBER VAR
%token AND OR COMP DIFERENTES MAY MEN MAYI MENI
%right '='
%left '+' '-'
%left '*'
%left ';'
%left COMP
%left DIFERENTES
%left MAY
%left MAYI
%left MEN
%left MENI
%left '!'
%left AND
%left OR
%right RETURN
%%
	list:   
		| list'\n'
	  	| list linea '\n'
		;

	linea:  exp ';' {$$ = $1;}
		|stmt {$$ = $1;}
		|linea exp ';' {$$ = $1;}
		|linea stmt {$$ = $1;}
		;
		
	exp:    VAR {		$$ = new ParserVal(machine.agregarOperacion("varPush_Eval")); 
				machine.agregar($1.sval);
		}
		|'-' exp {
				$$ = new ParserVal(machine.agregarOperacion("negativo"));
			}
		|NUMBER {
				$$ = new ParserVal(machine.agregarOperacion("constPush"));
				machine.agregar($1.dval);
			}
		| VAR '=' exp {
				$$ = new ParserVal($3.ival);
				machine.agregarOperacion("varPush");
                                machine.agregar($1.sval);
                                machine.agregarOperacion("asignar");
                                machine.agregarOperacion("varPush_Eval"); 
				machine.agregar($1.sval);
			}
		| exp '*' exp {
				$$ = new ParserVal($1.ival);
				machine.agregarOperacion("MUL");
			}
		| exp '+' exp {
				$$ = new ParserVal($1.ival);
				machine.agregarOperacion("SUM");
			}
		| exp '-' exp {
				$$ = new ParserVal($1.ival);
				machine.agregarOperacion("RES");
			}
		|'(' exp ')' {
				$$ = new ParserVal($2.ival);
			}
		| exp COMP exp {
				machine.agregarOperacion("EQ");
				$$ = $1;
			}
		| exp DIFERENTES exp {
				machine.agregarOperacion("NE");
				$$ = $1;
			}
		| exp MEN exp {
				machine.agregarOperacion("LE");
				$$ = $1;
			}
		| exp MENI exp {
				machine.agregarOperacion("LQ");
				$$ = $1;
			}
		| exp MAY exp {
				machine.agregarOperacion("GR");
				$$ = $1;
			}
		| exp MAYI exp {
				machine.agregarOperacion("GE");
				$$ = $1;
			}
		| exp AND exp {
				machine.agregarOperacion("AND");
				$$ = $1;
			}
		| exp OR exp {
				machine.agregarOperacion("OR");
				$$ = $1;
			}
		| '!' exp {
				machine.agregarOperacion("NOT");
				$$ = $2;
			}
		| RETURN exp { $$ = $2; machine.agregarOperacion("_return"); } 
		
		| PARAMETRO { $$ = new ParserVal(machine.agregarOperacion("push_parametro")); machine.agregar((int)$1.ival); }
		
		|nombreProc '(' arglist ')' { $$ = new ParserVal(machine.agregarOperacionEn("invocar",($1.ival))); machine.agregar(null); } //instrucciones tiene la estructura necesaria para la lista de argumentos

		;//Lamada a Procedimiento
		
	arglist: 
		|exp {$$ = $1; machine.agregar("Limite");}
		|arglist ',' exp {$$ = $1; machine.agregar("Limite");}
		;
	
	nop:    {$$ = new ParserVal(machine.agregarOperacion("nop"));}
		;
	
	stmt:   if '(' exp stop ')' '{' linea stop '}' ELSE '{' linea stop'}' {
				$$ = $1;
				machine.agregar($7.ival, $1.ival + 1);
				machine.agregar($12.ival, $1.ival + 2);
				machine.agregar(machine.numeroDeElementos() - 1, $1.ival + 3);
		}
		| if '(' exp stop ')' '{' linea stop '}' nop stop{
				$$ = $1;
				machine.agregar($7.ival, $1.ival + 1);
				machine.agregar($10.ival, $1.ival + 2);
				machine.agregar(machine.numeroDeElementos() - 1, $1.ival + 3);
			}
		| while '(' exp stop ')' '{' linea stop '}' stop{
				$$ = $1;
				machine.agregar($7.ival, $1.ival + 1);
				machine.agregar($10.ival, $1.ival + 2);
			}
		| for '(' instrucciones stop ';' exp stop ';' instrucciones stop ')' '{' linea stop '}' stop{
				$$ = $1;
				machine.agregar($6.ival, $1.ival + 1);
				machine.agregar($9.ival, $1.ival + 2);
				machine.agregar($13.ival, $1.ival + 3);
				machine.agregar($16.ival, $1.ival + 4);
		}
		| funcion nombreProc '(' ')' '{' linea null '}'
		| procedimiento nombreProc '(' ')' '{' linea null '}'
		| instruccion '[' arglist ']' ';' { 
				$$ = new ParserVal($1.ival);
				machine.agregar(null);
		}

        instruccion: FNCT {
			$$ = new ParserVal(machine.agregar((Funcion)($1.obj)));
            

		}
		;

	procedimiento: PROC { machine.agregarOperacion("declaracion"); }
		;
	funcion: FUNC { machine.agregarOperacion("declaracion"); }
		;
		
	nombreProc: VAR {$$ = new ParserVal(machine.agregar($1.sval));}

		;

		
	null: {machine.agregar(null);}
		;
		
	stop: {$$ = new ParserVal(machine.agregarOperacion("stop"));} 
		;

	if: IF {
		$$ = new ParserVal(machine.agregarOperacion("IF_ELSE"));
	        machine.agregarOperacion("stop");//then
	        machine.agregarOperacion("stop");//else
	        machine.agregarOperacion("stop");//siguiente comando
		}
		;

	while: WHILE {
			$$ = new ParserVal(machine.agregarOperacion("WHILE"));
	        machine.agregarOperacion("stop");//cuerpo
	        machine.agregarOperacion("stop");//final
		}
		;

	for : FOR {
			$$ = new ParserVal(machine.agregarOperacion("FOR"));
	        machine.agregarOperacion("stop");//condicion
	        machine.agregarOperacion("stop");//instrucción final
	        machine.agregarOperacion("stop");//cuerpo
	        machine.agregarOperacion("stop");//final
		}		

	instrucciones: { $$ = new ParserVal(machine.agregarOperacion("nop"));}
		|exp {$$ = $1;}
		|instrucciones ',' exp {$$ = $1;}
		;



%%
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
	sym.insert("GIRA", new Code.Girar());
	sym.insert("AVANZA", new Code.Avanzar());
	sym.insert("DIBUJA", new Code.CambiarColor());
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

