int leer_int(){
    int t;
    scanf("%d",&t);
    getchar();
    return t;
}

const char* leer_string(){
    fflush(stdin);
    char *temp;
    fgets(temp,64,stdin);
    temp[strlen(temp)-1] = '\0';
    return temp;
}

int int_equals(int a, int b){return a==b;}