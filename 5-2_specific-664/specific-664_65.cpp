#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return ready; });
        // Do some work
        do_something(p);
        ready = false;
        lock.unlock();
        cv.notify_all();
    }
}

int main() {
    void *myp[n_threads] = {a_location, another_location, /*...*/};
    std::thread mythread[n_threads];
    
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        std::unique_lock<std::mutex> lock(mtx);
        ready = true;
        cv.notify_all();
        cv.wait(lock, []{ return !ready; });
        
        mix_data(myp);
    }

    // Signal threads to finish
    {
        std::unique_lock<std::mutex> lock(mtx);
        ready = true;
        cv.notify_all();
    }

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
