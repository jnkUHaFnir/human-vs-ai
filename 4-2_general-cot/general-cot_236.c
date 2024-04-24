#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define TIMEOUT 3

int threadFinished = 0;
pthread_mutex_t g_mutex;

void *threadFunction(void* attr)
{
    pthread_mutex_lock(&g_mutex);
    char *pData = (char*)attr;
    if(pData)
    {
        printf("data from main thread is: %s\n", pData);
    }
    sleep(10);
    threadFinished = 1;
    pthread_mutex_unlock(&g_mutex);
    return (void*)"This is thread message!";
}

int main()
{
    pthread_t tid;
    char *retVal = NULL;
    int iTimeOut = TIMEOUT;
    int i =0;
    pthread_mutex_init(&g_mutex, NULL);
    pthread_create(&tid, NULL, threadFunction, "Message from main thread");

    while(iTimeOut != 0 && !threadFinished)
    {
        printf("waiting %d\n", ++i);
        sleep(1);
        iTimeOut--;
    }

    pthread_mutex_lock(&g_mutex); // Lock the mutex before checking/modifying threadFinished
    if(iTimeOut == 0)
    {
        if(!threadFinished)
        {
            printf("Timed out so cancelling the thread\n");
            pthread_cancel(tid);
        }
        else
        {
            printf("Thread finished\n");
        }
    }
    else
    {
        printf("Thread finished its job\n");
        pthread_join(tid, (void**)&retVal);
    }
    pthread_mutex_unlock(&g_mutex);

    pthread_mutex_destroy(&g_mutex);

    printf("Message from thread is: %s\n", retVal);
    return 0;
}
