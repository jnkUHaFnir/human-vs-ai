    int interrupt_flag = 0;
    pthread_mutex_t interrupt_lock;
    pthread_cond_t interrupt_cond;
    
    void interrupt_handler(void)
    {
      pthread_mutex_lock(&interrupt_lock);
      interrupt_flag = 1
      pthread_cond_signal(&interrupt_cond);
      pthread_mutex_unlock(&interrupt_lock);
    }
    
    void monitoring_thread(void) //this thread is started at the start of the program
    {
      pthread_mutex_lock(&interrupt_lock);
      while(1)
      {
        if(!interrupt_flag)
        {
          pthread_cond_wait(&interrupt_cond, &interrupt_lock);
          continue;
        }
        else
        {
          interrupt_flag = 0;
          //start the thread here
        }
      }
    }