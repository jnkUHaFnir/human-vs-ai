#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

pid_t create_process() {
    pid_t pid;

    do {
        pid = fork();
    } while (pid == -1 && errno == EAGAIN);

    return pid;
}

int main() {
    FILE *fichier = fopen("entiers.txt","r");
    int i = 0;
    int n = 0;

    if (fichier != NULL) {
        printf("I am the father process of the pid %d\n", getpid());

        for (i = 0; i < 10; i++) {
            fscanf(fichier, "%d\n", &n);
            printf("%d\n", n);
        }

        pid_t pid = create_process();

        if (pid > 0) {
            wait(NULL);

            printf("I am the father process of the pid %d\n", getpid());

            // Reset the file pointer position to the beginning
            fseek(fichier, 0, SEEK_SET);

            do {
                n = fgetc(fichier);
                printf("%d\n", n);               
            } while (n != EOF);

            fclose(fichier);
            kill(pid, SIGKILL);
        }

        if (pid == 0) {
            printf("I am the child process of the pid %d\n", getpid());

            // Skip the first 10 numbers already read by the father process
            for (i = 0; i < 10; i++) {
                fscanf(fichier, "%d\n", &n);
            }

            for (i = 0; i < 10; i++) {
                fscanf(fichier, "%d\n", &n);
                printf("%d\n", n);
            }
        }
    }

    return EXIT_SUCCESS;
}
