#include<stdio.h>
#include<assert.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    if(access("./test",F_OK) != 0){
        int res = mkfifo("./test",0666);
        assert(res != -1);
    }
    int fdw = open("./test",O_WRONLY);
    assert(fdw != -1);
    printf("fdw=%d\n",fdw);
    write(fdw,"test",4);
    close(fdw);
    
    return 0;
}
