#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

// Global variable to indicate interrupt occurrence
volatile sig_atomic_t interrupt_flag = 0;

// Signal handler function
void signal_handler(int sig) {
    interrupt_flag = 1;
}

// Function to be executed by the new thread
void* thread_function(void* arg) {
    printf("New thread created!\n");
    // Put your thread code here
    return NULL;
}

int main() {
    // Set up signal handler for SIGINT (Ctrl+C)
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    pthread_t thread;

    while (1) {
        if (interrupt_flag) {
            interrupt_flag = 0;
            pthread_create(&thread, NULL, thread_function, NULL);
        }
        usleep(1000); // Sleep for 1ms to avoid busy waiting
    }

    pthread_join(thread, NULL); // Wait for the thread to finish

    return 0;
}
