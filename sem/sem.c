#include "sem.h"

static int semid;

int sem_init()
{
    semid = semget((key_t)1234,1,0600|IPC_CREAT|IPC_EXCL);
    if(semid == -1){
        semid = semget((key_t)1234,1,0600);
        if(semid == -1){
            printf("init failed\n");
            return 0;
        }
    }else{
        union semun em;
        em.val = 1;
        if(semctl(semid,0,SETVAL,em) == -1){
            printf("init failed\n");
            return 0;
        }
    }
    return 1;
}

int sem_p()
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;
    if(semop(semid,&buf,1) == -1){
        printf("p failed\n");
        return 0;
    }
    return 1;
}

int sem_v()
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;
    if(semop(semid,&buf,1) == -1){
        printf("v failed\n");
        return 0;
    } 
    return 1;
}

int sem_destory()
{
    if(semctl(semid,0,IPC_RMID) == -1){
        printf("error\n");
        return 0;
    }
    return 1;
}

