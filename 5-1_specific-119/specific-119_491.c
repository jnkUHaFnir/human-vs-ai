#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

pthread_cond_t conds[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int signals[NUM_THREADS] = {0};

void *consumer(void *thread_id) {
    int id = *((int *)thread_id);

    pthread_mutex_lock(&mutex);
    signals[id] = 1;
    while (signals[id] == 1) {
        pthread_cond_wait(&conds[id], &mutex);
    }
    pthread_mutex_unlock(&mutex);

    printf("Consumer %d received a signal.\n", id);

    pthread_exit(NULL);
}

void producer() {
    for (int i = 0; i < NUM_THREADS; i++) {
        if (signals[i] == 1) {
            __sync_bool_compare_and_swap(&signals[i], 1, 0); // Atomically set signal to 0
            pthread_mutex_lock(&mutex);
            pthread_cond_broadcast(&conds[i]);
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cond_init(&conds[i], NULL);
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, consumer, &thread_ids[i]);
    }

    // Producer
    producer();

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cond_destroy(&conds[i]);
    }

    return 0;
}
