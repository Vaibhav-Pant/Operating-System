#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int foo(int fd, char *buf, int b_size, int n, int skip)
{
    int bytes = 0;
    if (fd == -1)
    {
        printf("Error opening file");
        return -1;
    }

    int i = 0;
    while (i < n)
    {
        ssize_t read_bytes = read(fd, buf, b_size);
        if (read_bytes == -1)
        {
            printf("Error reading.\n");
            return -1;
        }

        bytes += read_bytes;

        off_t skip_cursor = lseek(fd, skip, SEEK_CUR);
        if (skip_cursor == -1)
        {
            printf("Error in skiping cursor.\n");
            return -1;
        }
        i++;
    }
    return bytes;
}

int main()
{

    int n, skip, size;
    printf("Enter number of blocks to read (n): :");
    scanf("%d", &n);

    printf("Enter the Size of 1 block: ");
    scanf("%d", &size);

    printf("Enter the amount to skip: ");
    scanf("%d", &skip);

    char *filename = "file1.txt";
    char buf[100];
    int fd = open(filename, O_RDONLY);

    int res = foo(fd, buf, size, n, skip);
    printf("Total Bytes read: %d\n", res);
    return 0;
}
