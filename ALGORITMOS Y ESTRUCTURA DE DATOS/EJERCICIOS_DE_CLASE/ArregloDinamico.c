#include<stdio.h>
#include<stdlib.h>

int main(){

    char a[20];
    char *b;
    int i;

    b=(char*)malloc(sizeof(char));

    for(i=0;i<10;i++)
        a[i]='A'+i;

    for(i=0;i<10;i++)
        printf("%c\t",a[i]);
    printf("\n");

    for(i=0;i<10;i++)
        b[i]=a[i]+32;

    for(i=0;i<10;i++)
        printf("%c\t",b[i]);
    printf("\n");

    return 0;
}