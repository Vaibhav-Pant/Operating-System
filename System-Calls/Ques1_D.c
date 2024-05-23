#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

void check(char *path)
{
    DIR *directory;
    struct dirent *entry;
    char src_path[256]; // source path

    char des_path[256]; // destination path

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
            char *a = strstr(name, ".");
            if ((a != NULL))
            {
                a++; // Removing . from extension
            }

            int fd = open(path, O_DIRECTORY | O_RDONLY);

            // making folder if not already exist
            // if exist ignore.
            if (mkdirat(fd, a, 0744) == -1 && errno != EEXIST)
            {
                perror("Error creating destination folder");
            }

            // Source path and destination path

            sprintf(src_path, "%s/%s", path, name);       // path/file_name
            sprintf(des_path, "%s/%s/%s", path, a, name); // path/foldername/file_name

            // move file to folder
            if (rename(src_path, des_path) != 0)
            {
                perror("Error moving file:  ");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (closedir(directory) == -1)
    {
        printf("Error closing directory\n");
        return;
    }
}

int main(int argv, char *argc[])
{
    check(argc[1]);
    printf("Completed!");
    return 0;
}
