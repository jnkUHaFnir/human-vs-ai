#include <thread>
#include <climits>
#include <condition_variable>
#include <mutex>
#include <atomic>

std::condition_variable cv;
std::mutex mtx;
std::atomic<bool> ready{false};

void myfunc(void * p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return ready; }); // Wait until notified to proceed
        // Do work with p
        // Assuming do_something is a placeholder
        do_something(p);
        ready = false; // Reset ready flag
        cv.notify_one(); // Notify main that work is done
    }
}

int main() {
    void * myp[n_threads] = {a_location, another_location};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Perform data mixing
        mix_data(myp);

        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = true; // Notify threads to proceed
        }

        cv.notify_all(); // Notify all threads to wake up

        // Do some work in main while threads are busy

        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return !ready; }); // Wait for threads to finish
        }
    }

    // Signal threads to stop
    ready = true;
    cv.notify_all();

    // Join threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
