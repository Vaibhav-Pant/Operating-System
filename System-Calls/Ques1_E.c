#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

void askDelete(char *path, char *file)
{
    char buf[256];
    char ask;

    sprintf(buf, "%s/%s", path, file);
    printf("Do you want to delete %s  (Y/N): ", buf);
    scanf(" %c", &ask);

    if ((ask == 'Y') || (ask == 'y'))
    {
        int del = unlink(buf);
        if (del == 0)
        {
            printf("File Deteted !\n\n");
            return;
        }
        else
        {
            perror("Failed to delete ");
            printf("\n\n");
            return;
        }
    }
    else
    {
        printf("Not deleting.\n\n");
        return;
    }
}

void recur(char *path, char *name)
{
    struct dirent *third;
    DIR *dir = opendir(path);
    while ((third = readdir(dir)) != NULL)
    {
        char des_path[256];
        char *file = third->d_name;
        if (third->d_type == DT_DIR)
        {
            if ((strcmp(file, ".") == 0) || (strcmp(file, "..") == 0))
            {
                continue;
            }
            sprintf(des_path, "%s/%s", path, file);
            recur(des_path, name);
        }
        if (third->d_type == DT_REG)
        {
            int a = strcmp(file, name);
            if (a == 0)
            {
                struct stat filestat;
                stat(name, &filestat);
                sprintf(des_path, "%s/%s", path, file);

                printf("\nFile Name: %s\nPath of duplicate file: %s\nTime of file  Created: %s \n", file, des_path, ctime(&filestat.st_ctime));
                askDelete(path, file);
            }
        }
    }
    closedir(dir);
}

void check(char *path)
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
        if (entry->d_type == DT_DIR) // check if it is a directory
        {
            if ((strcmp(name, ".") == 0) || (strcmp(name, "..") == 0))
            {
                continue;
            }
        }
        else if (entry->d_type == DT_REG)
        {
            struct dirent *inside;
            DIR *dir = opendir(path);
            char buf[256];
            while ((inside = readdir(dir)) != NULL)
            {

                if (inside->d_type == DT_DIR)
                {
                    if ((strcmp(inside->d_name, ".") == 0) || (strcmp(inside->d_name, "..") == 0))
                    {
                        continue;
                    }
                    sprintf(buf, "%s/%s", path, inside->d_name);
                    recur(buf, name);
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

int main()
{

    check(".");
    return 0;
}
