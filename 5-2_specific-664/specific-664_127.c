#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/eventfd.h>

int pipe_fd;

void interrupt_handler(int signal)
{
    uint64_t val = 1;
    write(pipe_fd, &val, sizeof(val));
}

void* monitoring_thread(void* arg)
{
    uint64_t val;
    while(1)
    {
        read(pipe_fd, &val, sizeof(val));
        //start the thread here
    }
    return NULL;
}

int main()
{
    // Setup the pipe
    if(pipe(&pipe_fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    // Set up the signal handler
    signal(SIGINT, interrupt_handler);

    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitoring_thread, NULL);

    // Other initialization and handling code...

    pthread_join(monitor_thread, NULL);

    close(pipe_fd);
    return 0;
}
