#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, char const *argv[]){

	key_t llaveshm = ftok("memoriaConexion",'m');
	int shmid = shmget(llaveshm,sizeof(int),IPC_CREAT|0660);
	int *connect = (int *)shmat(shmid,NULL,SHM_R|SHM_W);
	*connect = getpid();
	printf("Peticion de servico con: %i\n",*connect);
	shmdt(&connect);
	return 0;
}