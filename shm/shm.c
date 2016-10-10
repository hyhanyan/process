#include<sys/shm.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include "sem.h"

int main()
{   
    int shmid = shmget((key_t)234,256,0600|IPC_CREAT);
    assert(shmid != -1);
    char *s = (char*)shmat(shmid,NULL,0);
    assert( (void*)s != (void*)-1);
    sem_init();
    while(1){
        char buff[128] = {0};
        printf("input\n");
        scanf("%s",&buff);
        strcpy(s,buff);
        sem_v();
        if(strncmp(buff,"end",3) == 0){
            break;
        }
    }
    assert(shmdt(s) != -1);
    shmctl(shmid,IPC_RMID,0);
    sem_destroy();
    return 0;
}
