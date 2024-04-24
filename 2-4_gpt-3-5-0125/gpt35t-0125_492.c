#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

pid_t create_process()
{
    pid_t pid;

    do {
        pid = fork();       
    } while (pid == -1 && errno == EAGAIN); 

    return pid;
}

int main()
{
    FILE *fichier = fopen("entiers.txt", "r");
    int i = 0;
    int n = 0;

    if (fichier != 0)
    {
        printf("I am the father process of the pid %d\n", getpid());

        for (i = 0; i < 10; i++)
        {
            fscanf(fichier, "%d\n", &n);
            printf("%d\n", n);
        }

        pid_t pid = create_process();

        if (pid)
        {
            wait(NULL);

            fseek(fichier, 0, SEEK_SET); // Reset file pointer to the beginning

            printf("I am the father process of the pid %d\n", getpid());
            do
            {   
                n = fgetc(fichier);
                if (n != EOF) {
                    printf("%d\n", n);
                }               
            } while (n != EOF);

            fclose(fichier);

            kill(pid, SIGKILL);
        }

        if (!pid)
        {
            printf("I am the child process of the pid %d\n", getpid());

            for (i = 0; i < 10; i++)
            {
                fscanf(fichier, "%d\n", &n);
                printf("%d\n", n);
            }

        }
    }

    return EXIT_SUCCESS;
}
