#include <pthread.h>
#include <unistd.h>

int interrupt_flag = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void interrupt_handler(void)
{
    pthread_mutex_lock(&mutex);
    interrupt_flag = 1;
    pthread_cond_signal(&cond); // Notify the monitoring thread
    pthread_mutex_unlock(&mutex);
}

void* monitoring_thread(void* arg)
{
    pthread_mutex_lock(&mutex);
    while (1)
    {
        while (!interrupt_flag)
        {
            pthread_cond_wait(&cond, &mutex); // Wait until interrupt_flag is set
        }
        interrupt_flag = 0;
        pthread_mutex_unlock(&mutex);
        
        // Start the thread here
        sleep(/*some amount of time*/);
        
        pthread_mutex_lock(&mutex);
    }
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main()
{
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitoring_thread, NULL);
    
    // Your main program logic here
    
    pthread_join(monitor_thread, NULL);
    return 0;
}
