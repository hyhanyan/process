#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>

struct data 
{
    long type;
    char buff[8];
};

int main()
{
    int msgid = msgget((key_t)34,IPC_CREAT|0600);
    assert(msgid != -1);
    struct data dt;
    dt.type = 1;
    memset(dt.buff,'a',7);
    int res = msgsnd(msgid,&dt,8,0);
    assert(res != -1);
    res = msgrcv(msgid,&dt,8,2,0);
    assert(res != -1);
    printf("buff=%s\n",dt.buff);
    assert(msgctl(msgid,IPC_RMID,0) != -1);
    return 0;
}
