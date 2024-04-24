#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool threads_ready = false;
bool main_ready = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return threads_ready; });

        // Do work
        do_something(p);
        
        main_ready = true;
        cv.notify_all();
    }
}

int main(){
    void *myp[n_threads] = {a_location, another_location,...};
    std::thread mythread[n_threads];
    
    // Create threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Notify threads to start working
        {
            std::lock_guard<std::mutex> lock(mtx);
            threads_ready = true;
            cv.notify_all();
        }

        // Wait for threads to finish
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return main_ready; });
            main_ready = false;
        }

        mix_data(myp); 
    }

    // Signal threads to finish
    {
        std::lock_guard<std::mutex> lock(mtx);
        threads_ready = true;
        cv.notify_all();
    }

    // Join threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
