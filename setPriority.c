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
        int i=0;
        int new_priority=0, pid=0;
        while(argv[1][i]!='\0')
        {
            new_priority *= 10;
            new_priority += argv[1][i]-(int)'0';
            i++;
        }
        i=0;
        while(argv[2][i]!='\0')
        {
            pid *= 10;
            pid += argv[2][i]-(int)'0';
            i++;
        }
        if(new_priority < 0 || new_priority > 100)
        {
            printf(2, "Invalid priority number\n");
        }
        else
        {
            setPriority(new_priority, pid); //convert string to int????
        } //convert string to int????
    }
}