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
        public:
        TaskThread(Task *task, condition_variable *cond, semaphore *sem): 
             mTask(task), mCond(cond), mSem(sem) {
            mThread = new thread(run);
        }
        void run(){
            std::unique_lock<std::mutex> lock;
            while(true){
                 mTask();
                 mSem->signal();
                 mCond->wait(lock);
            }
     };