#include <pthread.h>
#include <signal.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int interrupt_flag = 0;

void interrupt_handler(int signal)
{
    pthread_mutex_lock(&mutex);
    interrupt_flag = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

void* monitoring_thread(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while (!interrupt_flag)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        interrupt_flag = 0;
        pthread_mutex_unlock(&mutex);

        // Start your new thread here
        // pthread_create(...);

        // Optionally sleep for some amount of time
        // sleep(...);
    }

    return NULL;
}

int main()
{
    // Initialize thread for monitoring
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitoring_thread, NULL);

    // Set up the signal handler
    signal(SIGINT, interrupt_handler);

    // Main thread logic
    while (1)
    {
        // Your main thread logic here
        // Example: Do some work
    }

    return 0;
}
