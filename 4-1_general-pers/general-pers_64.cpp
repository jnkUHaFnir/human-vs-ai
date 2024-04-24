#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [] { return ready; });
        // Do work here with p
        lck.unlock();
    }
}

int main() {
    void *myp[n_threads] { a_location, another_location, ... };
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        std::unique_lock<std::mutex> lck(mtx);
        ready = true;
        cv.notify_all();
        // Main thread work
        ready = false;
        cv.notify_all();
    }

    for (unsigned int i = 0; i < n_threads; i++) {
        {
            std::unique_lock<std::mutex> lck(mtx);
            ready = true;
            cv.notify_all();
        }
        mythread[i].join();
    }

    return 0;
}
