void interrupt(){
    printf("Going to interrupt\n");
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond); //signal the condition
    pthread_mutex_unlock(&mutex); //unlock the mutex so that condition_lock can acquire it
    printf("interrupted \n");
}
