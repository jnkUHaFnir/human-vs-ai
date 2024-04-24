#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

pid_t create_process()
{
    pid_t pid;

    do {
        pid = fork();
    } while (pid == -1 && errno == EAGAIN);

    return pid;
}

int main(int argc, char *argv[])
{
    int fd = -1;
    int child_flag = 0;
  
    if (argc > 1) {
        fd = atoi(argv[1]);
        child_flag = 1;
    }
    else {
        fd = fileno(fopen("entiers.txt", "r"));
    }
  
    FILE *fichier = fdopen(fd, "r");
    int i = 0;
    int n = 0;

    if(!child_flag) {
        printf("I am the father process of the pid %d\n", getpid());
        for(i = 0; i < 10; i++) {
            fscanf(fichier, "%d\n", &n);
            printf("%d\n", n);
        }
    }

    pid_t pid = create_process();

    if(pid)
    { // parent process
        if(!child_flag) {
            wait(NULL);
            printf("I am the father process of the pid %d\n", getpid());
            do {
                fscanf(fichier, "%d\n", &n);
                printf("%d\n", n);               
            } while (n != EOF);

            fclose(fichier);
            kill(pid, SIGKILL);
        }
    }
    else if (!child_flag)
    { // child process
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", fd);
        execlp(argv[0], argv[0], buf, NULL);
    }
    else
    { // child process after exec
        printf("I am the child process of the pid %d\n", getpid());
        for(i=0; i<10; i++)
        {
            fscanf(fichier, "%d\n", &n);
            printf("%d\n",n);
        }
    }

    return EXIT_SUCCESS;
}
I am the father process of the pid 11496
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
I am the child process of the pid 11497
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
I am the father process of the pid 11496
71
73
79
83
89
97
