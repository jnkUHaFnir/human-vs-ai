#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define TNUM 4

pthread_mutex_t mutx;
pthread_cond_t cond;
int cnt = 0;

void *t_function(void *data)
{
    while (1)
    {
        pthread_mutex_lock(&mutx);
        if (cnt >= 1000)
        {
            pthread_mutex_unlock(&mutx);
            break;
        }
        cnt++;
        pthread_mutex_unlock(&mutx);
    }
}

int main()
{
    pthread_t p_thread[TNUM];
    int i;
    clock_t start, end;

    pthread_mutex_init(&mutx, NULL);
    pthread_cond_init(&cond, NULL);

    start = clock();

    for (i = 0; i < TNUM; i++)
    {
        pthread_create(&p_thread[i], NULL, t_function, NULL);
    }

    for (i = 0; i < TNUM; i++)
    {
        pthread_join(p_thread[i], NULL);
    }

    end = clock();

    printf("time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("result : %d\n", cnt);

    pthread_mutex_destroy(&mutx);
    pthread_cond_destroy(&cond);

    return 0;
}
