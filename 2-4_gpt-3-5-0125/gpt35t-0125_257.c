#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define TNUM 4

pthread_mutex_t mutx;
pthread_cond_t cond;
int cnt = 0;
int turn = 0;


void *t_function(void *data)
{

    while(cnt < 1000)
    {
        pthread_mutex_lock(&mutx);
        while(turn != (int)data)
        {
            pthread_cond_wait(&cond, &mutx);
        }
        cnt++;
        turn = (turn + 1) % TNUM;
        pthread_cond_broadcast(&cond);
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
    pthread_cond_init(&cond, NULL);

    start = clock();

    for(i=0; i<TNUM; i++)
    {
        thr_id[i] = pthread_create(&p_thread[i], NULL, t_function, (void*)i);
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
    return 0;
}
