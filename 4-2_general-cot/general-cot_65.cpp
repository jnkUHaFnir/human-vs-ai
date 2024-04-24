#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void *p) {
    while (true) {
        // Wait until notified by the main thread
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return ready; });

        // Do the actual work
        do_something(p);

        // Notify the main thread that this thread has finished its work
        ready = false;
        lock.unlock();
        cv.notify_one();
    }
}

int main(){
    void *myp[n_threads] = {a_location, another_location,...};
    std::thread mythread[n_threads];

    for (unsigned int i=0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j=0; j < ULONG_MAX; j++) {
        // Do work in the main thread

        // Notify all threads to start their work
        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = true;
        }
        cv.notify_all();

        // Wait for all threads to finish
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{ return !ready; });
        }

        mix_data(myp);
    }

    // Stop the threads
    ready = true;
    cv.notify_all();

    // Join all threads
    for (unsigned int i=0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
