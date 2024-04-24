#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
#include <memory>
class Worker
{
    public:
        Worker(void* ptr) 
            : m_ptr(ptr), m_run(false), m_exit(false), m_thread([this]() { this->run(); }) {}
        
        void start()
        {
            {
                std::lock_guard<std::mutex> lock(m_mutex);
                m_run = true;
            }
            m_condVar.notify_one();
        }
        
        void stop()
        {
            {
                std::lock_guard<std::mutex> lock(m_mutex);
                m_run = false;
                
                if(m_exit) // Once done, no need to block main thread anymore.
                    return;
            }
            m_thread.join();
        }
        
        void exit()
        {
            {
                std::lock_guard<std::mutex> lock(m_mutex);
                m_exit = true;
            }
            start();
            m_thread.join();
        }
    
    private:
        void* m_ptr;
        bool m_run;
        bool m_exit;

        std::condition_variable m_condVar;
        std::mutex m_mutex;
        
        std::thread m_thread;
        
        void run() 
        {
            while(true)
            {
                std::unique_lock<std::mutex> lock(m_mutex);
                m_condVar.wait(lock, [&]() { return m_run; });
                
                if(m_exit)
                    break;

                // Do your processing here
                do_something(m_ptr);
                
                m_run = false;
            }
        }
};
int main()
{
    std::vector<std::unique_ptr<Worker>> workers;

    void* myp[n_threads] { /*a_location, another_location, ...*/ };
    for(unsigned int i=0; i<n_threads; i++)
    {
        workers.emplace_back(std::make_unique<Worker>(myp[i]));
    }

    for(unsigned long int j=0; j<ULONG_MAX; j++)
    {
        for(auto& worker : workers)
        {
            worker->start();
        }

        for(auto& worker : workers)
        {
            worker->stop();
        }
        
        /* mix_data(myp) */ 
    }

    for(auto& worker : workers)
    {
        worker->exit();
    }

    return 0;
}
```  

But please ensure go through necessary documentation and understand working of condition variables and mutexes, improper use can lead to various concurrency issues.
