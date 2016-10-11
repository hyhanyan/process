# process

#信号量
1、  sem ：
  编译 gcc -o testa testa.c sem.c
      gcc -o testb testb.c sem.c 
  执行 ./testa & ./testb &

#共享内存
2、  shm :
   编译 gcc -o shm shm.c sem.c
       gcc -o shmread shmread.c sem.c
       
#消息队列
3、  msg :
       gcc -o test test.c
       gcc -o msg msg.c
       
#管道
4、  pipe(无名)：
        gcc -o pipe pipe.c
        管道必须在fork之前创建
        有名管道与无名管道的区别：
          (pipe)无名管道：只可以在亲缘关系进程(fork)中使用，有名随便
          (mkfifo)有名管道：2个文件必须有一个为写，一个为读(是否有无亲缘关系都可以使用)
