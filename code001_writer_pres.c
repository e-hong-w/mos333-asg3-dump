#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*For calling sleep() function.*/
#include <time.h>   /*For calling time() function.*/
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 6666    /*Key for shared memory.*/

void main()
{
    int shm_id, *shmptr;
    float pressure;
    const float LOWER_PRES_BOUND = 150;
    const float UPPER_PRES_BOUND = 300.00;
    time_t now;

    printf("shm: Writing pressure.\n");
    /*Returns identifier of allocated shared memory segment of size 2x integer size to 'descr'.*/
    shm_id = shmget(KEY, 2 * sizeof(int), IPC_CREAT|0660);

    ...
    ...

    sleep(1);
    while(1)
    {
        time(&now);
        pressure = LOWER_PRES_BOUND + (int)(UPPER_PRES_BOUND * rand() / (RAND_MAX + 1.0));
        /*Converts temperature from floating point to integer.*/
        shmptr[1] = (int)pressure;
        printf("\tPressure\t: %d\n", shmptr[1]);
        /*Converts and shows date and time.*/
        printf("\t%s\n", ctime(&now));
        sleep(1);
    }
}