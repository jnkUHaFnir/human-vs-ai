#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

volatile int interrupt_flag = 0;
pthread_mutex_t flag_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t flag_cv = PTHREAD_COND_INITIALIZER;

void interrupt_handler(void)
{
    pthread_mutex_lock(&flag_mutex);
    interrupt_flag = 1;
    pthread_cond_signal(&flag_cv);
    pthread_mutex_unlock(&flag_mutex);
}

void *monitoring_thread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&flag_mutex);
        while (!interrupt_flag)
        {
            pthread_cond_wait(&flag_cv, &flag_mutex);
        }
        interrupt_flag = 0;
        pthread_mutex_unlock(&flag_mutex);

        // Start the thread here
        printf("Thread created\n");
    }
    return NULL;
}

int main()
{
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitoring_thread, NULL);

    // Simulating interrupt occurrence
    while (1)
    {
        printf("Simulating interrupt...\n");
        interrupt_handler();
        sleep(1);
    }

    pthread_join(monitor_thread, NULL);
    return 0;
}
