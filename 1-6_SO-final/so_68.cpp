       void condition_lock(bool condition){
            pthread_mutex_lock(&mutex);
            if(condition){
        //  ^^^^ Should be while(<validate some invariant>)
                printf("Entering conditional lock\n");
                pthread_cond_wait(&cond,&mutex);
            }
            pthread_mutex_unlock(&mutex);
        }