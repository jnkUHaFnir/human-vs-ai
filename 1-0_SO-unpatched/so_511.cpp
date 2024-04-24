         void start_thread(){
              stop = false;
              int status = pthread_create(&thread, NULL, run_helper, this);
          }