#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\Elem.h"
#include"C:\Users\Eduardo_SH\Documents\IPN\ESCOM\Semestre 2\AED\LibAED\ColaCir.h"


int MyModule(int, int);

Circular ColaCNueva(int);

int main(){
    int a,b;

    while(1){
        printf("Ingrese a: ");
        scanf("%d",&a);
        printf("Ingrese b: ");
        scanf("%d",&b);
        printf("El resultado de %d mod %d es: %d\n\n",a,b,MyModule(a,b));
    }

    return 0;
}

int MyModule(int a, int b){
    //Esta funci�n debera devolver a mod b;

    /*int i,t,k;
    Circular M=nuevaC();
    for(i=0;i<=a;i++)
        M=formarC(M,i);
    t=a/b;
    k=t*b;
    k=a-k;
    for(i=0;i<=k-1;i++){
        M=rotacionC(M);
        //printf("%d\n",primeroC(M));
    }
    return primeroC(M);*/

    //Codigo de Hanna
    /*int i;
    Circular e=ColaCNueva(b);
    for(i=1;i<a;i++)
        e=rotacionC(e);
    if(primeroC(e)==b)
        return 0;
    else
        return primeroC(e);*/
    
    //Codigo del profe
    int i;
    Circular e=ColaCNueva(b);
    if(b==0){
        printf("***ERROR***\n");
        return NULL;
        //exit(0);
    }else{
        for(i=0;i<a;i++)
            e=rotacionC(e);
        return primeroC(e);
    }
}

Circular ColaCNueva(int n){
    int i;
    Circular d=nuevaC();
    for(i=0;i<n;i++)
        d=formarC(d,i);
    return d;
}
