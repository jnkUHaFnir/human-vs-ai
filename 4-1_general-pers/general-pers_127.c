#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define INTERRUPT_SIGNAL SIGRTMIN+1

int interrupt_flag = 0;
pthread_t interrupt_handling_thread;

void interrupt_handler(int signal)
{
    // Raise the flag in the signal handler
    interrupt_flag = 1;
}

void *interrupt_handling_function(void *arg)
{
    while(1)
    {
        if(interrupt_flag)
        {
            interrupt_flag = 0;
            // Start the thread upon interrupt
            printf("Thread started upon interrupt\n");
        }
    }
}

int main()
{
    // Set up the interrupt handling thread
    pthread_create(&interrupt_handling_thread, NULL, interrupt_handling_function, NULL);

    // Set up the interrupt handler
    struct sigaction action;
    action.sa_handler = interrupt_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(INTERRUPT_SIGNAL, &action, NULL);

    // Trigger the interrupt for demonstration
    // In a real scenario, this would be triggered by the hardware interrupt
    raise(INTERRUPT_SIGNAL);

    // Continue running other threads or operations here

    pthread_join(interrupt_handling_thread, NULL); // Wait for the thread to finish before exiting
    return 0;
}
