void condition_lock(){
    pthread_mutex_lock(&mutex);
    while(queue.size() == 0){
        printf("Entering conditional lock\n");
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);
}
void push(int value){
    pthread_mutex_lock(&mutex);
    queue.push_back(value);
    pthread_cond_signal(&cond); // Signal waiting threads when new data is pushed
    pthread_mutex_unlock(&mutex);
}
