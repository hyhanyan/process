#include<stdio.h>
#include<assert.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    if(access("./test",F_OK) != 0){
        int res = mkfifo("./test",0666);
        assert(res != -1);
    }
    int fdr = open("./test",O_RDONLY);
    assert(fdr != -1);
    char buff[128] = {0};
    read(fdr,buff,127);
    printf("read=%s\n",buff);
    close(fdr);
    
    return 0;
}
