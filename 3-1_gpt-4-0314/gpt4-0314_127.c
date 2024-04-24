#include <semaphore.h>
#include <pthread.h>

sem_t sem_interrupt;

interrupt_handler(void)
{
  sem_post(&sem_interrupt);
}

monitoring_thread(void) // this thread is started at the start of the program
{
  while(1)
  {
    sem_wait(&sem_interrupt);
    // start the thread here
  }
}

int main(void)
{
  // initialize semaphore
  sem_init(&sem_interrupt, 0 /* pshared */, 0 /* value */);
  
  // start monitoring_thread
  pthread_t monitoring_thread_id;
  pthread_create(&monitoring_thread_id, NULL, (void *)monitoring_thread, NULL);
  
  // your other code
  // ...
  
  // join monitoring_thread and destroy semaphore
  pthread_join(monitoring_thread_id, NULL);
  sem_destroy(&sem_interrupt);

  return 0;
}
