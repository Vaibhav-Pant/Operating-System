#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

void check(char *path, char *output_file)
{
    DIR *directory;
    struct dirent *entry;

    directory = opendir(path);
    if (directory == NULL)
    {
        printf("Error opening directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL)
    {
        char *name = entry->d_name;
        if (entry->d_type != DT_DIR)
        {
            char *a = strstr(name, ".txt");
            if ((a != NULL))
            {
                struct stat st;
                stat(name, &st);
                int size = st.st_size;
                char *buffer = (char *)malloc(sizeof(char) * size);
                int fd = open(name, O_RDONLY);
                if (fd == -1)
                {
                    printf("Error in fd");
                    return;
                }
                ssize_t bytes = read(fd, buffer, size);
                if (bytes == -1)
                {
                    printf("Error reading from file: %s\n", name);
                    close(fd);
                    return;
                }
                int fd2 = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
                ssize_t bytes_written = write(fd2, buffer, size);
                if (bytes_written == -1)
                {
                    printf("Error writin in file: %s\n", output_file);
                    close(fd2);
                    return;
                }
            }
        }
    }
    if (closedir(directory) == -1)
    {
        printf("Error closing directory\n");
        return;
    }
}

int main(int argc, char *argv[])
{
    check(".", argv[1]);
    return 0;
}
