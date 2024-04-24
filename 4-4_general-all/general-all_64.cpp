#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void* p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return ready; });
        // Do work with p
        do_something(p);
        cv.notify_one();
    }
}

int main() {
    void* myp[n_threads] = {a_location, another_location,...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = true;
        }
        cv.notify_all();

        // Main thread work
        mix_data(myp);

        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = false;
        }
        cv.notify_all();
    }

    // Notify threads to finish
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_all();

    // Join threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
