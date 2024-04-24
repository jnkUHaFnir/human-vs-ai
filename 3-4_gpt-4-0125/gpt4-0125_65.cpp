#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>

const int n_threads = 4; // Example number of threads

std::mutex mutex;
std::condition_variable cv;
std::atomic<bool> ready(false);
std::atomic<bool> finished(false);
std::atomic<int> working(0); // Keep track of working threads

void do_something(void* p) {
    // Example work
}

void myfunc(void* p) {
    while (!finished) {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [] {return ready || finished; });
        if (finished) break;

        ++working;
        lock.unlock();

        do_something(p);

        lock.lock();
        --working;
        if (working == 0) {
            cv.notify_one(); // Notify main thread if all work is done
        }
    }
}

void mix_data(void** myp) {
    // Example work
}

int main() {
    void* myp[n_threads] = {/* Initialize pointers here */};
    std::vector<std::thread> threads;

    // Create threads
    for (int i = 0; i < n_threads; ++i) {
        threads.emplace_back(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < 100; ++j) { // Example loop condition
        // Notify threads there's work
        {
            std::lock_guard<std::mutex> lock(mutex);
            ready = true;
        }
        cv.notify_all();

        // Now wait for threads to finish
        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [] {return working == 0; });
        }

        // Safe to work with shared data
        mix_data(myp);

        // Prepare for next iteration
        ready = false;
    }

    // Notify threads to exit
    finished = true;
    cv.notify_all();

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
