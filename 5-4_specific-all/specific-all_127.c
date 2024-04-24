#include <pthread.h>
#include <stdio.h>
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
        
        // Start the thread here instead of just sleeping
        printf("Starting the thread...\n");
        sleep(/*some amount of time*/);
    }
    return NULL;
}

int main()
{
    pthread_t monitor_tid;
    pthread_create(&monitor_tid, NULL, monitoring_thread, NULL);
    
    // Simulate an interrupt occurring
    interrupt_handler();
    
    // Other code in your program
    
    pthread_join(monitor_tid, NULL);
    return 0;
}
