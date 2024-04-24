#include <signal.h>
#include <pthread.h>

int interrupt_flag = 0;

void interrupt_handler(int signum)
{
  interrupt_flag = 1;
  pthread_kill(monitoring_thread_id, SIGUSR1); // send signal to monitoring thread
}

void signal_handler(int signum)
{
  // start the thread here
}

pthread_t monitoring_thread_id;

void* monitoring_thread(void* arg)
{
  signal(SIGUSR1, signal_handler);

  while(1)
  {
    // monitor the flag
    if(interrupt_flag)
    {
      interrupt_flag = 0;
      // do something
    }
  }
}

int main()
{
  pthread_create(&monitoring_thread_id, NULL, monitoring_thread, NULL);

  // Set up interrupt handler
  signal(SIGINT, interrupt_handler);

  // Your program logic here
  
  pthread_join(monitoring_thread_id, NULL);
}
