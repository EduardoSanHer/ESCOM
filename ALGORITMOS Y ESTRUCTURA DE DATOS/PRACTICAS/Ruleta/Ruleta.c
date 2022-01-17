//Sandoval Hernández Eduardo - 2020630632
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Elem.h"
#include"ColaCir.h"


typedef Circular Ruleta;
int Absoluto(int);
Ruleta NuevaRuleta(int);
int CantApuesta();
int TipoApuesta();
int MultApuesta(int,int*,char);
int NumApuesta(int,char);
Circular AuxCuadro(Elem,Elem,Elem,Elem);
Circular Cuadro(Elem);
Circular AuxFila(Elem,Elem,Elem);
Circular Fila(Elem);
Circular Columna(Elem);
Circular ValoresApuesta(Circular,int,char);
int Giro(Ruleta);
int Resultado(Ruleta);
int GanaOPierde(int,Circular,int);

int main(){
    srand(time(NULL));
    int a=0,Ta,Na=0,Res;
    Ruleta R=nuevaC();
    R=NuevaRuleta(37);

    while(1){
        Circular Val=nuevaC();
        a=CantApuesta();
        Ta=TipoApuesta();
        getchar();
        a=MultApuesta(a,&Na,Ta);
        Val=ValoresApuesta(Val,Na,Ta);
        printf("-------------\n Su apuesta: \t");
        ImpColaC(Val,Na);
        puts("\n-------------");
        Res=Resultado(R);
        GanaOPierde(a,Val,Res);
    }

    return 0;
}

//Forma la ruleta con el orden indicado (el 100 equivale al 00)
//Los numeros negativos equivalen a numeros negros
Ruleta NuevaRuleta(int n){
    int i,A[]={0,28,-9,26,-30,11,-7,20,-32,17,-5,22,-34,15,-3,24,-36,13,
        -1,100,-27,10,-25,29,-12,8,-19,31,-18,6,-21,33,-16,4,-23,35,-14,2};
    Ruleta R=nuevaC();
    for(i=0 ; i<n ; i++)
        R=formarC(R,A[i]);
    return R;
}

//Pregunta la cantidad (de dinero) que desea apostar
int CantApuesta(){
    printf("**Bienvenido***\n***Cuanto desea apostar***\n");
    return LeeElem();
}


//Pregunta a que desea apostar
int TipoApuesta(){
    int ta;
    printf("**A que quiere apostar\n");
    printf("\t1)Numeros Pares\n\t2)Numeros Impares\n");
    printf("\t3)Un numero\n\t4)Dos numeros\n");
    printf("\t5)Una Fila\n\t6)Un Cuadro\n");
    printf("\t7)Una Columna\n\t8)Docena\n");
    printf("\t9)Los Cuatro primeros\n");
    printf("\t10)Los cinco primeros\n\t11)Rojo\n");
    printf("\t12)Negro\n\t13)Falta\n");
    printf("\t14)Pasa\n\t15)Cero\n\t16)Doble Cero\n");
    printf("Seleccione un tipo de apuesta: \t");
    ta=LeeElem();
    if(!(ta<17 && ta>0))
        return TipoApuesta();
    return ta;
}

//Regresa el valor de la apuesta (de dinero) dependiendo el tipo de apuesta
//Asi como el cantidad de numeros a los que apuesta
int MultApuesta(int a, int *Na, char ta){
    switch(ta){
        case 1: case 2: case 11: case 12: case 13: case 14: a=a;   *Na=18;
            break;
        case 3: case 15: case 16: a*=35;    *Na=1;
            break;
        case 4: a*=17;    *Na=2;
            break;
        case 5: a*=11;    *Na=3;
            break;
        case 6: case 9: a*=8;     *Na=4;
            break;
        case 10: a*=6;     *Na=5;
            break;
        case 7: case 8: a*=2;     *Na=12;
            break;
    }
    return a;
}

//Auxiliar de la funcion Cuadro, forma los cuatro elementos que se le envían
Circular AuxCuadro(Elem a, Elem b, Elem c, Elem d){
    return formarC(formarC(formarC(formarC(nuevaC(),a),b),c),d);
}

Circular Cuadro(Elem e){
    switch(e){
        case 1: return AuxCuadro(-1,2,4,-5);  break;
        case 2: return AuxCuadro(2,-3,-5,6);  break;
        case 3: return AuxCuadro(-7,8,10,11);  break;
        case 4: return AuxCuadro(8,-9,11,-12);  break;
        case 5: return AuxCuadro(13,-14,-16,17);  break;
        case 6: return AuxCuadro(-14,15,17,-18);  break;
        case 7: return AuxCuadro(-19,20,22,-23);  break;
        case 8: return AuxCuadro(20,-21,-23,24);  break;
        case 9: return AuxCuadro(-25,26,28,29);  break;
        case 10: return AuxCuadro(26,-27,29,-30);  break;
        case 11: return AuxCuadro(31,-32,-34,35);  break;
        case 12: return AuxCuadro(-32,33,35,-36);   break;
        default: return Cuadro(LeeElem());  break;
    }
}

Circular AuxFila(Elem a,Elem b, Elem c){
    return formarC(formarC(formarC(nuevaC(),a),b),c);
}

Circular Fila(Elem e){
    switch(e){
    case 1:     return AuxFila(-1,2,-3);     break;
    case 2:     return AuxFila(4,-5,6);     break;
    case 3:     return AuxFila(-7,8,-9);     break;
    case 4:     return AuxFila(10,11,-12);     break;
    case 5:     return AuxFila(13,-14,15);     break;
    case 6:     return AuxFila(-16,17,-18);     break;
    case 7:     return AuxFila(-19,20,-21);     break;
    case 8:     return AuxFila(22,-23,24);     break;
    case 9:     return AuxFila(-25,26,-27);     break;
    case 10:     return AuxFila(28,29,-30);     break;
    case 11:     return AuxFila(31,-32,33);     break;
    case 12:     return AuxFila(-34,35,-36);     break;
    default:    return Fila(LeeElem());     break;
    }
}

Circular Columna(Elem e){
    int i,k=e;
    if(e>0 && e<4){
        Circular t = nuevaC();
        for(i=1;i<=12;i++){
            t=formarC(t,k);
            k+=3;
        }
        return t;
    }
    else
        return Columna(LeeElem());
}

//Esta funcion ayuda a saber a que numeros se esta apostando
Circular ValoresApuesta(Circular Val, int Na, char ta){
    int i,A[]={0,28,-9,26,-30,11,-7,20,-32,17,-5,22,-34,15,-3,24,-36,13,
        -1,100,-27,10,-25,29,-12,8,-19,31,-18,6,-21,33,-16,4,-23,35,-14,2};

    switch(ta){
        case 1:
            for(i=2;i<=36;i+=2)
                Val=formarC(Val,i);
            break;
        case 2:
            for(i=1;i<=35;i+=2)
                Val=formarC(Val,i);
            break;
        case 9:
            for(i=1;i<=4;i++)
                Val=formarC(Val,i);
            break;
        case 10:
            for(i=1;i<=5;i++)
                Val=formarC(Val,i);
            break;
        case 13:
            for(i=1;i<=18;i++)
                Val=formarC(Val,i);
            break;
        case 11:
            for(i=0;i<37;i++)
                if(A[i]<0)
                    Val=formarC(Val,A[i]);
            break;
        case 12:
            for(i=0;i<37;i++)
                if(100>A[i]&&A[i]>0)
                    Val=formarC(Val,A[i]);
            break;
        case 14:
            for(i=19;i<=36;i++)
                Val=formarC(Val,i);
            break;
        case 15:
            Val=formarC(Val,0);
            break;
        case 16:
            Val=formarC(Val,100);
            break;
        case 5:
            printf("Introduzca el numero de la fila: ");
            Val=Fila(LeeElem());
            break;
        case 6:
            printf("Introduzca el numero del cuadro: ");
            Val=Cuadro(LeeElem());
            break;
        case 7:
            printf("Introduzca el numero de la columna: ");
            Val=Columna(LeeElem());
            break;
        default:
            printf("Introduzca los numeros a apostar\n");
            for(i=1;i<=Na;i++){
                Val=formarC(Val,LeeElem());
            }
    }
    return Val;
}

//Hace el giro de la ruleta
int Giro(Ruleta r){
    int i;
    for(i=0;i<=rand();i++)
        r=rotacionC(r);
    return primeroC(r);
}

//Regresa el resultado de la ruleta
int Resultado(Ruleta R){
    int Res=Giro(R);
    if(Res==100)//100 Equivale al 00
        printf("\t###El resultado es: %d%d ###\n",0,0);
    else
        printf("\t###El resultado es: %d ###\n",Absoluto(Res));
    return Res;
}

//Determina si el jugador gano o perdio, de ser el primer caso muestra la cantidad (de dinero) que ha ganado
int GanaOPierde(int a, Circular Val, int Res){
    if(esvaciaC(Val))
        printf("\t****Suerte para la proxima****\n");
    else if(Absoluto(primeroC(Val))==Absoluto(Res)){
        printf("\t====Felicidades has ganado====\n");
        printf("\t====Ganas %d pesos====\n",a);
    }
    else
        GanaOPierde(a,desformarC(Val),Res);
}
