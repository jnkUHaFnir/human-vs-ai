#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void *p) {
    for (;;) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return ready; });
        if (!ready) break; // Break the loop if notified to stop
        // Do your work here with p
    }
}

int main() {
    void *myp[n_threads] = {a_location, another_location,...};
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

        // Simulate main work
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        {
            std::lock_guard<std::mutex> lock(mtx);
            ready = false;
        }
        cv.notify_all();

        mix_data(myp);
    }

    // Notify threads to stop
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = false;
    }
    cv.notify_all();

    // Join threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
