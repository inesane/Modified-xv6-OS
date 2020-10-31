#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int
main(int argc, char *argv[])
{
    int wtime, rtime;
    int pid = fork();
    if(pid==0)
    {
        exec(argv[1],argv + 1);
        exit();
    }
    else
    {
        waitx(&wtime, &rtime);
        printf(1, "Wait time = %d\nRun Time = %d\n", wtime, rtime);
        exit();
    }
}