#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0644

struct my_msgbu
{

    long mtype;
    char mtext[200];
} buf;

int main()
{
    int msqid, len;
    key_t key;
    system("touch msgq.txt");

    if ((key = ftok("msgq.txt", 'B')) == -1)
    {
        perror("ftok");
        exit(1);
    }

    if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1)
    {
        perror("msgget");
        exit(1);
    }

    printf("Message quque: Ready to send message. \n");
    printf("Enter text to send: \n");
    buf.mtype = 1;

    while (fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL)
    {
        len = strlen(buf.mtext);
        if (buf.mtext[len - 1] == '\n')
            buf.mtext[len - 1] = '\0';
        int cmp = strcmp(buf.mtext, "stop");
        if (cmp == 0)
        {
            break;
        }
        if (msgsnd(msqid, &buf, len + 1, 0) == -1)
        {
            perror("msgsnd ");
        }
    }
    if (msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue:  done sending message. \n");
    return 0;
}
