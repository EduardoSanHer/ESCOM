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


import java.awt.*;

public class Circulo implements Dibujable {
	private int x=0;
	private int y=0;
	private int r=0;

	public Circulo(int x, int y, int r){
		this.x=x;
		this.y=y;
		this.r=r;
	}

	public void dibuja(Graphics g){
		g.drawOval(x,y,r,r);
	}
}