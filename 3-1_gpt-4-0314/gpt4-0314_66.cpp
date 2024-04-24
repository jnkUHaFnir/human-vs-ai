#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;
bool exit_flag = false;

void do_something(void *p) {
    // Your original function implementation
}

void thread_func(void *p) {
    std::unique_lock<std::mutex> lck(mtx);
    while (!exit_flag) {
        cv.wait(lck, [] { return data_ready; });
        if (exit_flag) break;
        do_something(p);
        data_ready = false;
        cv.notify_one();
    }
}

int main() {
    static const int n_threads = 4;
    void *myp[n_threads] = { /* Initialize your memory locations here */ };
    std::vector<std::thread> mythread;
    for (int i = 0; i < n_threads; ++i) {
        mythread.push_back(std::thread(thread_func, myp[i]));
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::unique_lock<std::mutex> lck(mtx);
            data_ready = true;
        }
        cv.notify_all();

        {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [] { return !data_ready; });
        }

        mix_data(myp);
    }

    {
        std::unique_lock<std::mutex> lck(mtx);
        exit_flag = true;
        data_ready = true;
    }
    cv.notify_all();

    for (auto &t : mythread) {
        t.join();
    }

    return 0;
}
