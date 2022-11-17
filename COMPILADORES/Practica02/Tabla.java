/*
    |-------------------------------------------|
    |            Datos del alumno               |
    |   Nombre: Eduardo Sandoval Hernández      |
    |   Practica número: 2                      |
    |   Tema: Uso de Java para modo gráfico     |
    |   Opcion: Dibujo de circulos, lineas y	|
    |           rectangulos                     |
    |   Fecha de entrega: 22 de abril de 2022   |
    |   Grupo: 5CM2                             |
    |   Materia: Compiladores                   |
    |-------------------------------------------|
*/
//package compiladores.parser;  //<= Para ejecutar en NetBeans

public class Tabla {
	Simbolo listaSimbolo;
	Tabla(){
		listaSimbolo=null;
	}

    Simbolo install(String s, short t, double d){
		Simbolo simb=new Simbolo(s,t,d);
		simb.ponSig(listaSimbolo);
		listaSimbolo=simb;
		return simb;
	}

    Simbolo lookup(String s){
	    for(Simbolo sp=listaSimbolo; sp!=null; sp=sp.obtenSig())
		    if((sp.obtenNombre()).equals(s))
			    return sp;
	    return null;
	}
}
