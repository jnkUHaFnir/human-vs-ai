#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

constexpr int n_threads = 4; // Example thread count
std::mutex mutex;
std::condition_variable cv;
bool ready = false;
bool finished = false;
int active_threads = 0;

void myfunc(void *p) {
    std::unique_lock<std::mutex> lock(mutex);
    while(true) {
        cv.wait(lock, [] { return ready || finished; });

        if (finished) {
            break; // Exit if finished
        }

        do_something(p);
        
        // Decrease active thread count and notify main if all threads are done
        if (--active_threads == 0) {
            cv.notify_one();
        }

        // Wait until the mixing is done and they're ready to be reactivated.
        cv.wait(lock, [] { return !ready; });
    }
}

int main() {
    void *myp[n_threads] = { /* a_location, another_location, ... */ };

    // Create worker threads
    std::vector<std::thread> threads;
    for (int i = 0; i < n_threads; i++) {
        threads.emplace_back(myfunc, myp[i]);
    }

    // Repeatedly run the threads and mix the data
    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::unique_lock<std::mutex> lock(mutex);
            ready = true;
            active_threads = n_threads;
        }

        cv.notify_all(); // Notify all threads to start work

        // Wait for all threads to finish
        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [] { return active_threads == 0; });
            ready = false;
        }

        mix_data(myp); // Mix the data

        cv.notify_all(); // Notify all threads that mixing is done and they can wait for next work
    }

    // Notify threads to exit
    {
        std::lock_guard<std::mutex> lock(mutex);
        finished = true;
    }
    cv.notify_all();

    // Join all threads before exiting
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
