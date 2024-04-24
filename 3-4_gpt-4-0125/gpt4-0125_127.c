#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int interrupt_flag = 0;

void *interrupt_handler(void *arg)
{
    // Simulate interrupt handling
    // This would actually be an external event
    sleep(1); // wait a bit to simulate time until interrupt

    pthread_mutex_lock(&mutex);
    interrupt_flag = 1;
    pthread_cond_signal(&cond); // Signal the monitoring thread that the flag is set
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *monitoring_thread(void *arg)
{
    pthread_mutex_lock(&mutex);

    while (1) {
        while (!interrupt_flag) { // Use while loop to avoid spurious wake-ups
            pthread_cond_wait(&cond, &mutex); // Unlock mutex and wait for signal, then re-lock mutex
        }
        interrupt_flag = 0;
        pthread_mutex_unlock(&mutex);

        // Code to start the thread here
        // Remember to handle the thread properly,
        // for instance with pthread_create()

        // Lock the mutex for the next iteration or condition check
        pthread_mutex_lock(&mutex);
    }
    // Not reached because of infinite loop, but you may add handling for termination 

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(void)
{
    pthread_t handler_thread, monitor_thread;

    pthread_create(&monitor_thread, NULL, &monitoring_thread, NULL);
    pthread_create(&handler_thread, NULL, &interrupt_handler, NULL);

    pthread_join(handler_thread, NULL);
    pthread_join(monitor_thread, NULL);
    return 0;
}
