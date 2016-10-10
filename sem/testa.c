#include "sem.h"

int main()
{
    int i=0,n=0;
    sem_init();
    for(;i<10;i++){
        sem_p();
        printf("A");
        fflush(stdout);
        n = rand()%3;
        sleep(n);
        printf("A");
        fflush(stdout);
        sem_v();
        n = rand()%2;
        sleep(n);
    }
    sleep(10);
    sem_destory();
    return 0;
}
