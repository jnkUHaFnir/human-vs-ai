#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define TNUM 4

pthread_mutex_t mutx;
int cnt = 0;

void *t_function(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutx);
        if(cnt < 1000)
        {
            cnt++;
        }
        pthread_mutex_unlock(&mutx);

        if(cnt >= 1000)
        {
            break;
        }
    }
}

int main()
{
    pthread_t p_thread[TNUM];
    int i;
    clock_t start, end;

    pthread_mutex_init(&mutx, NULL);

    start = clock();

    for(i=0; i<TNUM; i++)
    {
        pthread_create(&p_thread[i], NULL, t_function, NULL);
    }

    for(i=0; i<TNUM; i++)
    {
        pthread_join(p_thread[i], NULL);
    }

    end = clock();

    printf("time : %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
    printf("result : %d\n", cnt);

    return 0;
}
