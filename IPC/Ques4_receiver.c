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
    shmid = shmget((key_t)SHM_KEY, BUF_SIZE, 0644 | IPC_CREAT);
    printf("Key of shared memeory: %d\n", shmid);
    if (shmid == -1)
    {
        perror("Shared memory");
        return 1;
    }
    // Attach to the segment to get a pointer to it.
    mem = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", mem);

    if (mem == (void *)-1)
    {
        perror("Shared memory attach");
        return 1;
    }
    /* Transfer blocks of data from buffer to shared memory */
    printf("Entet data to put in shared memeory:\n");
    fgets(bufptr, BUF_SIZE, stdin);
    strcpy(mem, bufptr);
    printf("\nData succesfully wriiten in shared memory!");
}
