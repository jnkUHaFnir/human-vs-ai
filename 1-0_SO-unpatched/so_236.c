      while (iTimeOut != 0)
      {
        {
          pthread_mutex_lock(&g_mutex);
          int finished = threadFinished;
          pthread_mutex_unlock(&g_mutex);
          if (finished)
          {
            break;
          }
        }
       
        printf("waiting %d\n",++i);
       
        sleep(1);
        iTimeOut--;
        printf("changing the threadfinish varible\n");
        pthread_mutex_lock(&g_mutex); //statement 1
        threadFinished = 1;
        pthread_mutex_unlock(&g_mutex); // statement 2
        printf("changed the threadfinish varible\n");
      }