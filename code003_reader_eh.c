#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*For calling sleep() function.*/
#include <time.h>   /*For calling time() function.*/
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 6666    /*Key for shared memory.*/

void main()
{
    int shm_id, count, *shmptr;
    time_t now;

    printf("smh: Starting reader process.\n");
    /*Returns identifier of allocated shared memory segment of size 2x integer size to 'descr'.*/

    ...
    ...

    while(1)
    {
        time(&now);
        for(count = 0; count < 2; count++)
        {
            if(count == 0)
                printf("\tshm: Value of temperature\t: %d\n", shmptr[count]);
            else if(count == 1)
                printf("\tshm: value of pressure\t\t: %d\n", shmptr[count]);
        }
        /*Converts and shows date and time.*/
        printf("\t%s\n", ctime(&now));
        sleep(5);
    }
}