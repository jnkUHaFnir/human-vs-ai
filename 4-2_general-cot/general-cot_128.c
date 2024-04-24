#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t interrupt_sem;

void interrupt_handler()
{
    sem_post(&interrupt_sem); // Signal the semaphore from the interrupt handler
}

void* thread_function(void* arg)
{
    // Thread code to run when started upon interrupt
    printf("Thread started!\n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    
    sem_init(&interrupt_sem, 0, 0); // Initialize the semaphore
    
    // Create the thread that will monitor the semaphore
    pthread_create(&thread_id, NULL, thread_function, NULL);
    
    while(1)
    {
        sem_wait(&interrupt_sem); // Wait for the semaphore to be signaled
        
        // Once the semaphore is signaled, start the thread
        pthread_create(&thread_id, NULL, thread_function, NULL);
        
        // Optionally add a delay before allowing the interrupt to trigger again
        usleep(/*some amount of time*/);
    }
    
    return 0;
}
#include <stdlib.h>
#include <queue>

std::queue<int> interrupt_queue;
pthread_mutex_t interrupt_mutex = PTHREAD_MUTEX_INITIALIZER;

void interrupt_handler()
{
    pthread_mutex_lock(&interrupt_mutex);
    interrupt_queue.push(1);
    pthread_mutex_unlock(&interrupt_mutex);
    sem_post(&interrupt_sem);
}

void* monitoring_thread_function(void* arg)
{
    while(1)
    {
        sem_wait(&interrupt_sem);
        
        pthread_mutex_lock(&interrupt_mutex);
        while (!interrupt_queue.empty())
        {
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, thread_function, NULL);
            interrupt_queue.pop();
        }
        pthread_mutex_unlock(&interrupt_mutex);
    }
    return NULL;
}
