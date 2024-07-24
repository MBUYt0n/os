#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    char buff[100];
    if (pipe(fd) == -1)
    {
        printf("pipe failure\n");
        exit(EXIT_FAILURE);
    }

    pid_t p = fork();

    if (p < 0)
    {
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }

    else if (p == 0)
    {
        printf("Enter a string\n");
        scanf("%[^\n]s", buff);
        write(fd[1], buff, 100);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        wait(NULL);
        read(fd[0], buff, 100);
        char rev[100];
        for (int i = strlen(buff); i > 0; i--)
        {
            rev[strlen(buff) - i] = buff[i - 1];
        }
        rev[strlen(buff)] = '\0';
        printf("Reversed String:\n%s\n", rev);
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }
}