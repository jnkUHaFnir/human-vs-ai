#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/eventfd.h>

int efd;

void interrupt_handler(int signal)
{
    uint64_t u = 1;
    write(efd, &u, sizeof(uint64_t));
}

void *thread_func(void *arg)
{
    while (1)
    {
        uint64_t u;
        read(efd, &u, sizeof(uint64_t));
        // start your thread here
        printf("Thread created!\n");
    }
    return NULL;
}

int main()
{
    struct sigaction sa;
    pthread_t thread_id;

    // Create event file descriptor
    efd = eventfd(0, EFD_SEMAPHORE);

    // Initialize signal handler
    sa.sa_handler = interrupt_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    // Create and start the thread
    pthread_create(&thread_id, NULL, &thread_func, NULL);

    // Wait for the thread to finish
    pthread_join(thread_id, NULL);

    return 0;
}
