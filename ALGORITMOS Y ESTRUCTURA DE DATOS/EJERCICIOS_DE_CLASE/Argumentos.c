#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
     int i=0;
     char *c=*(argv+1);

     //printf("Numero de argumentos: %d.\n",argc);
     printf("%s\n",c);
     //puts("Lista de argumentos:");

     while(c[i])
         printf("%c\n",*c[i++]);

     return 0;
}
