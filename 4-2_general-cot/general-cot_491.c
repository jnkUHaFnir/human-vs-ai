#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int signal[3] = {0, 0, 0}; // Assume 3 consumers
int i = 0; // Index of the consumer

// Consumer function
void* consumer_func(void* arg) {
    int consumer_id = *(int*)arg;

    pthread_mutex_lock(&mutex);
    signal[consumer_id] = 1;
    while (signal[consumer_id] == 1) {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Producer function
void* producer_func(void* arg) {
    int consumer_id = *(int*)arg;

    pthread_mutex_lock(&mutex);
    if (signal[consumer_id] == 1) {
        signal[consumer_id] = 0; // Reset the signal
    }
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t producer, consumers[3];
    int ids[3] = {0, 1, 2}; // Consumer IDs

    // Create producer thread
    pthread_create(&producer, NULL, producer_func, &i);

    // Create consumer threads
    for (int j = 0; j < 3; j++) {
        pthread_create(&consumers[j], NULL, consumer_func, &ids[j]);
    }

    // Join threads
    pthread_join(producer, NULL);
    for (int j = 0; j < 3; j++) {
        pthread_join(consumers[j], NULL);
    }

    return 0;
}
