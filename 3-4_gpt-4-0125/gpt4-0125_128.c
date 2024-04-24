#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

volatile int interrupt_flag = 0;
sem_t semaphore;

void* interrupt_handler_thread(void* arg) {
    // Simulate an interrupt handler signaling
    while (1) {
        if (interrupt_flag) {
            interrupt_flag = 0;
            sem_post(&semaphore);
        }
    }
}

void* event_handler_thread(void* arg) {
    while (1) {
        sem_wait(&semaphore); // Wait for the semaphore to be posted
        // Handle the event, potentially starting another thread
    }
}

int main() {
    pthread_t handler_thread, event_thread;
    sem_init(&semaphore, 0, 0); // Initialize semaphore

    pthread_create(&handler_thread, NULL, interrupt_handler_thread, NULL);
    pthread_create(&event_thread, NULL, event_handler_thread, NULL);

    pthread_join(handler_thread, NULL);
    pthread_join(event_thread, NULL);

    sem_destroy(&semaphore); // Clean up semaphore
    return 0;
}
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
volatile int interrupt_flag = 0;

void* interrupt_handler_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (interrupt_flag) {
            interrupt_flag = 0;
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);
    }
}

void* event_handler_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (!interrupt_flag) {
            pthread_cond_wait(&cond, &mutex);
        }
        // Reset interrupt_flag if necessary
        // Process event here
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t handler_thread, event_thread;

    pthread_create(&handler_thread, NULL, interrupt_handler_thread, NULL);
    pthread_create(&event_thread, NULL, event_handler_thread, NULL);

    pthread_join(handler_thread, NULL);
    pthread_join(event_thread, NULL);

    return 0;
}
