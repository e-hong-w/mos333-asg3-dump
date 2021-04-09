# EKT333 Modern Operating System ![GitHub last commit](https://img.shields.io/github/last-commit/ehong-w/mos333-asg3-dump?style=for-the-badge)

In my own words,\
`Make your life easier in a blink of a Touch n Go scan!`

![forthebadge](https://forthebadge.com/images/badges/powered-by-electricity.svg)

---
### Assignment 3: Inter process Communication – Shared Memory
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/ehong-w/mos333-asg3-dump)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/ehong-w/mos333-asg3-dumps)
![GitHub all releases](https://img.shields.io/github/downloads/ehong-w/mos333-asg3-dump/total)

#### Learning Outcome : Practice Implementation of shared memory in Linux environment

#### Creates 3 processes, 2 writer processes and 1 reader process. For this assignment you should create shared memory location with the size 2 (two) integer variable. One of the writer process will write a dummy temperature value to the first (1st) integer location and the other writer process will write a dummy pressure value to the second (2nd) integer location in the shared memory. The third process should read both value from the shared memory at approximately every 5 seconds.

&nbsp;&nbsp;&nbsp;&nbsp;a) Create your dummy temperature value from the equation value.
```python
temperature = LOWER_TEMP_BOUND+(int)(UPPER_TEMP_BOUND*rand()/(RAND_MAX+1.0));
** LOWER_TEMP_BOUND= 0 , UPPER_TEMP_BOUND= 100.00
```
&nbsp;&nbsp;&nbsp;&nbsp;b) Create your dummy pressure value from the equation value.
```python
pressure= LOWER_PRES_BOUND+(int)(UPPER_PRES_BOUND*rand()/(RAND_MAX+1.0));
** LOWER_PRES_BOUND = 150, UPPER_PRES_BOUND= 300.00
```
&nbsp;&nbsp;&nbsp;&nbsp;Note: LOWER_TEMP_BOUND, UPPER_TEMP_BOUD, LOWER_PRES_BOUND, UPPER_PRES_BOUND should be define as constant.

---

#### Reader process
```python
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
```
#### Temperature writer process
```python
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
```
#### Pressure writer process
```python
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
```

---

**@blaco**🐏: How's life? Did you check out my [GitHub](https://github.com/ehong-w/)? 😟
**@blaco**🐏: Drop me an email for other source code!
**@blaco**🐏: It's not free, but it worths just a price of a lunch. 🥗  

<p>
  <img width="512" src="https://user-images.githubusercontent.com/68590570/113911631-c52ca900-980c-11eb-8946-19ce84f84c40.png">
</p>

## 🧸 **Leave me a message?**
- 🍺 [E-mail](mailto:ehong.w@gmail.com?subject=[GitHub]%20Problem%20Description)
- 🧺 [Linkedin](https://www.linkedin.com/in/ehong-w/)
- ⛄ [Whatsapp]()
