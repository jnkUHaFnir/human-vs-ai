#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

// Define global variables for synchronization
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return ready; });
        // Do work with p
        // For demonstration, let's print the address stored in p
        std::cout << "Working on: " << p << std::endl;
        ready = false;
        lock.unlock();
    }
}

int main() {
    void *myp[n_threads] = {a_location, another_location, ...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Main thread work
        // If you want to notify threads simultaneously uncomment the next 3 lines
        // ready = true;
        // cv.notify_all();
        // Do work in main thread
        mix_data(myp);

        // Notify worker threads to resume
        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = true;
        }
        cv.notify_all();
    }

    // Join threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
