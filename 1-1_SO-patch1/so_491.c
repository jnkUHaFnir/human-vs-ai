    pthread_mutex_lock(&mutex);
    pthread_cond_broadcast(&cond); /* or signal */
    pthread_mutex_unlock(&mutex);