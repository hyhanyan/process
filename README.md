# process

#信号量
  sem ：
  编译 gcc -o testa testa.c sem.c
      gcc -o testb testb.c sem.c 
  执行 ./testa & ./testb &

#共享内存
   shm :
   编译 gcc -o shm shm.c sem.c
       gcc -o shmread shmread.c sem.c
