#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

// Function to create a new process with error handling
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

    if (fichier != NULL)
    {
        printf("I am the parent process with PID: %d\n", getpid());

        for (i = 0; i < 10; i++)
        {
            fscanf(fichier, "%d\n", &n);
            printf("%d\n", n);
        }

        pid_t pid = create_process();

        if (pid)
        {
            wait(NULL);

            printf("I am the parent process with PID: %d\n", getpid());

            // Reposition the file offset to the beginning
            fseek(fichier, 0, SEEK_SET);

            while (fscanf(fichier, "%d\n", &n) != EOF)
            {
                printf("%d\n", n);
            }

            fclose(fichier);
            kill(pid, SIGKILL);
        }

        if (!pid)
        {
            printf("I am the child process with PID: %d\n", getpid());

            for (i = 0; i < 10; i++)
            {
                fscanf(fichier, "%d\n", &n);
                printf("%d\n", n);
            }

            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        printf("Error opening the file.\n");
    }

    return EXIT_SUCCESS;
}
