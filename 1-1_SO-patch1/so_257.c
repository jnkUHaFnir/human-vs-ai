    pthread_mutex_lock(&mutx);
    while(cnt < 1000)
    { 
        cnt++;
    }
    pthread_mutex_unlock(&mutx);