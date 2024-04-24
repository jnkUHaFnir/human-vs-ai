#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t create_process() {
    pid_t pid;
    do {
        pid = fork();
    } while (pid == -1 && errno == EAGAIN);
    return pid;
}

int main() {
    FILE *fichier = fopen("entiers.txt", "r");
    int i = 0;
    int n = 0;

    if (fichier != 0) {
        printf("I am the father process with pid %d\n", getpid());
        for (i = 0; i < 10; i++) {
            fscanf(fichier, "%d\n", &n);
            printf("%d\n", n);
        }

        pid_t pid = create_process();

        if (pid) {
            wait(NULL);

            printf("I am the father process with pid %d\n", getpid());

            // Reset the file pointer position to the beginning of the file
            fseek(fichier, 0, SEEK_SET);

            do {   
                n = fgetc(fichier);
                printf("%d\n", n);               
            } while (n != EOF);

            fclose(fichier);
            kill(pid, SIGKILL);
        }

        if (!pid) {
            printf("I am the child process with pid %d\n", getpid());

            for (i = 0; i < 10; i++) {
                fscanf(fichier, "%d\n", &n);
                printf("%d\n", n);
            }
        }
    }

    return EXIT_SUCCESS;
}
I am the father process with pid 8226
1
2
3
5
7
11
13
17
19
23
I am the child process with pid 8227
29
31
37
41
43
47
53
59
61
67
I am the father process with pid 8226
1
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
