#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define TNUM 4

pthread_mutex_t mutx; // Corrected typo: pthread_mutex_t
int cnt = 0;

void *t_function(void *data)
{
    while(1) // Changed condition to an infinite loop
    {
        pthread_mutex_lock(&mutx);
        if(cnt >= 1000) // Check cnt value after acquiring the lock
        {
            pthread_mutex_unlock(&mutx); // Unlock before breaking
            break;
        }
        cnt++;
        pthread_mutex_unlock(&mutx);
    }
}

int main()
{
    pthread_t p_thread[TNUM];
    int thr_id[TNUM];
    int status;
    int i;
    clock_t start, end;

    // Initialize mutex before using
    if(pthread_mutex_init(&mutx, NULL) != 0)
    {
        perror("Mutex init failed");
        return 1; // Exit if mutex init fails
    }

    start = clock();

    for(i=0; i<TNUM; i++)
    {
        thr_id[i] = pthread_create(&p_thread[i], NULL, t_function, NULL);
        if(thr_id[i] < 0)
        {
            perror("thread create error: ");
            exit(i);
        }
    }

    for(i=0; i<TNUM; i++)
    {
        pthread_join(p_thread[i], (void**)&status);
    }

    end = clock();

    printf("time : %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
    printf("result : %d\n", cnt);

    // Destroy mutex after using
    pthread_mutex_destroy(&mutx);
    
    return 0;
}
