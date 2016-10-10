#include "sem.h"

int main()
{
    int i=0,n=0;
    sem_init();
    for(;i<10;i++){
        sem_p();
        printf("B");
        fflush(stdout);
        n = rand()%3;
        sleep(n);
        printf("B");
        fflush(stdout);
        sem_v();
        n = rand()%2;
        sleep(n);
    }
    return 0;
}
