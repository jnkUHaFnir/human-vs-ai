#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

const size_t n_threads = 4;

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
bool done = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return ready || done; });

        if (done)
            return;

        do_something(p);
        ready = false;
        cv.notify_one();
    }
}

int main() {
    void *myp[n_threads]{a_location, another_location, ...};
    std::vector<std::thread> mythread;

    for (size_t i = 0; i < n_threads; i++) {
        mythread.emplace_back(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        for (size_t i = 0; i < n_threads; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            ready = true;
            cv.notify_one();
            cv.wait(lock, [] { return !ready; });
        }
        mix_data(myp);
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();

    for (size_t i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
