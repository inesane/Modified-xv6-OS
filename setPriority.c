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
    if(argc!=3)
    {
        printf(2, "Invalid Number of Arguments\n");
    }
    else
    {
        //setPriority(argv[1], argv[2]); //convert string to int????
    }
}