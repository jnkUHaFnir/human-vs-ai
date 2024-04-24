void push(int value){
    pthread_mutex_lock(&mutex);
    queue.push_back(value);
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
}
void condition_lock(){
    pthread_mutex_lock(&mutex);
    while(queue.size() == 0){
        printf("Entering conditional lock\n");
        pthread_cond_wait(&cond,&mutex);
    }
    pthread_mutex_unlock(&mutex);
}
void start_thread(Worker *worker){
    stop = false;
    int status = pthread_create(&thread,NULL,run_helper,worker);
}
static void *run_helper(void* context){
    return ((Worker *)context)->run();
}
