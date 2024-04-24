void *t_function(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutx);
        
        if(cnt < 1000)
        {
            cnt++;
        }
        else
        {
            pthread_mutex_unlock(&mutx);
            break;
        }
        
        pthread_mutex_unlock(&mutx);
    }
}
