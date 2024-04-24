#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

const int n_threads = 4; // Set the number of threads you want
std::mutex mtx; // A mutex for synchronization
std::condition_variable cv; // Condition variable for signaling
bool ready = false; // A boolean flag to check if the thread should work
bool finished = false; // Flag to signal to threads to exit

void do_something(void* p) {
    // Dummy function to emulate work
}

void myfunc(void* p, int thread_id) {
    while (true) {
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, []{return ready || finished;});

        if (finished) break; // If finished is true, exit the thread

        // Once notified, and not finished, do the work
        do_something(p);

        // Optionally: Notify the main thread that work has finished
        // This is only necessary if main thread should wait after each iteration
        lk.unlock();
        cv.notify_one();

        // Thread goes back to wait state
    }
}

void mix_data(void* myp[]) {
    // Dummy function to represent data mixing
}

int main() {
    void* myp[n_threads] = { /* Initialize with your data locations */ };
    std::vector<std::thread> mythreads;

    // Spawn all threads. They start and immediately wait for work
    for (int i = 0; i < n_threads; ++i) {
        mythreads.emplace_back(myfunc, myp[i], i);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Lock, set the work flag to true, unlock, and notify threads
        {
            std::lock_guard<std::mutex> lk(mtx);
            ready = true;
        }
        cv.notify_all();

        // Optionally: If you need the main thread to wait after each iteration:
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, []{return !ready;}); // Wait for all threads to finish their current work

        // Main thread does its work of mixing data
        mix_data(myp); 

        // Reset the flag and start over
        ready = false;
    }

    // Time to stop all threads
    {
        std::lock_guard<std::mutex> lk(mtx);
        finished = true;
    }
    cv.notify_all();

    // Join all threads
    for (auto& thr : mythreads) {
        thr.join();
    }

    return 0;
}
