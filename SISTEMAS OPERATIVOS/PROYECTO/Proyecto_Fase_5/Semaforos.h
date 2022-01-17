#include<sys/sem.h>
#include<sys/types.h>
#include<sys/ipc.h>

#define SEM_ID int

void semwait(int semid){
    struct sembuf s;
    s.sem_num=0;
    s.sem_op=-1;
    s.sem_flg=SEM_UNDO;

    semop(semid,&s,1);
    return;
}

void semsignal(int semid){
    struct sembuf s;
    s.sem_num=0;
    s.sem_op=1;
    s.sem_flg=SEM_UNDO;

    semop(semid,&s,1);
    return;
}

int createsem(int key, int value){
    int semid;
    semid = semget(key,1,0666|IPC_CREAT);
    semctl(semid,0,SETVAL,value);
    return(semid);
}

void ereasesem(int semid){
    semctl(semid,0,IPC_RMID,0);
    return;
}