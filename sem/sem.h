#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int sem_init();
int sem_p();
int sem_v();
int sem_destroy();
