#include <thread>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <climits>

std::mutex mtx;
std::condition_variable cv;
std::atomic<bool> shouldWakeUp(false);
std::atomic<bool> mainDone(false);

void myfunc(void* p) {
  while (true) {
    {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, []() { return shouldWakeUp || mainDone; });
      
      if (mainDone) {
        break;
      }
      
      do_something(p);
    }
    
    // Sleep until main thread wakes us up again
    shouldWakeUp = false;
  }
}

int main() {
  void* myp[n_threads] {a_location, another_location, ...};
  std::thread mythread[n_threads];
  
  for (unsigned long int j = 0; j < ULONG_MAX; j++) {
    // Create threads
    for (unsigned int i = 0; i < n_threads; i++) {
      mythread[i] = std::thread(myfunc, myp[i]);
    }
    
    // Notify threads to start processing
    {
      std::lock_guard<std::mutex> lock(mtx);
      shouldWakeUp = true;
    }
    cv.notify_all();
    
    // Wait for threads to finish processing
    for (unsigned int i = 0; i < n_threads; i++) {
      mythread[i].join();
    }
    
    // Mix data
    mix_data(myp);
  }
  
  // Notify threads to stop processing
  {
    std::lock_guard<std::mutex> lock(mtx);
    mainDone = true;
  }
  cv.notify_all();
  
  // Wait for threads to finish and exit
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i].join();
  }
  
  return 0;
}