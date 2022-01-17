//Sandoval Hernandez Eduardo
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"Pila.h"

void imprime(Stack);
long int exp(long int,long int);
int chartoint(char);
char inttochar(int);
Stack dividir(Stack,char,int);
Stack agrega0(Stack,int);
int cantDigInt(int);
Stack intToStack(int,int);
int stackToInt(Stack,int);
Stack intToBin(int);
int binToInt(Stack,int);
long long int hexToInt(Stack,int);
Stack intToHex(long long int);
Stack sumaStacks(Stack,Stack,int);
int hazPotencia2(int);
int mayorNumchars(Stack,Stack);
long long int multiplica(Stack,Stack,int,int);

int main (){

    puts("*******BINARIO*******");
    puts("\n__Prueba 1__");
    Stack B1 = push('1',empty());
    Stack B2 = push('0',empty());
    int RB1B2 = multiplica(B1,B2,1,2);
    printf("Binario 1: ");
    imprime(B1);
    printf("Binario 2: ");
    imprime(B2);
    printf("Resultado decimal: %d\nResultado binario: ",RB1B2);
    imprime(intToBin(RB1B2));

    puts("\n__Prueba 2__");
    Stack B3 = push('1',push('1',push('0',push('1',push('0',empty())))));
    Stack B4 = push('1',push('0',push('1',push('0',empty()))));
    int RB3B4 = multiplica(B3,B4,5,2);
    printf("Binario 3: ");
    imprime(B3);
    printf("Binario 4: ");
    imprime(B4);
    printf("Resultado decimal: %d\nResultado binario: ",RB3B4);
    imprime(intToBin(RB3B4));

    puts("\n__Prueba 3__");
    Stack B5 = push('1',push('0',push('1',push('1',push('0',push('1',push('0',push('1',empty()))))))));
    Stack B6 = push('1',push('0',push('1',empty())));
    int RB5B6 = multiplica(B5,B6,8,2);
    printf("Binario 5: ");
    imprime(B5);
    printf("Binario 6: ");
    imprime(B6);
    printf("Resultado decimal: %d\nResultado binario: ",RB5B6);
    imprime(intToBin(RB5B6));

    puts("\n\n*******DECIMAL*******");
    puts("\n__Prueba 4__");
    Stack D1 = push('8',empty());
    Stack D2 = push('9',empty());
    int RD1D2 = multiplica(D1,D2,1,10);
    printf("Decimal 1: ");
    imprime(D1);
    printf("Decimal 2: ");
    imprime(D2);
    printf("Resultado decimal: %d\nResultado en stack: ",RD1D2);
    imprime(intToStack(RD1D2,cantDigInt(RD1D2)));

    puts("\n__Prueba 5__");
    Stack D3 = push('1',push('2',push('3',push('4',push('5',empty())))));
    Stack D4 = push('3',push('4',empty()));
    int RD3D4 = multiplica(D3,D4,5,10);
    printf("Decimal 3: ");
    imprime(D3);
    printf("Decimal 4: ");
    imprime(D4);
    printf("Resultado decimal: %d\nResultado en stack: ",RD3D4);
    imprime(intToStack(RD3D4,cantDigInt(RD3D4)));

    puts("\n__Prueba 6__");
    Stack D5 = push('1',push('2',push('3',push('4',push('5',push('6',push('7',empty())))))));
    Stack D6 = push('1',push('2',push('3',push('4',empty()))));
    int RD5D6 = multiplica(D5,D6,7,10);
    printf("Decimal 5: ");
    imprime(D5);
    printf("Decimal 6: ");
    imprime(D6);
    printf("Resultado decimal: %d\nResultado en stack: ",RD5D6);
    imprime(intToStack(RD5D6,cantDigInt(RD5D6)));

    puts("\n\n*******HEXADECIMAL*******");
    puts("\n__Prueba 7__");
    Stack H1 = push('A',empty());
    Stack H2 = push('4',empty());
    int RH1H2 = multiplica(H1,H2,1,16);
    printf("Hexadecimal 1: ");
    imprime(H1);
    printf("Hexadecimal 2: ");
    imprime(H2);
    printf("Resultado decimal: %d\nResultado hexadecimal: ",RH1H2);
    imprime(intToHex(RH1H2));

    puts("\n__Prueba 8__");
    Stack H3 = push('1',push('2',push('3',push('A',push('B',empty())))));
    Stack H4 = push('D',push('3',empty()));
    int RH3H4 = multiplica(H3,H4,5,16);
    printf("Hexadecimal 3: ");
    imprime(H3);
    printf("Hexadecimal 4: ");
    imprime(H4);
    printf("Resultado decimal: %d\nResultado hexadecimal: ",RH3H4);
    imprime(intToHex(RH3H4));

    puts("\n__Prueba 9__");
    Stack H5 = push('1',push('1',push('1',push('2',push('2',push('2',push('E',empty())))))));
    Stack H6 = push('1',push('2',push('C',push('D',empty()))));
    long long int RH5H6 = multiplica(H5,H6,7,16);
    printf("Hexadecimal 5: ");
    imprime(H5);
    printf("Hexadecimal 6: ");
    imprime(H6);
    printf("Resultado decimal: %lld\nResultado hexadecimal: ",RH5H6);
    imprime(intToHex(RH5H6));
    //imprime(intToHex(86153075414));

    return 0;
}

//Esta función sirve como complemento de Impchars ya que agrega un salto de linea al final
void imprime(Stack P){
    Impchars(P);
    printf("\n");
}

//Esta función regresa el resultado de elevar un entero "a" a una potencia "b"
long int exp(long int a, long int b){
    if(b==0)
        return 1;
    else
        return a*exp(a,b-1);
}

//Esta función regresa un char (desde 0 a 9 y de A a F) convertido a entero
int chartoint(char cc){
    if(isdigit(cc))
        return cc - '0';
    else
        return 10 + (toupper(cc) - 'A');
}

//Esta función hace lo contrario a la anterior pero solo con enteros del 0 al 9
char inttochar(int ii){
    return ii + '0';
}

//Esta función se encarga de dividir la pila a la mitad dependiento de que mitad se desea
Stack dividir(Stack S, char mitad, int n){
    int i;
    Stack aux = empty();
    if(mitad=='i'){
        for(i=0 ; i<n/2 ; i++){
            aux = push(top(S),aux);
            S = pop(S);
        }
    }
    else{
        for(i=0 ; i<n/2 ; i++)
            S = pop(S);
        for(i=n/2 ; i<n ; i++){
            aux = push(top(S),aux);
            S = pop(S);
        }
    }
    aux = InvierteStacks(aux);
    return aux;
}

//Esta función agrega n canditad de 0 a la pila P
Stack agrega0(Stack P, int n){
    for(int i=0 ; i<n ; i++)
        P = push('0',P);
    return P;

}

//Esta función determina la cantidad de digitos que tiene un entero
int cantDigInt(int n){
    int i = 1;
    while((n/10)>0){
        n/=10;
        i++;
    }
    return i;
}

//Esta función divide los dígitos de un entero en una pila
Stack intToStack(int v, int n){
    if(n==0)
        return empty();
    else{
        int aux = ((v - v%(exp(10,n-1)))/exp(10,n-1));
        //printf("Valor de aux: %d\n",aux);
        return push(inttochar(aux),intToStack(v%(exp(10,n-1)),n-1));
    }
}

//Esta función convierte una pila que representa un número decimal en un entero
int stackToInt(Stack s, int n){
    if(isempty(s))
        return 0;
    else
        return chartoint(top(s))*exp(10,n-1) +  stackToInt(pop(s),n-1);
}

//Esta función convierte un entero a una pila que representa el mismo número en binario
Stack intToBin(int num){
    if(num==0)
        return push('0',empty());
    else if(num==1)
        return push('1',empty());
    else if(num%2==0)
        return PegaStacks(intToBin(num/2),push('0',empty()));
    else
        return PegaStacks(intToBin(num/2),push('1',empty()));
}

//Esta función toma una pila que representa un binario y la convierte a un entero
int binToInt(Stack s, int n){
    if(isempty(s))
        return 0;
    else
        return chartoint(top(s))*exp(2,n-1) +  binToInt(pop(s),n-1);
}
//Esta función convierte una pila con hexadecimales a un entero
//Utiliza long long para enteros muy grandes como es el caso de la prueba 9
long long int hexToInt(Stack s, int n){
    if(isempty(s))
        return 0;
    else
        return chartoint(top(s))*exp(16,n-1) +  hexToInt(pop(s),n-1);
}

//Esta función convierte un entero a una pila que representa el mismo número en hexadecimal
Stack intToHex(long long int num){
    //printf("Valor intohex %d\n",num);
    if(num<16){
        if(num<10)
            return push(inttochar(num),empty());
        else
            return push(num+55,empty());
    }
    else if(num/16 != 0){
        if(num%16==0)
            return PegaStacks(intToHex(num/16),push('0',empty()));
        else if(num%16<10)
            return PegaStacks(intToHex(num/16),push(inttochar(num%16),empty()));
        else
            return PegaStacks(intToHex(num/16),push(num%16+55,empty()));
    }
}

//Esta función suma dos pilas que representan un número dependiendo su base
//y regresa dicho número como una pila en la base que se especifica
Stack sumaStacks(Stack s1, Stack s2, int base){
    if(base==2){
        int ss1 = binToInt(s1,Numchars(s1)), ss2 = binToInt(s2,Numchars(s2)), resultado;
        resultado = ss1 + ss2;
        return intToBin(resultado);
    }
    if(base==10){
        int ss1 = stackToInt(s1,Numchars(s1)), ss2 = stackToInt(s2,Numchars(s2)), resultado;
        resultado = ss1 + ss2;
        return intToStack(resultado,cantDigInt(resultado));
    }
    if(base==16){
        int ss1 = hexToInt(s1,Numchars(s1)), ss2 = hexToInt(s2,Numchars(s2)), resultado;
        resultado = ss1 + ss2;
        return intToHex(resultado);
    }
}

//Esta función determina si un entero num es potencia de 2 y si no regresa la potencia de 2
//siguiente a dicho número, ejemplo, si num = 5 entonces regresa 8.
int hazPotencia2(int num){
    int i = 2;
    if(num<=i)
        return num;
    else{
        while(1){
            i*=2;
            if(num<=i)
                return i;
        }
    }
}

//Esta función determina cuál de los pilas tiene la mayor cantidad de elementos y regresa
//el número de elementos
int mayorNumchars(Stack s1, Stack s2){
    if(Numchars(s1)>=Numchars(s2))
        return Numchars(s1);
    else
        return Numchars(s2);
}

long long int multiplica(Stack x, Stack y, int n, int base){

    //Comprueba si la candidad n de cifras es potencia de 2
    n = hazPotencia2(n);
    //Comprueba que ambos números tengan n cantidad de cifras
    if(Numchars(x)<n)
        x = agrega0(x,n-Numchars(x));
    if(Numchars(y)<n)
        y = agrega0(y,n-Numchars(y));

    //imprime(x);
    //imprime(y);

    if(n==1)
        return chartoint(top(x))*chartoint(top(y));
    else{
        Stack xi = dividir(x,'i',n);
        Stack xd = dividir(x,'d',n);
        Stack yi = dividir(y,'i',n);
        Stack yd = dividir(y,'d',n);
        Stack Sx = sumaStacks(xi,xd,base);
        Stack Sy = sumaStacks(yi,yd,base);
        long long int P1 = multiplica(xi,yi,n/2,base);
        //printf("P1: %d\n",P1);
        long long int P2 = multiplica(Sx,Sy,mayorNumchars(Sx,Sy),base);
        //printf("P2: %d\n",P2);
        long long int P3 = multiplica(xd,yd,n/2,base);
        //printf("P3: %d\n",P3);

        long long int resultado = exp(base,n)*P1 + exp(base,n/2)*(P2-P1-P3) + P3;
        //printf("res: %d\n",resultado);
        return resultado;
    }
}

