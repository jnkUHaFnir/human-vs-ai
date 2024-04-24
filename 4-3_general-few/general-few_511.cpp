void condition_lock(){
    pthread_mutex_lock(&mutex);
    while(queue.size() == 0){
        printf("Entering conditional lock\n");
        pthread_cond_wait(&cond,&mutex);
    }
    pthread_mutex_unlock(&mutex); // Unlock before leaving the method
}
