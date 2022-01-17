#include<stdio.h>

int main(){
    int i=1;
    int n,m;
    while(i<=10){
        printf("%d\n",i);
        i++;
    }
    printf("---------\n");
    i=10;
    while(i>=1){
        printf("%d\n",i);
        i--;
    }
    printf("---------\n");
    printf("Ingrese un número: ");
    scanf("%d",&n);
    m=n;
    while(n!=0){
        m+=n-1;
        n--;
    }
    printf("La suma es: %d\n",m);
    return 0;
}
