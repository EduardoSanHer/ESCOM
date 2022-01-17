#include<stdio.h>

int main(int argc, char* argv[]){
    FILE *entrada=fopen(*++argv,"r");
    FILE *salida=fopen(*++argv,"w");
    char pal[80];

/*
    while((c=fgetc(entrada))!=EOF)
        fputc(c,salida);

    fclose(entrada);
    fclose(salida);
*/

    return 0;
}
