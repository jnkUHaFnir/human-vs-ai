#include <thread>
#include <mutex>
#include <condition_variable>
#include <climits>

...

std::mutex mtx;
std::condition_variable cv;

void myfunc(void * p, int &ready_count, int thread_id) {
    std::unique_lock<std::mutex> lock(mtx);
    while (true) {
        cv.wait(lock, [&ready_count, thread_id] { return ready_count == thread_id; });
        // Do some work
        do_something(p);
        ready_count++;
        cv.notify_all();
    }
}

int main(){
    void * myp[n_threads] = {a_location, another_location,...};
    std::thread mythread[n_threads];
    int ready_count = 0;

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i], std::ref(ready_count), i);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&ready_count] { return ready_count == n_threads; });

        // Main thread working
        mix_data(myp);

        ready_count = 0;
        cv.notify_all();
    }

    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
