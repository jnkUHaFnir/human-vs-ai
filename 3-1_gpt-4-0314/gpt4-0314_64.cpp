#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>
#include <vector>

constexpr unsigned int n_threads = 5;

std::mutex mtx;
std::condition_variable cv_main, cv_workers;
bool data_ready = false;
bool exit_flag = false;

void myfunc(int id, void *p) {
    std::unique_lock<std::mutex> lock(mtx);

    while (!exit_flag) {
        cv_workers.wait(lock, [] { return data_ready || exit_flag; });
        if (!exit_flag) {
            std::cout << "Thread " << id << " processing data..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            data_ready = false;
            cv_main.notify_one();
        }
    }
    std::cout << "Thread " << id << " exiting..." << std::endl;
}

int main() {
    void *myp[n_threads] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<std::thread> mythread(n_threads);

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, i, myp[i]);
    }

    for (unsigned long int j = 0; j < 10; j++) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "Main thread preparing data..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            data_ready = true;
            cv_workers.notify_all();
        }
        std::unique_lock<std::mutex> lock(mtx);
        cv_main.wait(lock, [] { return !data_ready; });
        std::cout << "Main thread mixing data..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    {
        std::unique_lock<std::mutex> lock(mtx);
        exit_flag = true;
        cv_workers.notify_all();
    }

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    std::cout << "Main thread exiting..." << std::endl;
    return 0;
}
