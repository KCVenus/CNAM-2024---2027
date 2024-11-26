#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int s;
    printf("Debut du processus\n");
    for (int i = 0; i < 100000; i++)
    {
        if (fork() == 0)
        {
            exit(0);
        }else{
            wait(&s);
        }
    }
    printf("Fin du processus\n");
}