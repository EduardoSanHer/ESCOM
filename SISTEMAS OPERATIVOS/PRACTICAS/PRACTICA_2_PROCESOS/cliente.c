#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>

int *boletos;
int escritura;
int lectura;
void leer(){
	key_t obtener = ftok("Boletos_Venta",'i');
	lectura = shmget(obtener,16*sizeof(int),IPC_CREAT|0666);
	boletos = (int *)shmat(lectura,(void*)0,0);
}
void escribir(int l){
	int *boletos_escritura,i;
	key_t obtener = ftok("Boletos_Venta",'i');
	escritura = shmget(obtener,16*sizeof(int),IPC_CREAT|0666);
	boletos_escritura = (int *)shmat(escritura,(void*)0,0);

	shmdt(&boletos_escritura);
	for(i = 0; i < 16; i++)
		boletos_escritura[i] = boletos[i];
	//shmctl(escritura,IPC_RMID,NULL);
}
void imp(){
    int i;
    printf("\n");
    for(i = 0; i<16; i++)
        printf("%c ",97+i);
    printf("\n");
    for(i = 0; i<16; i++)
        printf("%d ", boletos[i]);
    printf("\n");
}

void comprar(char c){

	if(boletos[c-97] == 1){
		printf("Lugar no disponible, por favor intentalo de nuevo.\n\n");
		return;
	}else{
		boletos[c-97] = 1;
		printf("Compra exitosa\n\n");
		escribir((int)(c-97));
	}
}

int main(int argc, char const *argv[]){

	char c;
//	boletos = (int*)malloc(16*sizeof(int));
	leer();

//	while(1){
		//system("cls");
		printf("SERVICIO DE VENTA DE BOLETOS\n\n");
		printf("Boletos disponibles: \n\n");
		imp();

		printf("Ingresa el asiento disponible a comprar o  para salir presiona x: ");
		scanf("%c",&c);

	//	if(c == 'x')
	//		break;

		comprar(c);
	//	escribir();



//	}
	  //imp();
	//  shmdt(&boletos);
	//  shmctl(lectura,IPC_RMID,NULL);
	//  sleep(2);
	//shmdt(&boletos);
	//shmctl(escritura,IPC_RMID,NULL);
	sleep(3);
	return 0;
}