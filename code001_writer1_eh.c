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
    float temperature;
    const float LOWER_TEMP_BOUND = 0;
    const float UPPER_TEMP_BOUND = 100.00;
    time_t now;

    printf("shm: Writing temperature.\n");
    /*Returns identifier of allocated shared memory segment of size 2x integer size to 'descr'.*/
    shm_id = shmget(KEY, 2 * sizeof(int), IPC_CREAT|0660);

    ...
    ...

    sleep(1);
    while(1)
    {
        time(&now);
        temperature = LOWER_TEMP_BOUND + (int)(UPPER_TEMP_BOUND * rand() / (RAND_MAX + 1.0));
        /*Converts temperature from floating point to integer.*/
        shmptr[0] = (int)temperature;
        printf("\tTemperature\t: %d\n", shmptr[0]);
        /*Converts and shows date and time.*/
        printf("\t%s\n", ctime(&now));
        sleep(1);
    }
}