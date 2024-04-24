#include <pthread.h>

#define NUM_CONSUMERS 3

pthread_mutex_t mutex;
pthread_cond_t conds[NUM_CONSUMERS];
int signals[NUM_CONSUMERS] = {0};

void* consumer(void* arg) {
    int consumer_id = *((int*)arg);

    pthread_mutex_lock(&mutex);
    signals[consumer_id] = 1;
    while (signals[consumer_id] == 1) {
        pthread_cond_wait(&conds[consumer_id], &mutex);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void producer() {
    // Check signals for each consumer and handle them one by one
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        if (signals[i] == 1) {
            __atomic_clear(&signals[i], __ATOMIC_SEQ_CST); // Atomically set signal to 0

            pthread_mutex_lock(&mutex);
            pthread_cond_broadcast(&conds[i]);
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main() {
    pthread_t consumer_threads[NUM_CONSUMERS];
    int consumer_ids[NUM_CONSUMERS];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_cond_init(&conds[i], NULL);
        consumer_ids[i] = i;
        pthread_create(&consumer_threads[i], NULL, consumer, &consumer_ids[i]);
    }

    // Run the producer function periodically or as needed

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumer_threads[i], NULL);
        pthread_cond_destroy(&conds[i]);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
