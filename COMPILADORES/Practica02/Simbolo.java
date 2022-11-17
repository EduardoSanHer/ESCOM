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

class Simbolo {
	String nombre;
	public short tipo;
	double val;
	public String metodo;
	int defn;
	Simbolo sig;

	Simbolo(String s, short t, double d){
		nombre=s;
		tipo=t;
		val=d;
	}
    public Simbolo obtenSig(){
		return sig;
	}
    public void ponSig(Simbolo s){
		sig=s;
	}
    public String obtenNombre(){
		return nombre;
	}
}