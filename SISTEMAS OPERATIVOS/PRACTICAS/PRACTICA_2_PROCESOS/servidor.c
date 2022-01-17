#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>
#include <termios.h>
#include "teclado.h"
#include <sys/wait.h>

int *boletos;
void asigna(){
    int i;

for(i = 0; i<16; i++)
        boletos[i] = 0;
}
void imp(){
    printf("Boletos disponibles:\n");
    int i;
    printf("\n");
    for(i = 0; i<16; i++)
        printf("%c ",97+i);
    printf("\n");
    for(i = 0; i<16; i++)
        printf("%d ", boletos[i]);
    printf("\n");
}
void leer(){
    int lectura;
    key_t obtener = ftok("Boletos_Venta",'i');
    lectura = shmget(obtener,16*sizeof(int),IPC_CREAT|0660);
    boletos = (int *)shmat(lectura,0,0); 
}
int main(int argc, char const *argv[]){

    boletos = (int*)malloc(16*sizeof(int));
    leer();
   // asigna();
    key_t llaveConexion;
    int idConexion, shmid,pid;
    init_keyboard();
    llaveConexion = ftok("memoriaConexion", 'm');
    printf("Venta DE BOLETOS\n\n");
    imp();
    printf("\n\n");
    shmid = shmget(llaveConexion,sizeof(int),IPC_CREAT|0660);

    int *connect = (int *)shmat(shmid,NULL,SHM_R|SHM_W);
    *connect = -1; 
    char c;

    while(1){
        
       // system("clear");
        //printf("\n\nVenta DE BOLETOS\n\n");
        //imp();        

        if(_kbhit()){
            char exit;
            exit = _getch();
            if(exit == 'x'){
                shmdt(&connect);
                shmctl(shmid,IPC_RMID,0);
                break;
            }
        }
        if(*connect == -1)
                continue;

            //leer();
            idConexion = *connect;
            printf("Peticion de servicio nueva con ID: %i\n", idConexion);
            pid = fork();
            if(pid < 0)
                    return 1;
            if(pid == 0){
                printf("Intentando hacer conexion con el cliente %i\n",idConexion);
                int err = execlp("gnome-terminal","gnome-terminal","--","./tc",(char*)NULL);
                if(err == -1){
                    printf("No se pudo hacer la conexion con cliente\n");
                    return 2;
                }else
                    return 0;

                return 0;
            }
            /*      
            else if(pid > 0){
                int pid2;
                pid2 = fork();
                if(pid2 < 0)
                    return 2;
                else if(pid2 == 0){
                    waitpid(pid,NULL,0);
                    printf("Se espero al cliente %i:", idConexion);
                    //kill(pid,SIGKILL);
                }
            }
            */
            leer();
            printf("\n\nVenta DE BOLETOS\n\n");
            imp();  
            

        *connect = -1;
       // printf("\n\n");
       // imp(); 
    }
    close_keyboard();
    return 0;
}