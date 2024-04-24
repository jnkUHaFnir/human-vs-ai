     using namespace std;
     class semaphore {
         private:
             mutex mMutex;
             condition_variable v;
             int mV;
         public:
             semaphore(int v): mV(v){}
             void signal(int count=1){
                 mMutex.lock();
                 mV+=count;
                 if (mV >= 1) mCond.notify_all();
                 mMutex.unlock();
             }
             void wait(int count = 1){
                 mMutex.lock();
                 mV-= count;
                 while (mV < 0)
                     mCond.wait(mMutex);
                 mMutex.unlock();
             }
     };
    template <typename Task>
    class TaskThread {
         condition_variable *mCond;
         thread *mThread;
         Task *mTask;
         semaphore *mSem;
         volatile bool mRunning;
        public:
        TaskThread(Task *task, condition_variable *cond, semaphore *sem): 
             mTask(task), mCond(cond), mSem(sem) {
            mThread = new thread(run);
        }
        void run(){
            std::unique_lock<std::mutex> lock;
            do {
                 mTask();
                 mSem->signal();
                 mCond->wait(lock);
            } while (mRunning);
        }
       void finish() { // end the thread after the current loop
             mRunning = false;
       }
     };