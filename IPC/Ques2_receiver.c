#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define fifo_file "myfifo"

int main()
{
    int readbytes;
    char read_store[4][20];
    mknod(fifo_file, S_IFIFO | 0640, 0);

    while (1)
    {

        int fd = open(fifo_file, O_RDONLY);
        readbytes = read(fd, read_store, sizeof(read_store));
        if (readbytes > 0)
        {

            for (int i = 0; i < 4; i++)
            {
                printf("Received data: %s\n", read_store[i]);
            }

            close(fd);
            break;
        }
    }
    return 0;
}
