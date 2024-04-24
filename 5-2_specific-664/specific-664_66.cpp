#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>

std::mutex threadMutex;
std::condition_variable cv;
bool workerReady = false;
bool mainReady = true;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> locker(threadMutex);
        cv.wait(locker, [] { return workerReady; });

        // Do work here
        do_something(p);

        workerReady = false;
        mainReady = true;
        cv.notify_one();
    }
}

int main() {
    void *myp[n_threads] = {a_location, another_location, ...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; ++i) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        std::unique_lock<std::mutex> locker(threadMutex);

        while (!mainReady) {
            cv.wait(locker);
        }

        // Main work here
        mix_data(myp);

        mainReady = false;
        workerReady = true;
        cv.notify_all();
    }

    return 0;
}
