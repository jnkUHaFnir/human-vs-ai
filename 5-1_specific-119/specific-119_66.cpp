#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
bool threads_ready = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return threads_ready; });
        // Do work here
        // For example: do_something(p);
        lock.unlock();
        cv.notify_one();
    }
}

int main() {
    void *myp[n_threads] = {a_location, another_location, ...};
    std::vector<std::thread> mythread;
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread.emplace_back(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            threads_ready = true;
        }
        cv.notify_all();

        // Main thread work
        mix_data(myp);

        {
            std::unique_lock<std::mutex> lock(mtx);
            threads_ready = false;
        }
        cv.notify_all();
    }

    for (std::thread& t : mythread) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}
