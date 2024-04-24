#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

constexpr unsigned int n_threads = SOME_VALUE;  // Set this to the desired number of threads
std::mutex mutexes[n_threads];
std::condition_variable cvars[n_threads];
bool ready[n_threads] = {false};
bool processed[n_threads] = {false};
bool terminate = false;

void myfunc(int id, void *p) {
    std::unique_lock<std::mutex> lock(mutexes[id]);
    while (!terminate) {  // Loop to keep thread alive
        // Wait until main thread sends data to be processed
        cvars[id].wait(lock, [&]{ return ready[id]; });

        if (terminate) break;  // If we're terminating, exit the loop

        do_something(p); // Your original data processing function
        
        // Signal that processing is complete
        processed[id] = true;

        // Notify main thread
        cvars[id].notify_one();

        // Wait for main thread to acknowledge processing
        cvars[id].wait(lock, [&] { return !ready[id]; });
    }
}

int main() {
    void *my_p[n_threads]; // assign proper values to these pointers

    // Create and detach n threads
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < n_threads; ++i) {
        threads.emplace_back(myfunc, i, my_p[i]);
    }

    for (unsigned long int j=0; j < ULONG_MAX; ++j) {
        // Notify worker threads that they can start processing
        for (unsigned int i = 0; i < n_threads; ++i) {
            std::unique_lock<std::mutex> lock(mutexes[i]);
            ready[i] = true;
            cvars[i].notify_one();
        }

        // Wait for all threads to finish processing
        for (unsigned int i = 0; i < n_threads; ++i) {
            std::unique_lock<std::mutex> lock(mutexes[i]);
            cvars[i].wait(lock, [&] { return processed[i]; });
        }

        // Reset processed flags and mix data
        for (unsigned int i = 0; i < n_threads; ++i) {
            processed[i] = false;
            ready[i] = false;
        }

        mix_data(my_p);

        // After data mixing, worker threads can be re-notified
    }

    // Notify threads to terminate
    terminate = true;
    for (unsigned int i = 0; i < n_threads; ++i) {
        std::unique_lock<std::mutex> lock(mutexes[i]);
        ready[i] = true;
        cvars[i].notify_one();
    }

    // Cleanup: Join all the threads
    for (std::thread &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    return 0;
}
