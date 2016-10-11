#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>

int main()
{
    int fd[2];
    int res = pipe(fd);
    assert(res != -1);
    pid_t pid = fork();
    assert(pid != -1);
    if(pid == 0){
        char buff[128] = {0};
        read(fd[0],buff,127);
        printf("child read:%s\n",buff);
    }else{
        char buff[128] = {0};
        printf("intput:\n");
        fgets(buff,127,stdin);
        write(fd[1],buff,strlen(buff));
    }

    return 0;
}
