void *t_function(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutx);
        if(cnt >= 1000) {
            pthread_mutex_unlock(&mutx);
            break;
        }
        cnt++;
        pthread_mutex_unlock(&mutx);
    }
}
