#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

// Assuming you have defined or will define these somewhere
void do_something(void* p);
void mix_data(void* p[]);

constexpr int n_threads = /* number of threads you want */;

std::mutex mtx;
std::condition_variable cv;
bool ready_to_work = false;
bool program_done = false;

void thread_function(int id, void* p) {
    std::unique_lock<std::mutex> lock(mtx);
    while (!program_done) {
        cv.wait(lock, [](){ return ready_to_work || program_done; });
        if (!program_done) {
            lock.unlock();
            do_something(p); // Perform work
            lock.lock();
        }
        ready_to_work = false;
    }
}

int main() {
    void* myp[n_threads] = {/* initialize your pointers */};
    std::vector<std::thread> threads;

    // Spawn threads
    for (int i = 0; i < n_threads; ++i) {
        threads.emplace_back(thread_function, i, myp[i]);
    }

    for (unsigned long int j = 0; j < /* your loop condition, e.g., some max value */; ++j) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            ready_to_work = true;
        }
        cv.notify_all(); // Tell all threads to start working

        // Wait for all threads to finish
        while (! /* condition indicating threads are done */ ) {
            // You might setup another condition variable that threads signal when done
        }
        
        mix_data(myp); // Modify data in main thread

        {
            std::unique_lock<std::mutex> lock(mtx);
            ready_to_work = false;
        }
        // Optionally, tell main thread to work using another cv.notify_one() or similar mechanism
    }

    // Signal threads to exit
    {
        std::unique_lock<std::mutex> lock(mtx);
        program_done = true;
        ready_to_work = true; // Make sure threads wake up to check program_done
    }
    cv.notify_all();

    // Join threads
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
