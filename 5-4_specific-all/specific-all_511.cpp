void condition_lock(){
    pthread_mutex_lock(&mutex);
    while(queue.size() == 0){
        printf("Entering conditional lock\n");
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Exiting conditional lock\n");
    // Mutex is re-acquired automatically after pthread_cond_wait() returns
}
void push(int value){
   pthread_mutex_lock(&mutex);
   queue.push_back(value);
   pthread_cond_signal(&cond); // Signal the condition to wake up a waiting thread
   pthread_mutex_unlock(&mutex);
}
