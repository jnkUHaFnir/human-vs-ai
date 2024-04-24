#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int interrupt_flag = 0;
pthread_cond_t interrupt_flag_cv = PTHREAD_COND_INITIALIZER;
pthread_mutex_t interrupt_flag_mutex = PTHREAD_MUTEX_INITIALIZER;

void interrupt_handler(void)
{
    pthread_mutex_lock(&interrupt_flag_mutex);
    interrupt_flag = 1;
    pthread_cond_signal(&interrupt_flag_cv);
    pthread_mutex_unlock(&interrupt_flag_mutex);
}

void* monitoring_thread(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&interrupt_flag_mutex);
        while (!interrupt_flag)
        {
            pthread_cond_wait(&interrupt_flag_cv, &interrupt_flag_mutex);
        }
        interrupt_flag = 0;
        pthread_mutex_unlock(&interrupt_flag_mutex);

        // Start the thread here

        usleep(1000); // Sleep for some time to avoid tight loop
    }

    return NULL;
}

int main()
{
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitoring_thread, NULL);

    // Rest of your code

    pthread_join(monitor_thread, NULL); // Wait for monitoring thread to finish

    return 0;
}
