#include<sys/shm.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>
#include "sem.h"

int main()
{
    int shmid = shmget((key_t)234,256,0600|IPC_CREAT);
    assert(shmid != -1);
    char *s = (char *)shmat(shmid,NULL,0);
    assert((void*)s != (void*)-1);
    sem_init();
    while(1){
        sem_p();
        if(s == '\0'){
            continue;
        }
        if(strncmp(s,"end",3) == 0){
            break;
        }
        printf("read=%s\n",s);
        memset(s,0,sizeof(s));
    }
    assert(shmdt(s) != -1);
    return 0;
}
