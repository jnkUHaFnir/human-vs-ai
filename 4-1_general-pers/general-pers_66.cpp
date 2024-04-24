#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool threads_ready = false;

void myfunc(void* p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return threads_ready; });
        // Do work with p
        lock.unlock();
        // Signal that work is done
        cv.notify_one();
    }
}

int main() {
    void* myp[n_threads] {a_location, another_location,...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Notify threads to start
        {
            std::lock_guard<std::mutex> lock(mtx);
            threads_ready = true;
        }
        cv.notify_all();

        // Do main work
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return !threads_ready; });
        }

        mix_data(myp);

        // Notify threads to start again
        {
            std::lock_guard<std::mutex> lock(mtx);
            threads_ready = true;
        }
        cv.notify_all();
    }

    // Cleanup
    {
        std::lock_guard<std::mutex> lock(mtx);
        threads_ready = true;
    }
    cv.notify_all();

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
