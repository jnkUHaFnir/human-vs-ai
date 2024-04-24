#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx; // Mutex to synchronize access to the condition variable
std::condition_variable cv; // Condition variable for thread synchronization
bool isReady = false; // Boolean flag to indicate whether threads should be running or sleeping

void myfunc(void * p) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    
    // Wait until the main thread signals that the worker threads should run
    cv.wait(lock, []{ return isReady; });
    
    // Check if the threads should terminate
    if (!isReady) {
      break;
    }
    
    // Do the work
    do_something(p);
  }
}

int main() {
  void * myp[n_threads] {a_location, another_location, ...};
  std::thread mythread[n_threads];
  
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i] = std::thread(myfunc, myp[i]);
  }
  
  for (unsigned long int j = 0; j < ULONG_MAX; j++) {
    // Signal the worker threads to start running
    {
      std::lock_guard<std::mutex> lock(mtx);
      isReady = true;
    }
    cv.notify_all();
    
    // Wait for the worker threads to complete their work
    for (unsigned int i = 0; i < n_threads; i++) {
      mythread[i].join();
    }
    
    // Mix data
    mix_data(myp);
    
    // Signal the worker threads to sleep
    {
      std::lock_guard<std::mutex> lock(mtx);
      isReady = false;
    }
    cv.notify_all();
  }
  
  // Signal the worker threads to terminate
  {
    std::lock_guard<std::mutex> lock(mtx);
    isReady = false;
  }
  cv.notify_all();
  
  // Wait for the worker threads to terminate
  for (unsigned int i = 0; i < n_threads; i++) {
    mythread[i].join();
  }
  
  return 0;
}