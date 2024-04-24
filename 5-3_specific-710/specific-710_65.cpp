#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
bool processed = false;

void myfunc(void* p) {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [] { return ready; });
        // Do work here
        do_something(p);

        processed = true;
        ready = false;
        cv.notify_one();
    }
}

int main() {
    void* myp[n_threads] = {a_location, another_location, ...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::lock_guard<std::mutex> lck(mtx);
            ready = true;
            cv.notify_all();
            cv.wait(lck, [] { return processed; });
            processed = false;
        }

        // Main thread work
        mix_data(myp);
    }

    for (unsigned int i = 0; i < n_threads; i++) {
        {
            std::lock_guard<std::mutex> lck(mtx);
            ready = true;
            cv.notify_all();
            cv.wait(lck, [] { return processed; });
            processed = false;
        }
    }

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
