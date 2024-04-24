void consumer_function() {
    pthread_mutex_lock(&mutex);    // Lock the mutex
    while(signal[i] == 1) {
        pthread_cond_wait(&cond, &mutex); // Wait for the condition variable to be signaled
    }
    // Do work here...
    pthread_mutex_unlock(&mutex);  // Unlock the mutex
}
void producer_function() {
    // Do some work and determine that a condition has been met to notify consumers.

    if(signal == 1) {
        // Set signal to 0 for all consumers (must be done with appropriate synchronization)
        // ...

        pthread_mutex_lock(&mutex);            // Lock the mutex
        pthread_cond_broadcast(&cond);         // Wake up all waiting consumers
        pthread_mutex_unlock(&mutex);          // Unlock the mutex
    }
}
