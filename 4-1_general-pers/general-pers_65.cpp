#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void myfunc(void * p) {
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, []{ return ready; });
        do_something(p);
        ready = false;
        lck.unlock();
        cv.notify_one();
    }
}

int main(){
    void * myp[n_threads] = {a_location, another_location,...};
    std::thread mythread[n_threads];
    
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }
    
    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        std::unique_lock<std::mutex> lck(mtx);
        ready = true;
        cv.notify_all();
        cv.wait(lck, []{ return !ready; });
        mix_data(myp);
    }

    return 0;
}
