#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void *p) {
    do {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return ready; }); // Worker thread waits until ready is set to true
        // Do work here
        do_something(p);
    } while (true);
}

int main() {
    void *myp[n_threads] = {a_location, another_location, ...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = true; // Notify worker threads to start working
        }
        cv.notify_all();

        // Main thread work
        mix_data(myp);

        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = false; // Set ready to false to make worker threads sleep
        }
        cv.notify_all();
    }

    // Join all threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
