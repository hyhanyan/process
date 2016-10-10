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
    int msgid = msgget((key_t)34,0600|IPC_CREAT);
    assert(msgid != -1);
    struct data dt;
    int res = msgrcv(msgid,&dt,8,1,0);
    assert(res != -1);
    printf("buff=%s\n",dt.buff);
    dt.type = 2;
    strcpy(dt.buff,"ok");
    res = msgsnd(msgid,&dt,8,0);
    return 0;
}
