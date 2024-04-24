#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int pipefd[2];

void interrupt_handler(int signum)
{
    char byte = 1;
    write(pipefd[1], &byte, sizeof(byte));
}

void* monitoring_thread(void* arg)
{
    while(1) {
        char byte;
        read(pipefd[0], &byte, sizeof(byte));
        // Start a new thread here
    }
    return NULL;
}

int main()
{
    pthread_t monitor_thread;

    if(pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    signal(SIGINT, interrupt_handler); // Set up the interrupt handler

    if(pthread_create(&monitor_thread, NULL, monitoring_thread, NULL) != 0) {
        perror("Thread creation failed");
        return 1;
    }

    pthread_join(monitor_thread, NULL);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
