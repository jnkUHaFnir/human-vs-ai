#include <signal.h>

volatile sig_atomic_t interrupt_flag = 0;

void interrupt_handler(int signal)
{
  interrupt_flag = 1;
}

void signal_handler(int signal)
{
  //start the thread here
}

int main()
{
  struct sigaction sa;
  sa.sa_handler = interrupt_handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(SIGINT, &sa, NULL);

  while(1)
  {
    if(interrupt_flag)
    {
      interrupt_flag = 0;
      
      signal(SIGUSR1, signal_handler);
      raise(SIGUSR1);

      sleep(/*some amount of time*/); // not recommended to use sleep in real-time applications
    }
  }

  return 0;
}
