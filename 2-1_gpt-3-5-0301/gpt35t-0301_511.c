int status = pthread_create(&thread, NULL, run_helper, this);
pthread_cond_broadcast(&cond);
while(queue.size() > 0){
    printf("item: %d\n",queue.front());
    queue.erase(queue.begin());
}
