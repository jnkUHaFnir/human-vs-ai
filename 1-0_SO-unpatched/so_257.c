    while(cnt < 1000) { 
        pthread_mutex_lock(&mutx); 
        if (cnt < 1000)  
            cnt++; 
        pthread_mutex_unlock(&mutx); 
    }