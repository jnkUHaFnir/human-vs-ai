#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int interrupt_flag = 0;

void interrupt_handler(void)
{
  pthread_mutex_lock(&mutex);
  interrupt_flag = 1;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);
}

void* monitoring_thread(void* arg)
{
  pthread_mutex_lock(&mutex);
  while(1)
  {
    if(!interrupt_flag)
    {
      pthread_cond_wait(&cond, &mutex);
    }
    //start the thread here
    interrupt_flag = 0;
    // Optionally add a small delay to improve performance
    usleep(1000);
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main()
{
  pthread_t monitor_thread;
  pthread_create(&monitor_thread, NULL, monitoring_thread, NULL);
  // rest of your program
  return 0;
}
