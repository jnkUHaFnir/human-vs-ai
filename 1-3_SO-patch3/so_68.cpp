        void start_thread(Worker worker){ // worker passed by value
                                          // thus it is a copy.
            stop = false;
            int status = pthread_create(&thread,NULL,
                             run_helper,&worker); // Address of worker passed to thread.
        }   // worker destroyed here.