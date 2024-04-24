#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define TNUM 4

pthread_mutex_t mutx;
int cnt = 0;
int max_count = 1000; // set the maximum count limit

void *t_function(void *data)
{
    while (1)
    {
        pthread_mutex_lock(&mutx);
        
        // Check if count has reached the limit
        if(cnt >= max_count)
        {
            pthread_mutex_unlock(&mutx);
            break; // Exit the loop if limit is reached
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

    status = pthread_mutex_init(&mutx, NULL);

    start = clock();

    for(i = 0; i < TNUM; i++)
    {
        thr_id[i] = pthread_create(&p_thread[i], NULL, t_function, NULL);
        if (thr_id[i] < 0)
        {
            perror("thread create error: ");
            exit(i);
        }
    }

    for(i = 0; i < TNUM; i++)
    {
        pthread_join(p_thread[i], NULL);
    }

    end = clock();

    printf("time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("result : %d\n", cnt);

    pthread_mutex_destroy(&mutx);

    return 0;
}
