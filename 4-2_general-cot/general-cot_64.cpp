#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
bool processed = false;

void myfunc(void *p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return ready; });
        
        // Do some work
        // For demonstration, we just print the pointer value
        std::cout << "Working on: " << p << std::endl;
        
        // Notify main that work is done
        processed = true;
        lock.unlock();
        cv.notify_all();
    }
}

int main() {
    const int n_threads = 5;
    void *myp[n_threads] = { (void*)1, (void*)2, (void*)3, (void*)4, (void*)5 };
    std::vector<std::thread> mythread;
    
    for (int i = 0; i < n_threads; i++) {
        mythread.push_back(std::thread(myfunc, myp[i]));
    }

    for (unsigned long int j = 0; j < 10; j++) {
        // Notify threads to start working
        {
            std::unique_lock<std::mutex> lock(mtx);
            ready = true;
            cv.notify_all();
        }

        // Do some work in main
        // For demonstration, we just sleep
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Wait for threads to finish
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return processed; });
            ready = false;
            processed = false;
        }
        
        // Do data mixing
        std::cout << "Mixing data..." << std::endl;
    }

    // Join all threads
    for (auto &t : mythread) {
        t.join();
    }

    return 0;
}
