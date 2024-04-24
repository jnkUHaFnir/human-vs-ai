#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false; // Indicates when there's work to do
bool done = false;  // Indicates when to exit

void myfunc(void * p, int id) {
    while (true) {
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [&]{return ready || done;}); // Wait until ready or done
        if(done) break;

        // Do something with p, like the previous myfunc
        // Example:
        // do_something(p);

        std::cout << "Thread " << id << " completed work.\n";
        lk.unlock();
    }
}

void notify_threads() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        ready = true;   // Set work ready flag
    }
    cv.notify_all();  // Wake all threads
}

void wait_for_threads() {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, []{return !ready;}); // Wait for ready to be reset
}

void done_with_threads() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        done = true; // Tell threads to exit
    }
    cv.notify_all();  // Wake all threads
}

int main() {
    const int n_threads = 4;
    std::vector<std::thread> mythreads;

    // Create threads
    for (int i = 0; i < n_threads; ++i) {
        void* p = nullptr;  // Assign real work pointers as needed
        mythreads.emplace_back(myfunc, p, i);
    }

    for (unsigned long int j = 0; j < 10; ++j) { // Example loop count
        notify_threads();  // Signal threads that work is ready
        // Do main work here while threads are also working, if any, eg:
        // mix_data();
        
        // Signal no more work for now
        {
            std::lock_guard<std::mutex> lk(mtx);
            ready = false;
        }
        
        wait_for_threads();  // Wait for threads to finish current work
    }

    // Cleanup
    done_with_threads();  // Signal threads to finish
    for (auto& t : mythreads) {
        if(t.joinable()) t.join();
    }

    return 0;
}
