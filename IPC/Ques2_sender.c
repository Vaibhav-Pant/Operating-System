#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define fifo_file "myfifo"

int main()
{

    int fd = open(fifo_file, O_CREAT | O_WRONLY);
    char data[4][20];

    printf("Enter RegNum: ");
    scanf("%s", data[0]);

    printf("Enter name: ");
    scanf("%s", data[1]);

    printf("Enter Course: ");
    scanf("%s", data[2]);

    printf("Enter School: ");
    scanf("%s", data[3]);

    write(fd, data, sizeof(data));
    printf("Data written!\n");

    close(fd);

    return 0;
}
