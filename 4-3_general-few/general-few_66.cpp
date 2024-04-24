#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, []{ return ready; });
        do_something(p);
        ready = false;
        ul.unlock();
        cv.notify_one();
    }
}

int main(){
    void * myp[n_threads] {a_location, another_location,...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Main thread is working
        {
            std::unique_lock<std::mutex> ul(mtx);
            ready = true;
            ul.unlock();
            cv.notify_all();
        }

        mix_data(myp); // Data mixing

        // Threads are working
        {
            std::unique_lock<std::mutex> ul(mtx);
            ready = true;
            ul.unlock();
            cv.notify_all();
        }
    }

    // Wait for threads to finish
    for (unsigned int i = 0; i < n_threads; i++) {
        {
            std::unique_lock<std::mutex> ul(mtx);
            ready = true;
            ul.unlock();
            cv.notify_all();
        }
        mythread[i].join();
    }

    return 0;
}
