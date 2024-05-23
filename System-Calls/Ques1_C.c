#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void check(char *path, char *str)
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
        if (entry->d_type == DT_DIR)
        {
            if ((strcmp(name, ".") == 0) || (strcmp(name, "..") == 0))
            {
                continue;
            }
            check(name, str);
        }
        else if (entry->d_type == DT_REG)
        {
            char *a = strstr(name, str);
            if ((a != NULL))
            {
                printf("file: %s\n", name);
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
