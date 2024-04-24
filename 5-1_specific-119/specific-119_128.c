#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/select.h>

int pipe_fd[2];
volatile sig_atomic_t interrupt_flag = 0;

void interrupt_handler(int signal)
{
    write(pipe_fd[1], "x", 1);
}

void* interrupt_thread(void* arg)
{
    // handle the interrupt in this thread
    // replace this with your actual interrupt handling code
    printf("Interrupt handled in a new thread\n");
    return NULL;
}

void* monitoring_thread(void* arg)
{
    fd_set readfds;
    char buf;

    while(1)
    {
        FD_ZERO(&readfds);
        FD_SET(pipe_fd[0], &readfds);

        select(pipe_fd[0] + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(pipe_fd[0], &readfds))
        {
            read(pipe_fd[0], &buf, 1);
            //start a new thread to handle the interrupt
            pthread_t tid;
            pthread_create(&tid, NULL, interrupt_thread, NULL);
        }

        // add other processing or sleeping here if necessary
    }

    return NULL;
}

int main()
{
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Setup interrupt handler
    // insert your signal handling setup here
    // Example: signal(SIGINT, interrupt_handler);

    pthread_t monitor_tid;
    pthread_create(&monitor_tid, NULL, monitoring_thread, NULL);

    // Your main program logic here

    pthread_join(monitor_tid, NULL);
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    return 0;
}
