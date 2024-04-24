#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

void myfunc(void* p) {
    while (true) {
        // Wait until notified to start
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock);

        // Do the work
        do_something(p);

        // Notify that work has been completed
        cv.notify_all();
    }
}

int main() {
    void* myp[n_threads] = {a_location, another_location, ...};
    std::thread mythread[n_threads];

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Notify threads to start their work
        cv.notify_all();

        // Wait for all threads to finish
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]() {
                for (unsigned int i = 0; i < n_threads; i++) {
                    if (mythread[i].joinable()) {
                        return false;
                    }
                }
                return true;
            });
        }

        mix_data(myp);
    }

    return 0;
}
