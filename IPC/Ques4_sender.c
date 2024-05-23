#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 1024
#define SHM_KEY 1122

int main(int argc, char *argv[])
{
    int shmid;
    void *mem;
    char bufptr[BUF_SIZE];
    shmid = shmget((key_t)SHM_KEY, BUF_SIZE, 0644);
    if (shmid == -1)
    {
        perror("Shared memory");
        return 1;
    }
    // Attach to the segment to get a pointer to it.
    mem = shmat(shmid, NULL, 0);
    if (mem == (void *)-1)
    {
        perror("Shared memory attach");
        return 1;
    }
    /* Transfer blocks of data from buffer to shared memory */
    printf("Process attached at %p\n", mem);
    printf("Data read from shared memory:\n%s", (char *)mem);
}
