//Sandoval Hern�ndez Eduardo - 2020630632
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Elem.h"
#include"ColaCirBackgammon.h"
#include"BiCola.h"

typedef Circular Dado;
typedef BiCola *Torre;
typedef BiCola *Salida;

Dado FormaDado();
int Tirada(Dado);
Torre CreaTorres();
Torre pruebagana();
void MostrarTablero(Torre,Salida);
void EspaciosF(BiCola,int);
void MostrarFila(Torre,int,int);
int QuienEmpieza(Dado);
int Juego(Torre,Salida,Dado,int);
void Cambio(Torre,Salida,int,int);
int reglasCambio(Torre,Salida,int,int,int,int);
int reglasSacar(Torre,Salida,int);

int main(){
    int Num;
    srand(time(NULL));
    //Crea el dado
    Dado Dados=nuevaC();
    Dados=FormaDado();
    //Crea las salidas para las fichas
    Salida S=(Salida)malloc(sizeof(BiCola)*2);
    S[0]=nuevaB();
    S[1]=nuevaB();
    //Crea las torres con las fichas iniciales
    Torre Torres=CreaTorres();
    //Torre Torres=pruebagana();
    MostrarTablero(Torres,S);
    //Primera tirada
    Num = QuienEmpieza(Dados);
    //Comienza el juego
    do{
        Num = Juego(Torres,S,Dados,Num);
        /*if(Num==1)
            Num = 2;
        else
            Num = 1;*/
        //MostrarTablero(Torres,S);
    }while(Num!=0);

    return 0;
}

//Crea el dado;
Dado FormaDado(){
    int i;
    Dado D = nuevaC();
    for(i=1;i<=6;i++)
        D=formarC(i,D);
    return D;
}

//Hace la tirada del dado
int Tirada(Dado d){
    int i;
    for(i=0;i<=rand();i++)
        d=rotacionC(d);
    return primeroC(d);
}

//Inicia el tablero
Torre CreaTorres(){
    Torre T=(Torre)malloc(sizeof(BiCola)*26);
    for(int i=0;i<=25;i++)
        T[i]=nuevaB();
    T[1]=formarI(1,formarI(1,T[1]));
    T[6]=formarI(2,formarI(2,formarI(2,formarI(2,formarI(2,T[6])))));
    T[8]=formarI(2,formarI(2,formarI(2,T[8])));
    T[12]=formarI(1,formarI(1,formarI(1,formarI(1,formarI(1,T[12])))));
    T[13]=formarI(2,formarI(2,formarI(2,formarI(2,formarI(2,T[13])))));//T[6];
    T[17]=formarI(1,formarI(1,formarI(1,T[17])));
    T[19]=formarI(1,formarI(1,formarI(1,formarI(1,formarI(1,T[19])))));//T[12];
    T[24]=formarI(2,formarI(2,T[24]));
    return T;
}


//Creada para hacer una partida rapida y ver errores
Torre pruebagana(){
    Torre T=(Torre)malloc(sizeof(BiCola)*26);
    for(int i=0;i<=25;i++)
        T[i]=nuevaB();
    T[1]=formarI(1,T[1]);
    T[3]=formarI(2,formarI(2,formarI(2,formarI(2,formarI(2,T[3])))));
    T[4]=formarI(2,formarI(2,formarI(2,formarI(2,formarI(2,T[4])))));
    T[5]=formarI(2,formarI(2,formarI(2,formarI(2,formarI(2,T[5])))));
    return T;
}

//Muestra el tablero completo
void MostrarTablero(Torre T, Salida S){
    printf("____________________________________________________________________________________________\n");
    printf("Salida Dos:");
    MostrarFila(S,0,1);
    printf(":Salida Unos");
    printf("\n____________________________________________________________________________________________\n");
    for(int i=1;i<=12;i++){
        printf("Torre[%d]:",i);
        MostrarFila(T,i,25-i);
        printf(":Torre[%d]",25-i);
        if(i==6){
            printf("\n____________________________________________________________________________________________\n");
            printf("Torre[0]:");
            MostrarFila(T,0,25);
            printf(":Torre[25]");
            printf("\n____________________________________________________________________________________________\n");
        }
        if(i==12)
            printf("\n____________________________________________________________________________________________");
        printf("\n");
    }
}

//Muesta solo una fila del tablero
void MostrarFila(Torre T, int i, int k){
    if(!esnuevaB(T[i])&&!esnuevaB(T[k])){
        ImpBiCola(T[i]);
        EspaciosF(T[i],i);
        printf("|\t|");
        EspaciosF(T[k],k);
        ImpBiCola(T[k]);
    }
    else if(!esnuevaB(T[i])&&esnuevaB(T[k])){
        ImpBiCola(T[i]);
        EspaciosF(T[i],i);
        printf("|\t|");
        EspaciosF(T[k],k);
    }
    else if(esnuevaB(T[i])&&!esnuevaB(T[k])){
        EspaciosF(T[i],i);
        printf("|\t|");
        EspaciosF(T[k],k);
        ImpBiCola(T[k]);
    }
    else{
        EspaciosF(T[i],i);
        printf("|\t|");
        EspaciosF(T[k],k);
    }
}

//Imprime los espacios faltantes por fila
void EspaciosF(BiCola B,int i){
    int j;
    for(j=NumElems(B);j<15;j++)
        printf("- ");
    if(i<10)
        printf(" ");
}

//Determina quien empieza la partida
int QuienEmpieza(Dado D){
    int r,c1,c2;
    c1=Tirada(D)+Tirada(D);
    c2=Tirada(D)+Tirada(D);
    printf("Jugador de 1: %d\n",c1);
    printf("Jugador de 2: %d\n",c2);
    if(c1==c2)
        return r=QuienEmpieza(D);
    else if(c1>c2){
        printf("**Inicia el jugador de 1**\n");
        return r=1;
    }
    else{
        printf("**Inicia el jugador de 2**\n");
        return r=2;
    }
}

//Funcion de juego principal
int Juego(Torre T, Salida S, Dado D, int Num){
    int Dado_1,Dado_2;

    if(NumElems(S[0])<15 && NumElems(S[1])<15){
        printf("**Mueve jugador de %d**\n",Num);
        Dado_1=Tirada(D);
        Dado_2=Tirada(D);
        printf("Dado 1: %d\nDado 2: %d\n",Dado_1,Dado_2);
        printf("Movimientos dado 1: %d\n",Dado_1);
        Cambio(T,S,Num,Dado_1);
        MostrarTablero(T,S);
        printf("Movimientos dado 2: %d\n",Dado_2);
        Cambio(T,S,Num,Dado_2);
        MostrarTablero(T,S);
        if(Num==1)
            return 2;
        else
            return 1;
    }
    else{
        int g;
        printf("\t***El juego ha terminado***\n");
        if(Num==1)
            g=2;
        else
            g=1;
        printf("\t***===Gana el jugador de %d===***\n",g);
        return 0;
    }
}

//Funcion que mueve una ficha de una torre a otra
void Cambio(Torre T, Salida S, int Num, int M){
    int Ori,Dest;
    do{
        do{
            printf("Numero de torre Origen:");
            scanf("%d",&Ori);
            printf("Numero de torre Destino:");
            scanf("%d",&Dest);
        }while(Ori<0 || Ori>25 || Dest<0 || Dest>25);

        if(reglasCambio(T,S,Ori,Dest,Num,M)){

            //T[Ori]=desformarI(T[Ori]);
            //Esta parte desforma las fichas del lado derecho o izquierdo segun la perspectiva del tablero
            if(Ori<=12)
                T[Ori]=desformarD(T[Ori]);
            else
                T[Ori]=desformarI(T[Ori]);

            if(reglasSacar(T,S,Num) && Dest==0 && Num==2)
                S[Dest]=formarD(S[Dest],Num);
            else if(reglasSacar(T,S,Num) && Dest==25 && Num==1)
                S[1]=formarI(Num,S[1]);
            else if(!esnuevaB(T[Dest]) && (izquierdo(T[Dest])!=Num) && (NumElems(T[Dest])==1) && Dest!=0 && Dest!=25){
                if(Num==2)
                    T[0]=formarD(T[0],1);
                else
                    T[25]=formarI(2,T[25]);

                if(Dest<=12){
                    T[Dest]=desformarD(T[Dest]);
                    T[Dest]=formarD(T[Dest],Num);
                }
                else{
                    T[Dest]=desformarI(T[Dest]);
                    T[Dest]=formarI(Num,T[Dest]);
                }
            }
            else
                T[Dest]=formarI(Num,T[Dest]);
            M=0;
        }
        else if(Ori==Dest){
            printf("***Sin movimientos disponibles, pasa***\n");
            M=0;
        }
        else
            printf("***Movimiento no valido***\n");
    }while(M!=0);
}

//Funcion que determina si se cumplen las condiciones para hacer el cambio
int reglasCambio(Torre T, Salida S,int Ori,int Dest,int Num, int M){
    if(esnuevaB(T[Ori]) || derecho(T[Ori])!=Num)
        return 0;
    else if(!esnuevaB(T[Dest]) && (NumElems(T[Dest])>1) && derecho(T[Dest])!=Num )
        return 0;
    else if(Num==1 && Ori>=Dest)
        return 0;
    else if(Num==2 && Ori<=Dest)
        return 0;
    else if(M==6 && reglasSacar(T,S,Num))
        return 1;
    else if(!reglasSacar(T,S,Num) && (Dest==0 ||Dest==25))
        return 0;
    else if(Absoluto(Ori-Dest)!=M)
        return 0;
    else
        return 1;
}

//Funcion que determina si se cumplen las condiciones para sacar fichas
int reglasSacar(Torre T, Salida S,int Num){
    int i,cantElems=0;
    if(Num==1){
        for(i=1;i<=18;i++){
            if(NumElems(T[i])!=0 && izquierdo(T[i])==Num)
                cantElems+=NumElems(T[i]);
        }
    }
    else{
        for(i=7;i<=24;i++){
            if(NumElems(T[i])!=0 && izquierdo(T[i])==Num)
                cantElems+=NumElems(T[i]);
        }
    }
    //printf("Sacar %d Num %d\n",Num,cantElems);
    if(cantElems>0)
        return 0;
    else
        return 1;
}
