#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int interrupt_flag = 0;

void interrupt_handler(void)
{
    pthread_mutex_lock(&mutex);
    interrupt_flag = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

void *monitoring_thread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while (!interrupt_flag)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        interrupt_flag = 0; // Reset the flag
        pthread_mutex_unlock(&mutex);

        // Start the thread here
        printf("Thread started\n");
        sleep(1); // Do some work here
    }
    return NULL;
}

int main()
{
    pthread_t monitor_tid;
    pthread_create(&monitor_tid, NULL, monitoring_thread, NULL);

    // Simulate an interrupt
    for (int i = 0; i < 5; i++)
    {
        interrupt_handler();
        sleep(1); // Simulate some processing time before the next interrupt
    }

    pthread_join(monitor_tid, NULL); // Wait for monitoring thread to finish
    return 0;
}
