pthread_mutex_t mutex;
pthread_cond_t cond[3]; // One condition variable for each consumer
int signal[3] = {0}; // Each consumer thread has its own signal

// Consumer thread function
void* consumer_thread(void* arg) {
    int i = *((int*)arg);
    
    pthread_mutex_lock(&mutex);
    signal[i] = 1;
    while(signal[i] == 1) {
        pthread_cond_wait(&cond[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

// Producer code
void producer_function() {
    // Assume the producer knows which consumer to signal

    int consumer_to_signal = 0; // For example, signaling consumer 0
    if(signal[consumer_to_signal] == 1) {
        // Set signal to 0 atomically using CAS
        pthread_mutex_lock(&mutex);
        signal[consumer_to_signal] = 0;
        pthread_cond_broadcast(&cond[consumer_to_signal]); // Signal the specific consumer
        pthread_mutex_unlock(&mutex);
    }
}
